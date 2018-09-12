## DOM

#### node 类型

node类型是所有的元素原型,所有元素继承其方法和属性

| 属性            |                |
| --------------- | -------------- |
| firstChild      | 第一个子元素   |
| lastChild       | 最后一个子元素 |
| nextSibling     | 下一个元素     |
| previousSibling | 前一个元素     |
| ownerDocument   | 指向文档节点   |

| 操作节点                          |                      |
| --------------------------------- | -------------------- |
| appendChild(newNode)              | 末尾添加             |
| insertBefore(newNode)             | 前添加               |
| replaceChild(newNode,replaceNode) | 替换节点             |
| removeChild(newNode)              | 删除节点             |
| cloneNode(bool)                   | 复制节点(是否深拷贝) |

#### Document 类型

| 属性              |                   |
| ----------------- | ----------------- |
| document.URL      | 获取完整url       |
| document.domain   | 获取域名          |
| document.referrer | 获取来源页面的url |
|document.head|获取头部|
|document.body|获取body节点|



| 方法                         |      |
| ---------------------------- | ---- |
|document.getElementById()    |      |
|document.getElementsByTag()  |      |
|document.getElementsByName() |      |
|document.getElementsByClassName() ||
|document.write() | |
|document.writeln()||



#### Element

|                   |          |
| ----------------- | -------- |
| getAttribute()    | 获取特性 |
| setAttribute()    | 设置特性 |
| removeAttribute() | 删除特性 |
|style|css操作|
|document.createElement()|创建元素|



#### Text 类型

|                           |              |
| ------------------------- | ------------ |
| document.createTextNode() | 创建文本节点 |




#### 扩展

|                    |              |
| ------------------ | ------------ |
| querSelector()     | 单元素选择器 |
| querySelectorAll() | 多元素选择器 |
| innerHTML()        |              |
| outerHTML ()       |              |
| scrollIntoView()   |              |

