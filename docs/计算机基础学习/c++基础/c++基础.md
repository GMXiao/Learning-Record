## c++面试资料：
[20道必须掌握的c++面试题](https://www.w3cschool.cn/cpp/cpp-a9no2ppi.html)


## new/delete 和 malloc/free 的区别与联系
### 区别
1、 malloc/free 是函数（标准库函数 void *malloc(long NumBytes)，void free(void *FirstByte)），new/delete是运算符。

2、 malloc分配内存要进行字节计算和类型转换
 
    
    用malloc 申请一块长度为length 的整数类型的内存，程序如下：
    int *p = (int *) malloc(sizeof(int) * length);
    们应当把注意力集中在两个要素上：
    1)、malloc 返回值的类型是void *，所以在调用malloc 时要显式地进行类型转换，将void * 转换成所需要的指针类型。
    2)、 malloc 函数本身并不识别要申请的内存是什么类型，它只关心内存的总字节数。

使用new更加简便，不需要进行类型转换和字节计算（这是因为new 内置了sizeof、类型转换和类型安全检查功能）：

    int *p1 = (int *)malloc(sizeof(int) * length);
    int *p2 = new int[length];

3、 对于非基本数据类型的对象而言，对象在创建的同时要自动执行构造函数，对象在消亡之前要自动执行析构函数。由于malloc/free是库函数而不是运算符，不能把执行构造函数和析构函数的任务加于malloc/free。因此C++语言需要一个能完成动态内存分配和初始化工作的运算符new，以及一个能完成清理与释放内存工作的运算符delete。
  
4、 new/delete是保留字，不需要头文件支持；malloc/free需要头文件库函数支持。

### 联系
既然new/delete的功能完全覆盖了malloc/free，为什么C++还保留malloc/free呢？因为C++程序经常要调用C函数，而C程序只能用malloc/free管理动态内存。如果用free释放“new创建的动态对象”，那么该对象因无法执行析构函数而可能导致程序出错。如果用delete释放“malloc申请的动态内存”，理论上讲程序不会出错，但是该程序的可读性很差。所以new/delete，malloc/free必须配对使用。

## new/delete用法
一维数组：

    int m;
    cin>>m;
    int *a = new int[m];

    delete[] a;
内存使用情况：
    ![动态分配一维数组](../pictures/newdelete一维数组.png)

二维数组：

    int m,n;
    cin>>m>>n;
    int **b = new int* [m];
    for(int i=0;i<m;i++)b[i] = new int[n];

    for(int i=0;i<m;i++)
        delete[] b[i]; 
    delete[] b;
内存使用情况：
    ![动态分配二维数组](../pictures/newdelete二维数组.png)

## 声明，定义和初始化
变量声明：用于向程序表明变量的类型和名字，但声明不一定引起内存的分配。定义也是声明：当定义变量时我们声明了它的类型和名字。

变量定义：用于为变量分配存储空间，用于存放对应类型的数据，变量名就是对相应的内存单元的命名，还可为变量指定初始值。程序中，变量有且仅有一个定义。

初始化：初始化是给对象赋予初值的过程，初始化由构造函数执行。

    [注意] 
    变量在使用前就要被定义或者声明。 
    定义也是声明，extern声明不是定义
    在一个程序中，变量只能定义一次，却可以声明多次。 
    定义分配存储空间，而声明不会。
    函数的声明和定义区别比较简单，带有{ }的就是定义，否则就是声明。

声明，定义，初始化是变量的三种状态。可以使用  extern告诉编译器变量在其他地方定义了。带有初始化式的声明也是定义，即使前面加了extern。

    extern int i;       //声明，不是定义
    int i;              //声明，也是定义，未初始化
    extern double pi=3.141592654;  //定义，初始化


程序模块化设计风格：

    不要在.h文件中定义变量。
    尽量使用static关键字把变量定义限制于该源文件作用域，除非变量被设计成全局的。
    可以在头文件中声明一个变量，在用的时候包含这个头文件就声明了这个变量。

    模块即是一个.c文件和一个.h文件的结合，头文件(.h)中是对于该模块接口的声明；
 
     某模块提供给其它模块调用的外部函数及数据需在.h中文件中冠以extern关键字声明；
    
    模块内的函数和全局变量需在.c文件开头冠以static关键字声明；
 
## C++11新特性
https://blog.csdn.net/jiange_zh/article/details/79356417

1、nullptr出现代替NULL

2、类型推导：引入auto和decltype这两个关键字实现了类型推导】

使用 auto 进行类型推导的一个最为常见而且显著的例子就是迭代器。

