# Html
## 1. 标签
### 非常用标签
定义和用法
`<base>` 标签为页面上的所有链接规定默认地址或默认目标。

通常情况下，浏览器会从当前文档的 URL 中提取相应的元素来填写相对 URL 中的空白。

使用` <base> `标签可以改变这一点。浏览器随后将不再使用当前文档的 URL，而使用指定的基本 URL 来解析所有的相对 URL。这其中包括 <a>、<img>、<link>、<form> 标签中的 URL。

HTML 与 XHTML 之间的差异
在 HTML 中，<base> 标签没有结束标签；在 XHTML 中，<base> 标签必须被正确地关闭。
```html
<base href="http://me.longer.king">
```