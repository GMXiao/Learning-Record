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




# JVM（Java Virtual Machine）
## JVM 简介
所有加java程序的运行都要依靠具体的java虚拟机实例，java虚拟机是一个抽象的体系结构，具有平台无关性和语言无关性。
* 平台无关性：任何平台只要装载JVM，.class文件（字节码文件）就可以在其上运行。
* 语言无关性：不同语言只要能编译成 .class文件，就可以在JVM上运行。

## JVM 体系介绍
![JVM体系结构](/pictures/jvm体系结构.png "JVM体系结构")
* Class Loader（类加载器）：用于装载.class文件。
* Execution Engine（执行引擎）：用于执行字节码或者本地方法。
* 运行时数据区：方法区、堆、java栈、pc寄存器、本地方法栈。

## 从JRE、JDK和JVM的关系来看JAVA程序执行过程
* JDK（Java Development Kit，Java开发工具包）是用来编译、调试Java程序的开发工具包。包括 JRE 及编译器和调试器等用于程序开发的文件。具体来说有Java工具（javac/java/jdb等）和Java基础的类库（java API ）
* JRE（Java Runtime Environment， Java运行环境）是Java平台，所有的程序都要在JRE下才能够运行。包括JVM和Java核心类库和支持文件。
* JVM(Java Virtual Machine)：Java 虚拟机，它也定义了指令集、寄存器集、结构栈、垃圾收集堆、内存区域，负责解释运行*.class 字节码文件，边解释边运行。Java 虚拟机机制是实现可移植性的核心机制。不同的操作系统有不同的虚拟机，Java虚拟机机制屏蔽了底层运行平台的差别，使 Java 语言在不同平台上运行时不需要重新编译，实现了一次编写，到处运行。

下图表示了JDK、JRE和JVM三者间的关系：

![JDK、JRE和JVM](/pictures/jdkjvmjre关系.png "JDK、JRE和JVM")

使用JDK（调用JAVA API）开发JAVA程序后，通过JDK中的编译程序（javac）将Java程序编译为Java字节码(.class文件)，在JRE上运行这些字节码，JVM会解析并映射到真实操作系统的CPU指令集和OS的系统调用。