以前书写迭代器：

    for（vector <int> :: const_iterator itr = vec.cbegin（）; itr！= vec.cend（）; ++ itr）
使用auto之后：

    // 由于 cbegin() 将返回 vector<int>::const_iterator 
    // 所以 itr 也应该是 vector<int>::const_iterator 类型
    for(auto itr = vec.cbegin(); itr != vec.cend(); ++itr);

3、引入了基于范围的迭代写法，可写出更加简单循环语句，原来的遍历：

    std::vector<int> arr(5, 100);
    for(std::vector<int>::iterator i = arr.begin(); i != arr.end(); ++i) {
        std::cout << *i << std::endl;
    }
现在：

    // & 启用了引用
    for(auto &i : arr) {    
        std::cout << i << std::endl;
    }

4、使用初始化列表来初始化任意对象

5、构造函数

    委托构造
    继承构造

6、Lambda表达式

https://blog.csdn.net/jiange_zh/article/details/79356417

本质上是一个函数，但是没有名字，具体形式如下：

    [外部变量访问方式说明符] (参数表) -> 返回值类型
    {
    语句块
    }
其中，“外部变量访问方式说明符”可以是=或&，表示{}中用到的但定义在{}外面的变量在{}中是否允许被改变。=表示不允许，&表示允许。当然，在{}中也可以不使用定义在外面的变量。“-> 返回值类型”可以省略。下面是一个合法的lambda表达式：

    [=] (int x, int y) -> bool {return x%10 < y%10; }
下面的程序段使用了上面的 Lambda 表达式：

    int a[4] = {11, 2, 33, 4};
    sort(a, a+4, [=](int x, int y) -> bool { return x%10 < y%10; } );
    for_each(a, a+4, [=](int x) { cout << x << " ";} );

关于捕获列表 []，
1) []不捕获任何变量。
2) [&]捕获外部作用域中所有变量，并作为引用在函数体中使用（按引用捕获）。
3) [=]捕获外部作用域中所有变量，并作为副本在函数体中使用(按值捕获)。
4) [this]捕获当前类中的this指针，让lambda表达式拥有和当前类成员函数同样的访问权限。
5) [=,&foo]按值捕获外部作用域中所有变量，并按引用捕获foo变量。
6) [bar]按值捕获bar变量，同时不捕获其他变量。

可见下例：

    int a = 0;
    auto f = [=] { return a; };
    a+=1;
    cout << f() << endl;       //输出0

    int a = 0;
    auto f = [&a] { return a; };
    a+=1;
    cout << f() <<endl;       //输出1

## 指针和引用

### 引用当参数和返回值
当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边，来修改被引用的变量。(使用引用来修改变量值)

    double vals[] = {10.1, 12.6, 33.1};
 
    double& setValues( int i )
    {
        return vals[i];   // 返回第 i 个元素的引用
    }

    int main(){
        cout << vals[0] << endl;
        cout << vals[2] << endl;
        setValues(0) = 11;//通过引用修改vals[]数组
        setValues(2) = 13;
        cout << vals[0] << endl;
        cout << vals[2] << endl;
        return 0;
    }

    main的执行结果为：
    10.1
    33.1
    11
    13

使用引用需要注意作用域，比如当函数返回一个局部变量的引用是不合法的，但返回一个静态变量的引用是合法的。

    int& func() {
    int q;
    //! return q; // 在编译时发生错误
    static int x;
    return x;     // 安全，x 在函数作用域外依然是有效的
    }  

## 宏定义

https://blog.csdn.net/qq_41865229/article/details/86746707

## 语法基础
这里记录一些基础的c++语法
### vector
遍历vector vec

方法1：迭代器输出

    for (vector<int>::const_iterator iter = vec.cbegin();iter != vec.cend(); iter++) {
        cout << (*iter) << endl;
    }

方法2：使用c++新增加的语义auto

      for (auto iter = vec.cbegin(); iter != vec.cend(); iter++) {
    cout << (*iter) << endl;

方法3：使用 .size()方法

    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i]<<endl;
	}


* 需要注意的是，sizeof(vec)只取决于vector里面存放的数据类型，与元素个数无关。
  
### 类的构造函数
当使用“引用”作为初始化的成员变量时，需要使用“初始化列表”来初始化。

    //假设有一个类 C，具有多个字段 X、Y、Z 等需要进行初始化
    C::C( double a, double b, double c): X(a), Y(b), Z(c)
    {
    ....
    }

