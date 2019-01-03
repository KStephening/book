# js
## 1. 方法
| 方法                           | 描述                      | 备注                                      |
| ------------------------------ | ------------------------- | ----------------------------------------- |
| setTimeout(function(){},3000)  | 多少时间后执行            |                                           |
| clearTimeout(id)               | 阻止方法的执行,根据id删除 |                                           |
| setInterval(function(){},3000) | 每间隔3秒执行一次         | setInterval('alert("hello");',3000)也可以 |
| clearInterval(id)              | 阻止方法的执行,根据id删除 |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |
|                                |                           |                                           |

## 2. promise



###	 `export`和`export default`

 异同:

1.export与export default均可用于导出常量、函数、文件、模块等
 2.你可以在其它文件或模块中通过import+(常量 | 函数 | 文件 | 模块)名的方式，将其导入，以便能够对其进行使用
 3.在一个文件或模块中，export、import可以有多个，export default仅有一个
 4.通过export方式导出，在导入时要加{ }，export default则不需要

作者：开车去环游世界

链接：https://www.jianshu.com/p/edaf43e9384f

```javascript
//export_a.js
//export导出
export str='hello';
export function getStr(){
    return str;
}

//导入export导出的内容
//from 后面跟的是js文件的名字
import {str,getStr} from 'export_a'


//export_default_a.js
//export default
const str='hello';
export default str;
//导入--
import str from 'export_defualt_a'

```



