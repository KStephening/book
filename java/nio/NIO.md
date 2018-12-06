# NIO

## 1. NIO和IO的区别

- IO是以字节进行读取的
- NIO是以块进行读取的

## 2. 通道和缓冲区

### 2.1 缓冲区

- Buffer 是一个对象， 它包含一些要写入或者刚读出的数据。
- 缓冲区实质上是一个数组。通常它是一个字节数组，但是也可以使用其他种类的数组。但是一个缓冲区不 仅仅 是一个数组。缓冲区提供了对数据的结构化访问，而且还可以跟踪系统的读/写进程。

#### 2.1.1 缓冲区类型

- ByteBuffer.最常用的
- CharBuffer
- ShortBuffer
- IntBuffer
- LongBuffer
- FloatBuffer
- DoubleBuffer

#### 2.1.2 ByteBuffer方法

- allocate(int bytes) 分配一个bytes字节数的缓冲区 
- clear() 方法重设缓冲区，使它可以接受读入的数据
- flip()  当需要读数据时，通过flip()方法把buffer从写模式调整为读模式；在读模式下，可以读取所有已经写入的数据。
- get()

#### 2.1.3 容量capacity,位置position,上限limit

![](screenshot/2018-12-06-18-59-31.png)

1. 容量capacity
就是最多只能写入容量值得字节，整形等数据。一旦buffer写满了就需要清空已读数据以便下次继续写入新的数据。

2. 位置（Position）
- 当写入数据到Buffer的时候需要中一个确定的位置开始
    - 默认初始化时这个位置position为0
    - 一旦写入了数据比如一个字节，整形数据，那么position的值就会指向数据之后的一个单元
    - position最大可以到capacity-1.

- 当从Buffer读取数据时，也需要从一个确定的位置开始。
    - buffer从写入模式变为读取模式时，position会归零
    - 每次读取后，position向后移动。

3. 上限（Limit）
- 写模式，limit的含义是我们所能写入的最大数据量。它等同于buffer的容量。

- 读模式，limit则代表我们所能读取的最大数据量，他的值等同于写模式下position的位置。

数据读取的上限时buffer中已有的数据，也就是limit的位置（原position所指的位置）。

### 2.2 通道

1. 简介
    - Channel是一个对象，可以通过它读取和写入数据。
    - 拿 NIO 与原来的 I/O 做个比较，通道就像是流。
    - 所有数据都通过 Buffer对象来处理。
    - 读取/写入:-->通道-->缓冲区
    - 通道与流的不同之处在于通道是双向的。可以用于读、写或者同时用于读写。
2. 方法
    - int read(ByteBuffer buf) 

