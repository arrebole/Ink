# XSS

## Introduction

逃过对script的过滤。



## Table of Contents

+ Resources
  + [AwesomeXSS](https://github.com/s0md3v/AwesomeXSS)
  + [Cheatsheet](https://github.com/cure53/H5SC)
+ War
  + [热身](#热身)
  + 



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



