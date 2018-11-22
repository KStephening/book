# VUE-BASIC
## 1.basic
### 1.1 `el`--选择器
### 1.2 `$`--实例属性与方法
```html
<div id="vue_det">
    <h1>site : {{site}}</h1>
    <h1>url : {{url}}</h1>
    <h1>Alexa : {{alexa}}</h1>
</div>
<script type="text/javascript">
// 我们的数据对象
var data = { site: "菜鸟教程", url: "www.runoob.com", alexa: 10000}
var vm = new Vue({
    el: '#vue_det',
    data: data
})
// true
document.write(vm.$data === data) 
// true
document.write("<br>") 
// true
document.write(vm.$el === document.getElementById('vue_det')) 
</script>
```
### 1.3 `v-`指令
1. v-html:输出html代码
2. v-if:是否插入
3. v-bind:使用属性中的值(缩写`:`)
4. v-on:监听DOM事件(缩写`@`)
5. .修饰符:如`v-on:submit.prevent="onSubmit"`调用event.preventDefault()
6. v-model:双向绑定.用来在 input、select、text、checkbox、radio 等表单控件元素上创建双向数据绑定，根据表单上的值，自动更新绑定的元素的值。
7. v-show:安装条件展示元素

```html
<style>
.class1{
  background: #444;
  color: #eee;
}
</style>
<div id="app">
    <p v-if="seen"></p>
    <div v-html="message"></div>
    <label for="r1">update color</label>
    <input type="checkbox" v-mosdel="class1" id="r1>
    <!-- 如果class1的值为true使用class1的样式 -->
    <div v-bind:class="{'class1':class1}">
        v-bind:class 指令
    </div>
    <div>
        <p>v-model双向绑定</p>
        <p>{{msg}}</p>
        <input v-model="msg">
        <button v-on:click="reverseMsg">反转</button>
    </div>
    <h1 v-show="seen">Hello!</h1>
</div>
<script>
new Vue({
    el:'#app',
    data:{
        seen:true,
        message:'<h1>Longer\' World</h1>',
        msg:'super',
        class1:false
    },
    method:{
        reverseMsg:function(){
            this.msg=this.msg.split('').reverse().join('')
        }
    }
})
</script>
```
## Vue与JavaScript均可以使用
```html
<div id="app">
	{{5+5}}<br>
	{{ ok ? 'YES' : 'NO' }}<br>
	{{ message.split('').reverse().join('') }}
	<div v-bind:id="'list-' + id">菜鸟教程</div>
</div>
	
<script>
new Vue({
  el: '#app',
  data: {
	ok: true,
    message: 'RUNOOB',
	id : 1
	}
})
</script>
```
### 1.4 过滤器`|`

#### 1.4.1 语法
> {参数|过滤原则}
```html
<div id="app">
<!-- 将msg转化为大写 -->
{{msg|capitalize}}
</div>

<script>
new Vue({
    el:'#app'
    data:{
        msg:'longer'
    }
    //大写
    capitalize:function(value){
        if(!value) return ''
        value=value.toString
        return value.chatAt(0).toUpperCase+value.slice(1)
    }
})
    
</script>
```
#### 1.4.2 过滤器可以串联
> {{msg|filterA|filterB}}
#### 1.4.3 过滤器可以传参
> {{msg|filterA('arg1',arg2)}}

### 1.5 条件判断
#### v-if的另一种用法
在上面已经看到了v-if的一种用法,下面还有一种用法:
字符串模板中:
```html
{{#if ok}}
    <p>longer</p>
{{/if}}
```
#### v-else以及v-else-if
```html
<div v-if="Math.random()>0.5">
    hello
</div>
<div v-else-if="Math.random()>0.8">
    longer
</div>
<div v-else>
    world
</div>
```
### 1.6 `v-for`循环
```html

```
