# Android 学习
Android 操作系统是一种多用户 Linux 系统，其中的每个应用都是一个不同的用户；

官方文档 https://developer.android.com/
## 五种数据存取方式
Android 五种数据存储的方式为：

    1、SharedPreferences：以Map形式存放简单的配置参数；
    2、ContentProvider：将应用的私有数据提供给其他应用使用；
    3、文件存储：以IO流形式存放，可分为手机内部和手机外部（sd卡等）存储，可存放较大数据；
    4、SQLite：轻量级、跨平台数据库，将所有数据都是存放在手机上的单一文件内，占用内存小；
    5、网络存储 ：数据存储在服务器上，通过连接网络获取数据；

### SharedPreferences 
具体可见 https://juejin.im/post/6844903594244702221
#### | 获取ShredPreferences对象
要想使用SharedPreferences 来存储数据，首先应该获得SharedPreferences对象，Android中提供了三种方式来获取SharedPreferences对象：
* Context 类中的 getSharedPreferences()方法：
* Activity 类中的 getPreferences()方法；
* PreferenceManager 类中的 getDefaultSharedPreferences()方法。

重点说一下getSharedPreferences()：

    此方法接收两个参数，第一个参数用于指定 SharedPreferences 文件的名称，如果指定的文件不存在则会创建一个，第二个参数用于指定操作模式，主要有以下几种模式可以选择。
    Context.MODE_PRIVATE: 指定该SharedPreferences数据只能被本应用程序读、写（默认模式）；
    Context.MODE_WORLD_READABLE:  指定该SharedPreferences数据能被其他应用程序读，但不能写；
    Context.MODE_WORLD_WRITEABLE:  指定该SharedPreferences数据能被其他应用程序读；
    Context.MODE_APPEND：该模式会检查文件是否存在，存在就往文件追加内容，否则就创建新文件；

#### || 使用ShredPreferences
SharedPreferences对象本身只能获取数据而不支持存储和修改,存储修改是通过SharedPreferences.edit()获取的内部接口Editor对象实现。
使用例：

    pref=getSharedPreferences("txtl",MODE_PRIVATE);
    isLogin=pref.getBoolean("isLogin",false); 
     if(isLogin){
        ···
        jump to another content
     }else{
        ···
        SharedPreferences.Editor editor = pref.edit();
        editor.putBoolean("isLogin",true);
        editor.commit();
     }
上述的例子中，首先创建了一个名为txt1的SharedPreferences文件（实质上是一个Map）；之后对其中“islogin”键查询，如果没有该键就设其值为“false”；最后对islogin判断并进行相应的处理。在else{ }代码块中，创建了一个Editor对象用于修改pref中的键值，并最终使用commit()提交。

## 事件总线机制 和 广播机制
事件总线（EventBus）机制通过记录对象、使用观察者模式来通知对象各种事件。
EventBus没出现之前，那时候的开发者一般是使用Android四大组件中的广播进行组件间的消息传递，那么我们为什么要使用事件总线机制来替代广播呢？主要是因为：
* 广播：耗时、容易被捕获（不安全）。
* 事件总线：更节省资源、更高效，能将信息传递给原生以外的各种对象。

EventBus原理图如下：
![EventBus原理图](/pictures/EventBus-Publish-Subscribe.png "EventBus原理图")

EventBus三要素
* Event：事件，自己定义的类；
* Publisher：事件的发布者，可以在任意线程中发送事件，使用post方法。
* Subscriber：；事件的订阅者，要指定线程模型（默认为POSTING）。


需要注意的是，register是强引用，它会让对象无法得到内存回收，导致内存泄露。所以必须在unregister方法中释放对象所占的内存。

### EventBus 使用实例
1、构造发送消息类

    Public class MessageEvent{
        ···
        public MessageEvent(){
            //构造函数
        }
    }
2、发布消息

    EventBus.getDefault().post(new MessageEvent("name","password"));

