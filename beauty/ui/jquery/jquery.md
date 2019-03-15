# JQuery

## 1. Ajax

### 1.1 简介

Asynchronous JavaScript And XML

使用Ajax与服务器通信

使用js发送ajax请求

```javascript
var xhr;
//ie
if(windows.ActiveXObject){
    xhr=new ActiveXObject('Microsoft.XMLHTTP');
}else if(windows.XMLHttpRequest){
    xhr=new XMLHttpRequest();
}else{
    throw new Error("此浏览器不支持ajax")
}
```

#### 1.1.1 方法,属性

1. 方法

| 方法                                     | 描述                                                         |
| ---------------------------------------- | ------------------------------------------------------------ |
| abort()                                  | 取消正在执行的请求                                           |
| getAllResponseHeaders()                  | 获取所有响应头(名称和值)的一个字符串                         |
| getResponseHeader(name)                  | 获取指定响应头的值                                           |
| open(method,url,async,username,password) | 设置请求方式和url(可以声明为同步请求,也可以提供用户名和密码) |
| send(content)                            | 发送数据                                                     |
| setRequestHeader(name,value)             | 设置响应头                                                   |

2. 属性

| 属性               | 描述                                                         |
| ------------------ | ------------------------------------------------------------ |
| onreadystatechange | 事件处理器                                                   |
| readyState         | 当前请求状态<br>0=UNSENT<br/>1=OPENED<br/>2=HEADERS_RECEIVED<br/>3=LOADING<BR/>4=DONE |
| reponseText        |                                                              |
| status             |                                                              |

> http规范200~299的状态码均为正常

```javascript
var xhr;
xhr.onreadystatechange=function(){
    if(this.readyState==4){
        if(this.status<300){
            //成功
            alert("成功");
        }else{
            alert("失败");
        }
    }
       
}
xhr.open('get','/some/music');
xhr.send();
```

 