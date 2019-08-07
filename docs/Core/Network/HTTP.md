# HTTP

## Introduction
+ HTTP 协议构建于 TCP/IP 协议之上(http3由udp实现)，是一个应用层协议，默认端口号是80, https是443
+ HTTP 是无连接无状态的

## Table of Contents
+ [HTTP报文](#HTTP报文)
    + [GET与POST的区别](#GET与POST的区别)
+ [状态码](#状态码)
+ [同源策略](#同源策略)
+ [缓存策略](#缓存策略)
+ [压缩](#压缩)

## HTTP报文
> 规范把 HTTP 请求分为三个部分：状态行、实体头、消息主体

根据request和response又可划分
+ 请求行(请求方法 URL 协议版本)、请求头、请求主体
+ 响应行(协议版本 状态码 状态文字)、响应头、响应主体

```tex
<method> <request-URL> <version>
<headers>

<entity-body>
```

​	

### GET与POST的区别

+ GET和POST都是http request方法，它们在http 请求行中标明

+ GET是幂等方法，POST是非幂等方法

+ POST比GET多了主体长度信息和类型,在请求头中必须有`Contents-Length`和`Contents-Type`

+ POST请求会分包，GET产生一个http数据包，POST产生至少两个http数据包



GET 请求报文示例

```tex
 GET /index.html HTTP/1.1
 Host: www.example.com
```

POST 请求报文示例

```tex
 POST /book HTTP/1.1
 Host: www.example.com
 Content-Type: application/x-www-form-urlencoded
 Content-Length: 40
 \n
 sex=man&name=Professional  
```



## 状态码

| code | 描述       |
| ---- | ---------- |
| 1xx  | 未完成     |
| 2xx  | 成功       |
| 3xx  | 重定向     |
| 4xx  | 客户端错误 |
| 5xx  | 服务器错误 |

特殊状态码

| code | 描述                   |
| ---- | ---------------------- |
| 307  | 重定向，post内容不丢失 |
| 304  | 协商缓存               |
| 404  | 未找到                 |



## 同源策略

> 同源 = 同协议 + 同主机 + 同端口

跨域方法

+ cors
+ jsonp



## 缓存策略

+ 强缓存	cache-control
+ 协商缓存  etag