### *和&的使用
理解指针 *：当执行 "int* b" 时创建了一个指针类型的变量 b。而对b赋的值需要是地址类型而不能是其他类型，使用“&”可以对变量进行取地址的操作。执行"int a=3; b=&a" 后指针变量b指向了变量a的地址，即b存储的内容是a的地址。"*b" 为变量a的内容，对*b修改会改变a的值。

理解引用 &："int a=3; int &b=a;" 上述语句相当于给变量a起了一个别名b。需要注意的是，a和b实际上都是a，两者地址相同。

函数传入指针参数：函数的形参为指针变量时，会改变调用时传入的值。

    void fun(int *a, int *b)
    {
        int c = 0;
        c = *a;
        *a = *b;
        *b = c;
    }
    int main()
    {
        int a = 1;
        int b = 2;
        cout << a << "," << b << endl;
        fun(&a, &b);//a,b交换
        cout << a << "," << b << endl;
        system("pause");
        return 0;
    }
    最终输出：
    1,2
    2,1
    而如果形参传入普通参数，是不会改变原来的值的。
    原因就在于采用指针参数时，实际的变量就是在a,b,c三者的内存中直接操作的；
    而普通参数则使用了额外的内存，形参操作之后并没有影响原来的内存中的值。

函数传入引用：函数的参数为 引用 时，会改变原本的值。

    void fun(int &a, int &b)
    {
        int c = 0;
        c = a;
        a = b;
        b = c;
    }
    int main()
    {
        int a = 1;
        int b = 2;
        cout << a << "," << b << endl;
        fun(a, b);//a,b交换
        cout << a << "," << b << endl;
        system("pause");
        return 0;
    }
    最终输出：
    1,2
    2,1
    原因是main函数中向fun函数传入了a和b的引用，而引用和原变量的地址是相同的，
    相当于还是在原变量的地址上操作，所以实现了swap。


### #ifdef和#ifndef的使用
一般情况下，源程序中所有的行都参加编译。但是有时希望对其中一部分内容只在满足一定条件才进行编译，也就是对一部分内容指定编译的条件，这就是“条件编译”。有时，希望当满足某条件时对一组语句进行编译，而当条件不满足时则编译另一组语句。 条件编译常见的形式为：

    #ifdef 标识符 
    程序段1 
    #else 
    程序段2 
    #endif
    它的作用是：当标识符已经被定义过(一般是用#define命令定义)，则对程序段1进行编译，否则编译程序段2。 

在头文件中使用条件编译很有必要，可以防止出现重复定义。



### 回调函数
https://www.cnblogs.com/smartlife/articles/12519130.html

程序通过参数把回调函数的函数指针传递给了其它函数，在那个函数里面调用这个函数指针就相当于调用这个函数，这样的过程就叫回调。

应用在具体的问题中，可以理解为库开发者和用户之间约定的一种函数调用规则。用户编程时需要使用库开发者定义的某个函数b()，但是函数b()无法自己实现全部功能，它需要反过头来调用用户的某个函数a()。为了达成一定的规则，库开发者会约定接口规范，即回调函数a()的函数原型，原型最好遵循下面的形式：

    typedef void (*SCT_XXX)(LPVOID lp, const CBParamStruct& cbNode);
SCT_XXX是回调函数名称，lp是回调上下文，CBParamStruct是回调参数。
库开发者提供了回调函数的原型，并且需要给出注册回调函数，实际使用中注册回调函数就是给用户调用的函数，它的参数会有回调函数原型的函数指针。注册回调函数的形式遵循：
    
    void RCF_XXX(SCT_XXX pfn, LPVOID lp); 
RCF_XXX是注册函数名，pfn是回调函数名称（函数指针）。

场景也可能为应用程序中多模块之间的协同工作，假如现在一个系统中有两个模块，通讯模块和数据处理模块需要进行协作，通讯模块负责接收数据并交给数据处理模块，而数据处理模块负责对收到的数据进行处理，那么通讯模块如何实时将。

通讯模块：

    //定义回调函数原型
    typedef void (*DataReceiveCBFunc)(ReceiveParam & recvParam);

    //注册回调函数，给数据接收模块调用，开始接收
    static BOOL StartReceive(DataReceiveCBFunc pfnData, LPVOID lpContext,……);

    //接收数据的现场，一收到数据就通知回调
    static UINT TH_Receive(LPVOID lp);



数据处理模块：

    //开始接收数据的函数，开启监听线程，调用上面的StartReceive函数
    int StartReceiveInfo(int nListenPort, std::string strLocalIP);

    //数据接收回调函数，根据原型编写，被TH_Receive通知回调之后执行内部的代码
    static void RecvInfoCallback(ReceiveParam &recvParam);  

### 结构体使用构造函数

    //Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {} //使用初始化列表的方式来设置值
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

    //初始化
    ListNode ln1 = ListNode();//方式1
    ListNode ln2 = ListNode(0);//方式2
    ListNode ln3 = ListNode(0,&ln2);//方式3

### C++标准模板库 STL
http://c.biancheng.net/cplus/80/

C++ 的一个特点在于通过模板的概念实现了对泛型程序设计的支持。C++标准模板库STL是泛型编程的成功例子。



## const的理解
1、一个经典的问题，const修饰指针变量，问以下两种声明的区别：
1)  const char * p (等价于 char const* p) = "一个char型变量"
2)  char * const p = "一个地址"