3、订阅消息

    @Subscribe(threadMode = ThreadMode.MAIN)
    public void messageEventBus(MessageEvent event){
        //自己决定收到消息之后怎么做
    }

## Handler使用
Handler可以有两种用法：
* 安排消息（Messages）或者可运行对象（Runables）在将来的某个时间点运行；
* 入队一个将执行于不同于当前线程的操作（action）。
### Handler大致使用方法
#### Handler常用的一些方法有：

    post(Runnable), postAtTime(java.lang.Runnable, long), postDelayed(Runnable, Object, long), sendEmptyMessage(int), sendMessage(Message), sendMessageAtTime(Message, long), and sendMessageDelayed(Message, long)
post方法将可运行对象（Runables）入队，在被收到的时候调用；sendMessage方法将消息（Messages）入队，通过Handler的handleMessage(Message)方法来对其进行处理。

#### Handler处理
在发送Messages 或Runables 给Handler之后，可以指定在消息队列准备就绪后立即对其进行处理，也可以指定处理前的具体等待时间，或者具体的处理所用时间。

## Java多线程 （From java.lang.Thread）
![Java线程生命周期](/pictures/java线程生命周期.jpg "Java线程生命周期")
Java 的线程是通过java.lang.Thread类来实现的。VM启动时会有一个由主方法所定义的线程。可以通过创建Thread的实例来创建新的线程。每个线程都是通过某个特定Thread对象所对应的方法run（）来完成其操作的，方法run()称为线程体。通过调用Thread类的start()方法来启动一个线程。
下面是一个线程使用的实例：

    public class Test {  
        public static void main(String[] args) {  
            Runner1 runner1 = new Runner1();  
            Runner2 runner2 = new Runner2();  
    //      Thread(Runnable target) 分配新的 Thread 对象。  
            Thread thread1 = new Thread(runner1);  
            Thread thread2 = new Thread(runner2);  
            thread1.start();  
            thread2.start();   
        }  
    }  
    
    class Runner1 implements Runnable { 
        public void run() {  
            for (int i = 0; i < 100; i++) {  
                System.out.println("进入Runner1运行状态——————————" + i);  
            }  
        }  
    }  
    
    class Runner2 implements Runnable {
        public void run() {  
            for (int i = 0; i < 100; i++) {  
                System.out.println("进入Runner2运行状态==========" + i);  
            }  
        }  
    }

其中主要使用了Thread的两个方法：

1）start方法

start()用来启动一个线程，当调用start方法后，系统才会开启一个新的线程来执行用户定义的子任务，在这个过程中，会为相应的线程分配需要的资源。

2）run方法

run()方法是不需要用户来调用的，当通过start方法启动一个线程之后，当线程获得了CPU执行时间，便进入run方法体去执行具体的任务。注意，继承Thread类必须重写run方法，在run方法中定义具体要执行的任务。

除此之外，线程还有：

3）sleep()方法

sleep让线程进入睡眠状态，交出CPU，让CPU执行其他任务。但需要注意的是，sleep方法不会让线程释放锁。

4）yield

Thread类的方法，类似sleep，但是不能由用户指定暂停多长时间 ，并且yield()方法只能让同优先级的线程有执行的机会。 yield()只是使当前线程重新回到可执行状态，所以执行yield()的线程有可能在进入到可执行状态后马上又被执行。调用yield方法只是一个建议，告诉线程调度器我的工作已经做的差不多了，可以让别的相同优先级的线程使用CPU了，没有任何机制保证采纳。

5）wait

sleep与Wait的区别：sleep是线程方法，wait是object方法；
它们的区别主要考虑两点：1.cpu是否继续执行、2.锁是否释放掉。

sleep ：释放cpu资源，不释放锁资源；

wait：释放cpu资源，也释放锁资源。

6）join

一种特殊的wait，当前运行线程调用另一个线程的join方法，当前线程进入阻塞状态直到另一个线程运行结束或终止。 

