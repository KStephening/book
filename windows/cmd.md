# 常用cmd命令
## 端口被占用
```cmd

netstat -ano|findstr 8080
taskkill /f /t /im 12048
```