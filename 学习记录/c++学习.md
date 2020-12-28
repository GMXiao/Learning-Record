## 指针和引用

### 引用当参数和返回值
当函数返回一个引用时，则返回一个指向返回值的隐式指针。这样，函数就可以放在赋值语句的左边，来修改被引用的变量。

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