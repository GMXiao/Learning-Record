## 编译原理
![c程序编译链接过程](/pictures/程序编译链接过程.png)
编译步骤具体如下：
![c程序编译链接](../pictures/程序编译链接过程解释.png)
结合linux系统叙述：

    1.预处理 选项 gcc -E test.c -o test.c (-E: Preprocess only; do not compile, assemble or link. -o <file>: Place the output into <file>)

        预处理完成就停下来，产生结果放在test.i文件中。

    2.编译 选项 gcc -S test.c (-S: Compile only; do not assemble or link.)

        编译完成之后就停下来，结果保存在test.s中。

    3.编译 gcc -C test.c (-c: Compile and assemble, but do not link.)

        汇编完成之后就停下来，结果保存在test.o中。

### 静态链接 和 动态链接
在程序链接的阶段，可以采用静态方式或者动态方式。静态链接就是在编译链接时直接将需要的执行代码拷贝到调用处。动态链接就是在编译的时候不直接拷贝可执行代码，而是通过记录一系列符号和参数，在程序运行或加载时将这些信息传递给操作系统，操作系统负责将需要的动态库加载到内存中，然后程序在运行到指定的代码时，去共享执行内存中已经加载的动态库可执行代码，最终达到运行时连接的目的。

静态链接代码装载速度快，执行速度比动态链接快，但生成的可执行文件比较大。

动态链接可以节省内存，减少页面交换。dll文件（拥有外部函数）与exe文件独立，只需要保证接口不变，更换dll文件对exe无影响，极大地提高可维护性和可拓展性。不同的编译语言可以用同一个dll文件。适用于大规模软件开发，使得开发过程独立，耦合度小。缺点是运行速度慢，且dll文件不存在程序会终止运行并报错。

## new/delete 和 malloc/free 的区别与联系
### 区别
1、 malloc/free 是函数（标准库函数 void *malloc(long NumBytes)，void free(void *FirstByte)），new/free是运算符。

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

## 声明和定义
变量定义：用于为变量分配存储空间，还可为变量指定初始值。程序中，变量有且仅有一个定义。

变量声明：用于向程序表明变量的类型和名字。

    [注意] 
    变量在使用前就要被定义或者声明。 
    定义也是声明，extern声明不是定义
    在一个程序中，变量只能定义一次，却可以声明多次。 
    定义分配存储空间，而声明不会。

声明，定义，初始化是变量的三种状态。可以使用  extern告诉编译器变量在其他地方定义了。带有初始化式的声明也是定义，即使前面加了extern。

    extern int i;       //声明，不是定义
    int i;              //声明，也是定义，未初始化
    extern double pi=3.141592654;  //定义，初始化
声明都有extern关键字，有extern关键字的不一定是声明。

程序模块化设计风格：

    不要在.h文件中定义变量。
    尽量使用static关键字把变量定义限制于该源文件作用域，除非变量被设计成全局的。
    可以在头文件中声明一个变量，在用的时候包含这个头文件就声明了这个变量。

    模块即是一个.c文件和一个.h文件的结合，头文件(.h)中是对于该模块接口的声明；
 
     某模块提供给其它模块调用的外部函数及数据需在.h中文件中冠以extern关键字声明；
    
    模块内的函数和全局变量需在.c文件开头冠以static关键字声明；
 
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