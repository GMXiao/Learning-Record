# Nginx 入门
Nginx作为高性能的web和反向代理服务器，在互联网公司应用广泛。

## 安装
    # CentOS
    yum install nginx;
    # Ubuntu
    sudo apt-get install nginx;
    配置文件nginx.conf默认在/etc/nginx/目录下。
    部署文件可在/var/www/下。
    # Mac
    brew install nginx;

## 使用
    # 启动
    nginx -s start;
    # 重新启动，热启动，修改配置重启不影响线上
    nginx -s reload;
    # 关闭
    nginx -s stop;
    # 修改配置后，可以通过下面的命令测试是否有语法错误
    nginx -t;