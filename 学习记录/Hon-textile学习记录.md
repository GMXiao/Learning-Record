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

编译文件message.proto,--proto_path指定该文件目录，--go_out指定输出目录：

    protoc --proto_path=pb/protos --go_out=pb pb/protos/message.proto

编译文件message.proto和mobile.proto：

    protoc --proto_path=pb/protos --go_out=pb pb/protos/message.proto pb/protos/mobile.proto

编译pb/protos文件夹下的所有.proto文件：

    protoc --proto_path=pb/protos --go_out=pb pb/protos/*.proto
* 需要注意的是,在多个

### windows