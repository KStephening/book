# NGINX
## 1.常用命令
![](screenshot/2019-07-09-16-01-28.png)

hosts文件修改

nginx.conf增加下面这句,表示包含vhost文件夹下的所有.conf文件
```
include vhost/*.conf
```
