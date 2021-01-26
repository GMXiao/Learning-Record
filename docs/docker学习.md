# Docker

资料可参考[Docker从入门到实践](https://yeasy.gitbook.io/docker_practice/)
## Docker 与 虚拟机的差别
每个虚拟机有自己的独立内核；所有docker共用一个内核，docker之间的不同点在于，每个docker拥有自己的用户空间，类似于操作系统不用的用户之间的关系。
## 理解Docker三大基本概念
### 镜像
操作系统分为内核和用户空间。对于 Linux 而言，内核启动后，会挂载 root 文件系统为其提供用户空间支持。而 Docker 镜像（Image），就相当于是一个 root 文件系统。
### 容器
容器和镜像，就是对象和类的关系。镜像是静态的定义，容器是镜像运行时的实体。容器可以被创建、启动、停止、删除、暂停等。容器的实质是进程，但与直接在宿主执行的进程不同，容器进程运行于属于自己的独立的 命名空间。因此容器可以拥有自己的 root 文件系统、自己的网络配置、自己的进程空间，甚至自己的用户 ID 空间。

镜像使用的是分层存储，容器也是如此。每一个容器运行时，是以镜像为基础层，在其上创建一个当前容器的存储层，我们可以称这个为容器运行时读写而准备的存储层为 容器存储层。
### 仓库
Docker Registry 是一个集中的存储、分发镜像的服务。

一个 Docker Registry 中可以包含多个 仓库（Repository）；每个仓库可以包含多个 标签（Tag）；每个标签对应一个镜像。

通常，一个仓库会包含同一个软件不同版本的镜像，而标签就常用于对应该软件的各个版本。我们可以通过 <仓库名>:<标签> 的格式来指定具体是这个软件哪个版本的镜像。如果不给出标签，将以 latest 作为默认标签。

## 安装Docker
https://yeasy.gitbook.io/docker_practice/install/ubuntu
## Docker镜像操作 
* docker pull
* docker image ls 列出可用镜像
* docker image rm
## Docker容器操作
* docker run \<image>
* docker ps -a
* docker stop \<container>
* docker rm \<container> 
## Docker仓库操作

## Docker进阶知识