# Linux-Learning
Some problems and details when I studying Linux System.

## 一些常用命令
### 查看系统信息
* lscpu：查看的是cpu的统计信息.
* cat /proc/cpuinfo：可以知道每个cpu信息，如每个CPU的型号，主频等。
* free -m: 概要查看内存情况
* cat /proc/meminfo:  查看内存详细使用
* lsblk: 查看硬盘和分区分布
* fdisk -l: 看硬盘和分区的详细信息
* 查看分区的UUID命令： blkid
* 格式化硬盘： mkfs -t ext4 /dev/sdb
* 挂载：mount (-t type) (-o option) /dev/sdb point
### 有关进程的命令
* telnet ip port: 测试某个端口的连通性
* lsof -i:5037: 查看端口号占用
* ps -a: 打印进程
* kill <数字信号> <进程ID>：根据进程ID来杀死后台进程，一般使用的是15信号，但是有些进程可能不会理会该信号，所以可以加 -9 来使用9信号，该信号则不会被忽略。（kill -9 pid）
* pkill <数字信号> <进程名>：根据进程名杀死后台进程。（pkill -9 进程名）
### ssh 和 scp 
* ssh \<username>@serverIP :从一个终端使用ssh连接到另一个终端，需要输入该终端的用户密码。
* scp \<local file path> \<username>@\<remote IP>:\<remote path>,传输单个文件或多个文件到指定目录下，其中local file path可以是单个文件或多个文件，多个文件用空格隔开。
* scp -v -r \<local folder path> root@\<remote IP>:\<remote path>， 传输整个文件夹到指定目录下。

### git 使用
    有关git的文档可以查阅 [github官方文档](https://docs.github.com/cn)。
    git远程服务器和本地用户机器之间使用SSH公钥进行验证。
    用户的SSH公私钥一般保存在 ~/.ssh/目录下，分别为id_rsa,id_rsa.pub。如果没有该文件，可以使用ssh-keygen来创建。
    在创建了ssh公私钥之后，可以查看id_rsa.pub，复制其中的公钥内容添加到git上。

## bashrc 和 profile 的区别

## 一些Linux安装时的错误记录




## 虚拟机测试时写的一些脚本
### 绑定内核与进程
主要使用命令 taskset -cp <内核（0-N）> \<pid> 进行绑定。
示例脚本如下：

    #!/bin/bash
    num=0
    pid=$(ps -a|grep player|grep -v grep|awk '{print $1}')
    for i in $pid./
    do
        echo "bangding the $num cpu with player ${i}"
        taskset -cp $num $i
        num=`expr $num + 1`;
    done

### 