这里的 const 关键字是用于修饰常量，书上说 const 将修饰离它最近的对象，所以，以上两种声明的意思分别应该是：
1)  p 是一个指向常量字符的指针，不变的是 char 的值，即该字符的值在定义时初始化后就不能再改变。
2)  p 是一个指向字符的常量指针，不变的是 p 的值，即该指针不能再指向别的。

Bjarne 在他的《The C++ Programming Language》里面给出过一个助记的方法——“以 * 分界，把一个声明从右向左读”。*读作

const char *const p = "一个地址" ，这种形式下p与p指向的地址中的值都不能修改。

2、const成员变量
const 成员变量的用法和普通 const 变量的用法相似，只需要在声明时加上 const 关键字。初始化 const 成员变量只有一种方法，就是通过构造函数的初始化列表。

3、const成员函数
const修饰函数承诺在本函数内部不会修改类内的数据成员，不会调用其它非 const 成员函数。

4、const在函数不同位置的用法：

1)函数开头的 const 用来修饰函数的返回值：

    1句话：修饰的是返回值，表示返回的指针所指向的量是常量。

    详见下面代码：
    class TestClass {//声明
    public:
        const char* getPContent();
    private:
        char *pContent;
    };
    const char* TestClass::getPContent(){//函数名前加const
        return pContent;
    } 

    int main(){
        TestClass *tc =new TestClass;
        char * content = tc->getPContent();      //A
        return 0;
    }  

    A处标记的语句在编译时会出错，原因在于被const在函数名开头修饰的函数返回值不能被更改，而语句A的指针变量content是可以被修改的，所以语句A应该改为： 
    const char * content = tc->getPContent(); 

2）函数头部的结尾加上 const 关键字

    1句话：该函数为只读函数，不允许修改其中的数据成员的值。

    const 成员函数可以使用类中的所有成员变量，但是不能修改它们的值，这种措施主要还是为了保护数据而设置的。const 成员函数也称为常成员函数。
    我们通常将 get 函数设置为常成员函数。读取成员变量的函数的名字通常以get开头，后跟成员变量的名字，所以通常将它们称为 get 函数。看下面例子：

    class Student{
    public:
        Student(char *name, int age, float score);
        //声明常成员函数
        char *getname() const;
        int getage() const;
        float getscore() const;
    private:
        char *m_name;
        int m_age;
        float m_score;
    };

## 数组作为成员变量
1、固定数组长度，需要在类定义中明确其长度，并在对象初始化时挨个赋值；

2、也可以使用动态数组传指针的方式：类中定义一个指针的成员变量，对象初始化时后动态数组赋值给指针成员变量。通过这种方式就可以正常访问该数组了，但是由于传入了指针，所以不知道数组长度，需要同时有一个成员变量来说明数组的长度（如果成员变量是私有的，可能还需要使用构造函数来初始化值）。例子见下面代码：

    class A{
    public:
        int *nums;
        int length;
        void handleNums(){······};
    }
    int main(){
        int *b = new int[7];//定义一个动态数组
        ······              //为动态数组赋值
        A a;
        a.nums = b;
        a.length = 7;
        a.handleNums();
    }

    //私有的成员变量，使用构造函数
    class A{
    public:
    	A(int *i, int j) { nums = i; length = j; }//构造函数
	    //A(int *i, int j):nums(i), length(j) {}; //使用初始化列表构造方法
        void handleNums(){······};
    private:
        int *nums;
        int length;
    }
    int main(){
        int *b = new int[7];//定义一个动态数组
        ······              //为动态数组赋值
        A a(b,7);
        a.handleNums();
    }

## 数据模型与变量大小
c语言中有基本类型：char,short,int,long,float,double.每种类型在不同的数据模型下所占用的内存空间不同。

数据模型包括：LP32,ILP32,LP64,LLP64,ILP64.

![](../../pictures/数据模型和内存大小.png)

32位环境的数据模型为ILP32；64位环境使用LP64；现有的unix64位系统使用LP64

