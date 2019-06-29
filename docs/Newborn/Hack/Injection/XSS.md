# XSS

## Introduction

逃过对script的过滤。



## Table of Contents

+ Resources
  + [AwesomeXSS](https://github.com/s0md3v/AwesomeXSS)
  + [Cheatsheet](https://github.com/cure53/H5SC)
  
+ 特征点
  + html render
    + 后端渲染
      + [直接吐html]()
    + 前端渲染
      + [write()/writeln()]()
      + [innerHTML()]()
      + [textContent()]()
      + [apend()]()
      + [innerText()]()
  + 过滤规则
    + 过滤`</>`
  
+ 漏洞

  +  低版本Jquery

+ 实战记录



## 热身

无过滤类型

```javascript
function escape(s) {
  return '<script>console.log("' + s + '");</script>';
}
```

+ 解法

```javascript
input: " + alert(1) + "

```



