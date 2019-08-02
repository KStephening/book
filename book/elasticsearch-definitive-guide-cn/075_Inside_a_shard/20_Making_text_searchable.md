#使文本可以被搜索

第一个不得不解决的挑战是如何让文本变得可搜索。在传统的数据库中，一个字段存一个值，但是这对于全文搜索是不足的。想要让文本中的每个单词都可以被搜索，这意味这数据库需要存多个值。

支持一个字段多个值的最佳数据结构是[倒排索引](052_Mapping_Analysis/35_Inverted_index.md)。倒排索引包含了出现在所有文档中唯一的值或词的有序列表，以及每个词所属的文档列表。


     Term  | Doc 1 | Doc 2 | Doc 3 | ...
     ------------------------------------
     brown |   X   |       |  X    | ...
     fox   |   X   |   X   |  X    | ...
     quick |   X   |   X   |       | ...
     the   |   X   |       |  X    | ...


> 注意

>当讨论倒排索引时，我们说的是把文档加入索引。因为之前，一个倒排索引是用来索引整个非结构化的文本文档。ES中的文档是一个结构化的JSON文档。实际上，每一个JSON文档中被索引的字段都有它自己的倒排索引。

倒排索引存储了比包含了一个特定term的文档列表多地多的信息。它可能存储包含每个term的文档数量，一个term出现在指定文档中的频次，每个文档中term的顺序，每个文档的长度，所有文档的平均长度，等等。这些统计信息让Elasticsearch知道哪些term更重要，哪些文档更重要，也就是[相关性](056_Sorting/90_What_is_relevance.md)。

需要意识到，为了实现倒排索引预期的功能，它必须要知道集合中所有的文档。

在全文检索的早些时候，会为整个文档集合建立一个大索引，并且写入磁盘。只有新的索引准备好了，它就会替代旧的索引，最近的修改才可以被检索。    

##不可变性
写入磁盘的倒排索引是不可变的，它有如下好处：
* 不需要锁。如果从来不需要更新一个索引，就不必担心多个程序同时尝试修改。
* 一旦索引被读入文件系统的缓存(译者:在内存)，它就一直在那儿，因为不会改变。只要文件系统缓存有足够的空间，大部分的读会直接访问内存而不是磁盘。这有助于性能提升。
* 在索引的声明周期内，所有的其他缓存都可用。它们不需要在每次数据变化了都重建，因为数据不会变。
* 写入单个大的倒排索引，可以压缩数据，较少磁盘IO和需要缓存索引的内存大小。
 
当然，不可变的索引有它的缺点，首先是它不可变！你不能改变它。如果想要搜索一个新文档，必须重见整个索引。这不仅严重限制了一个索引所能装下的数据，还有一个索引可以被更新的频次。