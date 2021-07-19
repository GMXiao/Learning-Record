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

## QUIC协议 代替 TCP协议
资料：https://www.chromium.org/quic

QUIC 是通过UDP 进行的多路复用流传输，是一种新的传输方式，与TCP相比它减少了延迟。从表面上看，QUIC与在UDP上实现的TCP + TLS + HTTP/2 非常相似。由于TCP是在操作系统内核和中间设备固件中实现的，因此对TCP进行重大更改几乎是不可能的。但是，由于QUIC建立在UDP之上，因此没有任何限制。

### MiddleBox 中间设备
在计算机网络的范畴中，中间设备是一种计算机网络设备，可为数据包转发以外的目的而进行转换，检查，过滤和处理流量。这些多余的功能干扰了应用程序的性能，并因违反“重要的架构原则”（如端对端原则）而受到批评。中间件包括防火墙，网络地址转换器（NAT），负载均衡器和深度包检查（DPI）盒。


### HTTP/2 超文本传输协议第二版
HTTP/2 通过下面方法减少网络延迟，提高浏览器的页面加载速度：

    对HTTP头字段进行数据压缩(即HPACK算法)；
    HTTP/2 服务端推送(Server Push)；
    请求流水线；
    修复HTTP/1.0版本以来未修复的 队头阻塞 问题；
    对数据传输采用TCP连接复用，让多个请求合并在同一 TCP 连接内。
### TLS 传输层安全性协议
传输层安全性协议（Transport Layer Security，TLS）及其前身安全套接层（Secure Sockets Layer，SSL）是一种安全协议，目的是为互联网通信提供安全及数据完整性保障。

### HTTPS 超文本传输安全协议
超文本传输安全协议（HyperText Transfer Protocol Secure，HTTPS；常称为HTTP over TLS、HTTP over SSL或HTTP Secure）是一种通过计算机网络进行安全通信的传输协议。HTTPS经由HTTP进行通信，但利用SSL/TLS来加密数据包。

HTTPS开发的主要目的，是提供对网站服务器的身份认证，保护交换资料的隐私与完整性。HTTPS的信任基于预先安装在操作系统中的证书颁发机构（CA）。

HTTP的URL是由“http://”起始与默认使用端口80，而HTTPS的URL则是由“https://”起始与默认使用端口443。

### libp2p/go-libp2p-quic-transport 代码研究
cmd/server/main.go

cmd/client/main.go

双方先用"github.com/libp2p/go-libp2p-quic-transport"中的静态方法 NewTransport 构建一个新的QUIC传输对象t 。然后 Server端使用t的方法Listen监听Client端的Dial方法。Client通过Dial方法拨通一个新的QUIC连接


