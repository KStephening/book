# REDIS-基础
## 1. 五大类型
### 1.1 字符串
### 1.2 列表-list
### 1.3 无序集合-set
list和set的区别
- list可以存储相同的值
- set不可以存储相同的值
- list是有序的
- set是无序的

list和set的相同点
- list和set不是键值对形式,类似于List的两个不同的实现类
### 1.4 哈希-hash
特点
- 不可重复的key
- 无序的
- 键值对 

### 1.5 有序集合-zset
特点
- 有序的
- 不可重复的
- 有序集合的值,也称为分值,必须是浮点数,可以用于取值,也可以用于排序