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
所有java程序的运行都要依靠具体的java虚拟机实例，java虚拟机是一个抽象的体系结构，具有平台无关性和语言无关性。
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

## Java native
native是与C++联合开发的时候用的！

使用native关键字说明这个方法是原生函数，也就是这个方法是用C/C++语言实现的，并且被编译成了DLL，由java去调用。

![Java Native方法实现流程图](/pictures/java_native.png)

## 计算机网络

### TCP三次握手

    原因：发送SYN包时附带了起始序号，A给B发SYN，B给A发SYN+ACK，各自约定起始序号，第三个包是A发给B的ACK，表示收到了B发送的起始序号。

### TCP四次分手

    原因：TCP是全双工通信，需要两边全部发完且结束。

### TCP/UDP)攻击与防御原理


### TCP粘包/拆包


## 数据库

### 为什么用B+树来索引
数据库可能很大，一般不会全部放在内存中，使用B+树可以减少内存与磁盘的I/O，B+树单个节点可以存放多个索引，磁盘I/O一次可以得到很多数据，提高了数据查找时的命中率。

### 脏读、不可重复读、幻读
    数据库隔离等级：Read uncommitted（可以读未提交的数据）=》导致 脏读；
    脏读：A事务在B事务未提交之前读取其中数据，但B之后发生了回滚，则A读取了脏数据。

    数据库隔离等级：Read committed（读提交之后的数据）=》解决了脏读，导致不可重复读；

    不可重复读：指同一个事务在整个事务过程中对同一笔数据进行读取，每次读取结果都不同。
    不可重复读的重点是修改:同样的条件, 你读取过的数据, 再次读取出来发现值不一样了

    数据库隔离等级：Repeatable read（在开始读取数据（事务开启）时，不再允许修改操作。）=》解决了不可重复读，导致幻读；

    幻读：幻读是指同样一笔查询在整个事务过程中多次执行后，查询所得的结果集是不一样的。
    幻读的重点在于新增或者删除 (数据条数变化)：同样的条件, 第1次和第2次读出来的记录数不一样
    数据库隔离等级：Serializable（最高的事务隔离级别，在该级别下，事务串行化顺序执行），解决了幻读。



## Redis
REmote DIctionary Server(Redis) 是一个由 Salvatore Sanfilippo 写的 key-value 存储系统，是跨平台的非关系型数据库。

一般地，Redis可以用来作为MySQL的缓存层。为什么MySQL最好有缓存层呢？想象一下这样的场景：在一个多人在线的游戏里，排行榜、好友关系、队列等直接关系数据的情景下，如果直接和MySQL正面交手，大量的数据请求可能会让MySQL疲惫不堪，甚至过量的请求将会击穿数据库，导致整个数据服务中断，数据库性能的瓶颈将掣肘业务的开发；那么如果通过Redis来做数据缓存，将大大减小查询数据的压力。在这种架子里，当我们在业务层有数据查询需求时，先到Redis缓存中查询，如果查不到，再到MySQL数据库中查询，同时将查到的数据更新到Redis里；当我们在业务层有修改插入数据需求时，直接向MySQL发起请求，同时更新Redis缓存。

Redis 官网：https://redis.io/

源码地址：https://github.com/redis/redis

Redis 在线测试：http://try.redis.io/

Redis 命令参考：http://doc.redisfans.com/




## abstract class和interface 区别
接口是对行为的抽象，抽象类是对根源的抽象。接口说的是有没有的问题，抽象类说的是是不是的问题。一个精彩的例子可见：接口和抽象类有什么区别？ - BWH.Steven的回答 - 知乎
https://www.zhihu.com/question/20149818/answer/704355929

在java中不能多继承，所以对于一个类只能继承一个抽象类。而接口提供了多继承的特性，一个类可以实现多个接口。

|| abstract class | interface |
| :------:| :------: |:------: |
|实例化|不能|不能|
|类的角度|在Java语言中体现了一种继承关系，即父类和派生类在概念本质上应该是相同的|不要求interface的实现者和interface定义在概念本质上是一致的，仅仅是实现了interface定义的契约而已|
|数据成员|可有自己的|必须是static final，不能修改的静态数据|
|方法|可以是私有的，非abstract方法必须实现|不能是私有的，默认是public和abstract的|
|变量|可有私有的，默认是friendly 型，其值可以在子类中重新定义，也可以重新赋值|不可有私有的，默认是public static final 型，且必须给其初值，实现类中不能重新定义，不能改变其值。|
|设计理念|表示的是“is-a”关系|表示的是“like-a”关系|
|子类实现|用extends|用implements|

## java中的锁

https://blog.csdn.net/weixin_35833012/article/details/88083553


## 线程池
Java中提供了创建线程池的类：Executor。我们一般使用的是它的子类：ThreadPoolExecutor。而我们通常使用的四种线程池都是返回了ThreadPoolExecutor，只不过其中设置的参数不同。

