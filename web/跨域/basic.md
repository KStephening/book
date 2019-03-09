# Basic

## 1. Session

### 1.1 三种`getSession`

```java
//下面两种用法相同
//如果没有session,会创建一个新的session---适合存取登录信息
HttpServletRequest.getSession();
HttpServletRequest.getSession(ture);

//如果没有session,会返回null
HttpServletRequest.getSession(false);
```

## 2. 跨域

### 2.1 跨域产生的原因

1. 发送的是XHR(XMLHttpRequest)请求
2. 浏览器限制(浏览器会做校验)
3. 跨域(协议,端口,域名任何一个不是本域的都会产生跨域)

### 2.2 解决思路

1. 浏览器限制--可以设置浏览器启动方式,可以用,但是没有意义
2. 针对XHR,可以采用JSONP(**目前JSONP有很多缺点,并不适用**)
3. 跨域--最终解决方案



#### 2.2.1 跨域解决思路

>  - 被调用方(服务端)
>  - 调用方(客户端)

## 3. 解决方法

### 3.1  浏览器  命令行启动

`chrome --disable-web-security --user-data-dir=g:\temp3`

### 3.2 JSONP










