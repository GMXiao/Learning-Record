# MySQL in ubuntu
## MySQL在ubuntu中的安装
    1、使用命令 “wget https://dev.mysql.com/get/mysql-apt-config_0.8.15-1_all.deb” 获取mysql deb包。
    2、使用命令 “dpkg -i <文件名>” 来解压刚刚获取到的安装包。
    3、分别选择 “MySQL Server & Cluster”, “mySQL-8.0”, “ok”
    4、使用命令 “apt-get install mysql-server”来安装mySQL，之后设
    置密码及加密方式。
## MySQL在ubuntu中的使用
    1、数据库服务操控
        service mysql start：启动数据库服务
        service mysql stop：停止数据库服务
        service mysql restart：重启数据库服务
        service mysql status： 查看数据库运行状态。
        -绿点：正在运行
        -白点：停止运行
    3、登录数据库后执行指令
        -使用命令 “mysql [-h <ip> –P <port>] –uroot -p<password>” 登录远程主机
        -输入命令 “mysql -uroot -p<password>”登录本地主机。
        -执行数据库指令。
        -执行指令“exit”退出。
    4、不登录数据库直接执行命令
        使用命令“mysqladmin -uroot -p<password> <数据库指令>”。