重点看下ThreadPoolExecutor，

    ThreadPoolExecutor(int corePoolSize, int maximumPoolSize, long keepAliveTime, TimeUnit unit, BlockingQueue<Runnable> workQueue, RejectedExecutionHandler handler)

    核心参数的作用：
    corePoolSize 为线程池的基本大小。
    maximumPoolSize 为线程池最大线程大小。
    keepAliveTime 和 unit 则是线程空闲后的存活时间。
    workQueue 用于存放任务的阻塞队列。
    handler 当队列和最大线程池都满了之后的饱和策略。


## HTTP URL GET POST

### HTTP请求消息

客户端发送一个HTTP请求到服务器的请求消息包括以下格式：

请求行（request line）、请求头部（header）、空行和请求数据四个部分组成。

用一个例子来说明GET 使用，

    GET /562f25980001b1b106000338.jpg HTTP/1.1
    Host    img.mukewang.com
    User-Agent    Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/51.0.2704.106 Safari/537.36 Accept image/webp,image/*,*/*;q=0.8 Referer http://www.imooc.com/ Accept-Encoding gzip, deflate, sdch Accept-Language zh-CN,zh;q=0.8

第一部分：请求行，用来说明请求类型,要访问的资源以及所使用的HTTP版本。

第二部分：请求头部，紧接着请求行（即第一行）之后的部分，用来说明服务器要使用的附加信息。

从第二行起为请求头部，HOST将指出请求的目的地。User-Agent,服务器端和客户端脚本都能访问它,它是浏览器类型检测逻辑的重要基础.该信息由你的浏览器来定义,并且在每个请求中自动发送等等。

第三部分：空行，请求头部后面的空行是必须的，即使第四部分的请求数据为空，也必须有空行。

第四部分：请求数据也叫主体，可以添加任意的其他数据。这个例子的请求数据为空。

用一个例子来说明POST 使用，

    POST / HTTP1.1
    Host:www.wrox.com
    User-Agent:Mozilla/4.0 (compatible; MSIE 6.0; Windows NT 5.1; SV1; .NET CLR 2.0.50727; .NET CLR 3.0.04506.648; .NET CLR 3.5.21022) Content-Type:application/x-www-form-urlencoded Content-Length:40 Connection: Keep-Alive name=Professional%20Ajax&publisher=Wiley

第一部分：请求行，第一行明了是post请求，以及http1.1版本。
第二部分：请求头部，第二行至第六行。
第三部分：空行，第七行的空行。
第四部分：请求数据，第八行。本例无请求数据

### HTTP相应消息
服  务器接收并处理客户端发过来的请求后会返回一个HTTP的响应消息。

HTTP响应也由四个部分组成，分别是：状态行、消息报头、空行和响应正文。

例子：

    HTTP/1.1 200 OK
    Date: Fri, 22 May 2009 06:07:21 GMT
    Content-Type: text/html; charset=UTF-8
    
    <html>
        <head></head> <body> <!--body goes here--> </body> </html>

第一部分：状态行，由HTTP协议版本号， 状态码， 状态消息 三部分组成。
第一行为状态行，（HTTP/1.1）表明HTTP版本为1.1版本，状态码为200，状态消息为（ok）

第二部分：消息报头，用来说明客户端要使用的一些附加信息
第二行和第三行为消息报头，
Date:生成响应的日期和时间；Content-Type:指定了MIME类型的HTML(text/html),编码类型是UTF-8

第三部分：空行，消息报头后面的空行是必须的
第四部分：响应正文，服务器返回给客户端的文本信息。
空行后面的html部分为响应正文。

### HTTP请求方法
    根据HTTP标准，HTTP请求可以使用多种请求方法。
    HTTP1.0定义了三种请求方法： GET, POST 和 HEAD方法。
    HTTP1.1新增了五种请求方法：OPTIONS, PUT, DELETE, TRACE 和 CONNECT 方法。

    GET     请求指定的页面信息，并返回实体主体。
    HEAD     类似于get请求，只不过返回的响应中没有具体的内容，用于获取报头
    POST     向指定资源提交数据进行处理请求（例如提交表单或者上传文件）。数据被包含在请求体中。POST请求可能会导致新的资源的建立和/或已有资源的修改。
    PUT     从客户端向服务器传送的数据取代指定的文档的内容。
    DELETE      请求服务器删除指定的页面。
    CONNECT HTTP/1.1协议中预留给能够将连接改为管道方式的代理服务器。 OPTIONS 允许客户端查看服务器的性能。 TRACE 回显服务器收到的请求，主要用于测试或诊断。

    POST和PUT用法区别：
    新建一条记录的话就用post，
    更新一条记录的话就用put.


### 一次输入网址之后的行为

在浏览器地址栏键入URL，按下回车之后会经历以下流程：

1、浏览器向 DNS 服务器请求解析该 URL 中的域名所对应的 IP 地址;

2、解析出 IP 地址后，根据该 IP 地址和默认端口 80，和服务器建立TCP连接;

3、浏览器发出读取文件(URL 中域名后面部分对应的文件)的HTTP 请求，该请求报文作为 TCP 三次握手的第三个报文的数据发送给服务器;

4、服务器对浏览器请求作出响应，并把对应的 html 文本发送给浏览器;

5、释放 TCP连接;

6、浏览器将该 html 文本并显示内容;