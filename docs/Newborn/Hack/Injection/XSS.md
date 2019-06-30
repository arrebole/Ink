# XSS

## Introduction

逃过对script的过滤。



## Table of Contents

+ Resources
  + [AwesomeXSS](https://github.com/s0md3v/AwesomeXSS)
  + [Cheatsheet](https://github.com/cure53/H5SC)
  
+ Feature
  + Server render
    + [直接吐html]()
  + Browser render
    + [write()/writeln()]()
    + [innerHTML()]()
    + [textContent()]()
    + [apend()]()
    + [innerText()]()
  + Filtering rules
    + 无过滤
    + 过滤 `</>`
  
+ 漏洞

  +  低版本Jquery

+ 实战记录



## Feature

### Filtering rules

#### 无过滤类型

前端使用 innerHTML，并直接字符串拼接

```html
<!--例如前端函数-->
<p id = "app"></p>
<script>
    let app = document.getElementById("app")
    function escape(data) {
        return "<h1>" + data + "</h1>";
    }
    app.innerHTML = escape(xss)
</script>
```

+ **解法1：嵌入dom（慢性）**

  延缓执行，等到html标签被渲染时执行xss

```javascript
// 由于是前端渲染，注入的script标签内的xss，默认不经过js主线程，
// 可以利用html渲染的钩子触发执行js
escape(`<img src="404.jpg" onerror=alert(1) />`)
```

+ **解法2：截断（急性）**

   截断字符串，在escape内直接执行

```typescript
escape(`${alert(1)}`)
```

