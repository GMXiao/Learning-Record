# Hon-Textile学习记录（GO 语言）
## protobuf  的格式
Protocol Buffers 是 google 出品的一种数据交换格式, 缩写为 protobuf。

Protobuf中最基本的数据单元是message，是类似Go语言中结构体的存在。在message中可以嵌套message或其它的基础数据类型的成员。

下面是一个简单的例子：
```
syntax = "proto3";

package main;

message String {
    string value = 1;
}
```
首行定义了语法版本, 即使用 proto3 版本. 然后定义了一个名为 SearchRequest 的 message, 以及它包含的字段(键值对). message 的结构非常类似于各种语言中的 struct, dict 或者 map.

每个字段包括三个部分，类型，字段名和字段编号。字段编号是唯一的，用于在essage的二进制格式中标识字段。 

proto3标准类型如下：

![proto3标准类型](/pictures/proto3标准类型.png "proto3标准类型")

## protobuf 使用特例
使用 repeated 可以指定重复字段, 即数组：

    message Test4 {
    repeated int32 d = 4 [packed=true];
    }

类型也可以嵌套使用：

    message SearchResponse {
    repeated Result results = 1;
    }

    message Result {
    string url = 1;
    string title = 2;
    repeated string snippets = 3;
    }

## protobuf 安装
    go get github.com/golang/protobuf/protoc-gen-go

## protobuf 的编译方法
可以同时编译一个文件，多个文件或者所有文件。
### 对于Go语言来说
编译文件message.proto,--proto_path指定该文件目录，--go_out指定输出目录：

    protoc --proto_path=pb/protos --go_out=pb pb/protos/message.proto

编译文件message.proto和mobile.proto：

    protoc --proto_path=pb/protos --go_out=pb pb/protos/message.proto pb/protos/mobile.proto

编译pb/protos文件夹下的所有.proto文件：

    protoc --proto_path=pb/protos --go_out=pb pb/protos/*.proto
* 需要注意的是,在有多个.proto文件的目录下，即使只修改了一个.proto文件也需要编译该目录下的所有.proto文件。
### 对于Java语言来说
编译文件message.proto,-I指定该文件目录，--java_out指定输出目录，使用格式和Go语言类似。

## sqlite3使用
官网 (https://www.sqlite.org/index.html)

Github 网址 (https://github.com/mattn/go-sqlite3)

GoDoc  地址 (https://godoc.org/github.com/mattn/go-sqlite3)

Go中已经有一个database/sql包，但是它需要一个driver来使用相关方法，（The sql package must be used in conjunction with a database driver. See <https://golang.org/s/sqldrivers> for a list of drivers.）。所以我们可以使用sqlite3的driver来做这件事。
API可以查看GoDoc文档，使用例可看[实例代码](https://github.com/GMXiao/Linux-Learning/blob/master/%E7%9B%B8%E5%85%B3%E6%96%87%E6%A1%A3/sqlOpt.go)。

## 服务器部署cafe节点
* 创建节点wallet: textile wallet create
* 初始化IPFS节点: textile init < seed >
* 生成token: textile token add
* Android源码中部署cafe 信息: url("http://139.159.200.151:40601"),token("a33d...")