## 数据结构——树
详细的教程可以看：https://www.zhihu.com/question/30527705/answer/1663740519

二叉树：

二叉平衡树：插入新数据时需要进行层数平衡操作（左旋或右旋），比较消耗时间。

红黑树：是一种折中方案，不需要像二叉平衡树那样频繁地进行平衡（最多平衡三次），同时也保证了时间复杂度大概在O(log n)。


## 大根堆 小根堆
大根堆和小根堆原理相同。
堆树的定义如下：

（1）堆树是一颗完全二叉树；

（2）堆树中某个节点的值总是不大于或不小于其孩子节点的值；

（3）堆树中每个节点的子树都是堆树。

堆数调整方法（以大根堆为例）：

首先需要找到最后一个节点的父节点，从这个节点开始构造最大堆；直到该节点前面所有分支节点都处理完毕，这样最大堆就构造完毕了。

假设树的节点个数为n，以1为下标开始编号，直到n结束。对于节点i，其父节点为i/2；左孩子节点为 i* 2，右孩子节点为 i* 2+1。最后一个节点的下标为n，其父节点的下标为n/2。


## this 指针
http://c.biancheng.net/view/170.html

## i++ 和 ++i的区别
https://blog.csdn.net/u014465639/article/details/72812187

    //i++实现代码为：                                    
    int operator++(int)                                  
    {
        int temp = *this;                                     
        ++*this;                                             
        return temp;                                    
    }
    //返回一个int型的对象本身
    //构造了一个局部变量temp，浪费了空间和时间

    // ++i实现代码为：
    int& operator++()
    {
        *this += 1;
        return *this;
    }
    //返回一个int型的对象引用
    //直接对对象进行操作

## 内联函数
函数调用在执行时，首先要在栈中为形参和局部变量分配存储空间，然后还要将实参的值复制给形参，接下来还要将函数的返回地址（该地址指明了函数执行结束后，程序应该回到哪里继续执行）放入栈中，最后才跳转到函数内部执行。这个过程是要耗费时间的。

另外，函数执行 return 语句返回时，需要从栈中回收形参和局部变量占用的存储空间，然后从栈中取出返回地址，再跳转到该地址继续执行，这个过程也要耗费时间。

使用 inline 关键字的函数称为“内联函数”。内联函数和普通函数的区别在于：当编译器处理调用内联函数的语句时，不会将该语句编译成函数调用的指令，而是直接将整个函数体的代码插人调用语句处，就像整个函数体在调用处被重写了一遍一样。


## C++ 使用VS创建和使用动态库ddl
1.静态库：函数和数据被编译进一个二进制文件（扩展名通常为.lib）,在使用静态库的情况下，在编译链接文件时，链接器从静态库中复制这些函数和数据，并把它们和应用程序的其他模块组合起来创建最终的可执行文件（.exe）。当发布产品时，只需要发布这个可执行文件，并不需要发布被使用的静态库。

2.动态库：在使用动态库时，往往提供两个文件：一个引入库（.lib，非必须）和一个.dll文件。这里的引入库和静态库文件虽然扩展名都是.lib，但是有着本质上的区别，对于一个动态链接库来说，其引入库文件包含该动态库导出的函数和变量的符号名，而.dll文件包含该动态库实际的函数和数据。

### 创建


### 使用


### 查看
在vs自带的命令提示符中，使用 dumpbin 命令来查看dll提供的方法，以及查看exe文件使用了那些动态库文件。用法如下：

    查看导出：dumpbin -exports 文件名称

    查看导入：dumpbin -imports 文件名称

## cmake学习历程
### gcc、g++、make、cmake区别
https://blog.csdn.net/hblhly/article/details/80740493

目标：让eigen3可以在windows环境下被使用，使用cmake进行编译，在vs或者vs code的编辑器中进行编辑。  
现状：目前在环境 linux+cmake 中编译及运行是没有问题的。  
问题：在 windows+vscode+cmake 环境中存在问题  
解决方案：

    1、vscode只用来编辑代码；修改CMakeLists.txt中 “include_directories("C:/Program Files (x86)/Eigen3/include")”；
    2、使用cmake来进行Makefile的生成，指令为：cmake [options] \<path-to-source> （具体为：“cmake -G "MinGW Makefiles" ..” ，-G指定编译器，这里是mingw32，".."代表上层目录，当前我们在build目录中）；
    3、然后执行mingw32-make（即make指令，由于cmake使用mingw32，所以我们不能将mingw32改名为make）执行Makefile中的指令生成我们想要的东西。



## 疑问：
