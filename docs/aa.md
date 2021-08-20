    public class Foo
    {
        public void f1() {
        synchronized(this) {
            // ...
        }
        }
    
        public void f2() {
            synchronized(Foo.class) {
            // ...
            }
        }
    
        public synchronized void f3() {
            // ...
        }
    }
[可见资料](https://www.jb51.net/article/74566.htm)

    
放在范围操作符(public等)之后,返回类型声明(void等)之前.这时,线程获得的是成员锁,即一次只能有一个线程进入该方法。