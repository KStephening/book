# 常用cmd命令
## 端口被占用
```cmd

netstat -ano|findstr 8080
taskkill /f /t /im 12048
```

## 把ps1文件注册为服务

把filebeat注册为服务

打开powershell,管理员运行

切换目录:
E:\logTool\filebeat-6.2.4-windows-x86_64

运行命令
`.\install-service-filebeat.ps1`

**可能会遇到的问题**

无法加载文件 D:\Workshop\Powershell\Sprinkler\src\Scripts\SPRINKLE.ps1，因为在此系统中禁止执行脚本。有关详细信息，请参
阅 "get-help about_signing"。

执行`get-ExecutionPolicy`
结果:`Restricted`--被限制

> 解决方法,运行`set-ExecutionPolicy RemoteSigned`

> 选择`y`

然后再重新注册即可



## 把bat注册成服务
Elasticsearch作为服务

新建cmd,以管理员运行

到E:\logTool\elasticsearch-6.2.4\bin目录下

执行下面的命令来安装服务

`elasticsearch-service.bat install`

启动服务

`elasticsearch-service.bat start`

> 启动的时候不要运行**elasticsearch.bat**

详见[注册windows系统服务](https://segmentfault.com/a/1190000012676619)

