# c++标准库参考

## string
cstring：是C标准库头文件\<string.h>的C++标准库版本，包含了C风格字符串（NUL即'\0'结尾字符串）相关的一些类型和函数的声明，例如strcmp、strchr、strstr等。\<cstring>和\<string.h>的最大区别在于，其中声明的名称都是位于std命名空间中的，而不是后者的全局命名空间。  
string：是包装了std 的C++头文件，对应的是新的string 类.  
string.h：是旧的C 头文件，对应的是基于char*的字符串处理函数.

## cstring
strlen:  strlan(char*) ,返回字符数组的长度，碰到'\0'停止计数，所以没赋初值它的值是不确定的。  


## STL
### 一些常用函数

|迭代器辅助函数|功能|
|:------:|:------:|
advance(it, n)|	it 表示某个迭代器，n 为整数。该函数的功能是将 it 迭代器前进或后退 n 个位置。
distance(first, last)|	first 和 last 都是迭代器，该函数的功能是计算 first 和 last 之间的距离。
begin(cont)|	cont 表示某个容器，该函数可以返回一个指向 cont 容器中第一个元素的迭代器。
end(cont)|	cont 表示某个容器，该函数可以返回一个指向 cont 容器中最后一个元素之后位置的迭代器。
prev(it)|	it 为指定的迭代器，该函数默认可以返回一个指向上一个位置处的迭代器。注意，it 至少为双向迭代器。
next(it)|	it 为指定的迭代器，该函数默认可以返回一个指向下一个位置处的迭代器。注意，it 最少为前向迭代器。
