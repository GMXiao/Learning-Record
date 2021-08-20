# c++ 多线程学习
## unique_lock 和 lock_guard


## wait 方法
当前线程（持有互斥锁）将被阻塞，直到收到其他线程notify。  
在阻塞线程的那一刻，函数自动调用lck.unlock()，允许其他被锁定的线程可持锁继续运行。

一旦通知（明确地，由某个其他线程），该函数解除阻塞并调用 lck.lock()。  

## yield 和 sleep_for
1. std::this_thread::yield(): 线程调用该方法时，主动让出CPU，并且不参与CPU的本次调度，从而让其他线程有机会运行。在后续的调度周期里再参与CPU调度。

2. std::sleep_for()：线程调用该方法时，同样会让出CPU，并且休眠一段时间，从而让其他线程有机会运行。等到休眠结束时，才参与CPU调度。

区别： yield()方法让出CPU的时间是不确定的，并且以CPU调度时间片为单位。而sleep_for()让出CPU的时间是固定的。

## 生产者、消费者模型
    queue<int> q;
    int MAXSIZE;
    mutex m;    //互斥量
    condition_variable notempty; //条件变量，表明缓存是否为空
    condition_variable notfull;  //条件变量，表明缓存是否为空

    void producer(int val){
        unique_lock<mutex> plock(m); 
        while(q.size()>=MAXSIZE){
            notfull.wait(plock); //阻塞当前线程，等待信号，并释放锁
        }
        q.push(val);
        notempty.notify_one();
    }
    void consumer(){
        unique_lock<mutex> slock(m);
        while(q.size()==0){
            notempty.wait(slock);
        }
        cout<<q.front()<<endl;
        q.pop();
        notfull.notify_one();
    }
