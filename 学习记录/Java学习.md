# Java 知识总结

## 集合框架
集合：用于存储数据的容器

### 集合和数组的区别
    1、数组是固定长度的；集合可变长度的。

    2、数组可以存储基本数据类型，也可以存储引用数据类型；集合只能存储引用数据类型。

    3、数组存储的元素必须是同一个数据类型；集合存储的对象可以是不同数据类型。

### 集合常用接口
#### Iterator 接口
在Iterator接口中定义了三个方法：
|返回类型| 方法与描述 |
| :------:| :------: |
|boolean|hasNext()如果还有可迭代的元素就返回true|
|E|next()返回迭代的下一个元素|
|null|remmove()删除collection最后一个元素|
#### ListIterator接口
    更加强大的迭代器， 它继承于Iterator接口，只能用于各种List类型的访问。可以通过调用listIterator()方法产生一个指向List开始处的ListIterator， 还可以调用listIterator(n)方法创建一个一开始就指向列表索引为n的元素处的ListIterator。

    除此之外，ListIterator还可以向前和向后进行遍历。
#### Collection接口
Collection接口主要包含List和Set两大接口。

    List主要有ArrayList接口，LinkedList接口和[Vector接口](https://docs.oracle.com/javase/8/docs/api/java/util/Vector.html)。ArrayList本质上是动态数组，LinkedList是双向链表，Vector也是动态数组，但是具有线程安全的特性。

    Set主要有HashSet、TreeSet、LinkedHashSet接口。HashSet底层实现为HashMap，TreeSet底层实现为红黑树、LinkedHashSet底层实现为LinkedHashMap。
#### Map接口
HashMap、HashTable、TreeMap的区别：

    1、TreeMap：基于红黑树实现。

    2、HashMap：基于哈希表实现。

    3、HashTable：和 HashMap 类似，但它是线程安全的，这意味着同一时刻多个线程可以同时写入 HashTable 并且不会导致数据不一致。它是遗留类，不应该去使用它。现在可以使用 ConcurrentHashMap 来支持线程安全，并且 ConcurrentHashMap 的效率会更高，因为 ConcurrentHashMap 引入了分段锁。

    4、LinkedHashMap：使用双向链表来维护元素的顺序，顺序为插入顺序或者最近最少使用（LRU）顺序。