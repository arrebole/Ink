# HTTP

## Introduction
HTTP 协议构建于 TCP/IP 协议之上(http3由udp实现)，是一个应用层协议，HTTP 是无连接无状态的



## Table of Contents

+ [HTTP报文](#HTTP报文)
    + [GET与POST的区别](#GET与POST的区别)
+ [状态码](#状态码)
+ [同源策略](#同源策略)
    + [跨域](#跨域)
+ [缓存策略](#缓存策略)
    + [强缓存](#强缓存)
    + [协商缓存](#协商缓存)
+ [压缩](#压缩)
    + [Gzip](#Gzip)
    + [http2头压缩]()

## $HTTP报文
> 规范把 HTTP 请求分为三个部分：状态行、实体头、消息主体

根据request和response又可划分
+ 请求行(请求方法 URL 协议版本)、请求头、请求主体
+ 响应行(协议版本 状态码 状态文字)、响应头、响应主体

```tex
<method> <request-URL> <version>
<headers>

<entity-body>
```


### GET与POST的区别

+ GET和POST都是http request方法，它们在http 请求行中标明
+ GET是幂等方法，POST是非幂等方法
+ GET能够被浏览器缓存，POST无法被缓存
+ POST比GET多了主体长度信息和类型,在请求头中必须有`Contents-Length`和`Contents-Type`
+ POST请求会分包，GET产生一个http数据包，POST产生至少两个http数据包



### GET 请求报文示例

```http
 GET /index.html HTTP/1.1
 Host: www.example.com
```



### POST 请求报文示例

```http
 POST /book HTTP/1.1
 Host: www.example.com
 Content-Type: application/x-www-form-urlencoded
 Content-Length: 40
 \r\n
 sex=man&name=Professional  
```



## $状态码

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



## $同源策略

> 同源 = 同协议 + 同主机 + 同端口

### 跨域
+ cors
+ jsonp



## $缓存策略
> 良好的缓存策略可以降低资源的重复加载，减轻服务器的压力、提高网页的整体加载速度
> 通常浏览器缓存策略分为两种：强缓存和协商缓存

**1、基本原理**

+ 强缓存: 浏览器在加载资源时，根据请求头的expires和cache-control判断是否命中，是则直接从缓存读取资源，不会发请求到服务器。
+ 协商缓存: 如果没有命中强缓存，浏览器一定会发送一个请求到服务器，通过last-modified和etag验证资源是否命中协商缓存，如果命中，服务器返回状态码403，浏览器会从缓存中读取资源
+ 无缓存：如果前面两者都没有命中，直接从服务器加载资源

**2、相同点**

+ 如果命中，都是从客户端缓存中加载资源，而不是从服务器加载资源数据；

**3、不同点**

+ 强缓存不发送请求到服务器，协商缓存会发请求到服务器。



### 强缓存

强缓存通过`Expires`和`Cache-Control`两种响应头实现

#### 1、Expires

Expires是http1.0提出的一个**表示资源过期时间**的http头内容，它描述的是一个绝对时间，**由服务器返回**。

Expires 受限于本地时间，如果修改了本地时间，可能会造成缓存失效。

```http
HTTP/1.1 200 OK
Expires: Wed, 11 May 2019 19:20:00 GMT
```



#### 2、Cache-Control

Cache-Control 出现于 HTTP / 1.1，**由服务器返回**， **优先级高于 Expires** ,表示的是相对时间

```http
HTTP/1.1 200 OK
Cache-Control: max-age=315360000
```

**其他选项**

`Cache-Control: no-store` 不缓存数据
`Cache-Control: public` 可以被所有用户缓存
`Cache-Control: private` 只能被终端浏览器缓存（不允许中继缓存服务器进行缓存）



### 协商缓存

协商缓存是利用的是`Last-Modified，If-Modified-Since`和`ETag、If-None-Match`管理。

请求到服务器，验证协商缓存是否命中，如果协商缓存命中，请求响应返回的http状态码为304，状态信息为Not Modified

#### 1、Last-Modified，If-Modified-Since

`Last-Modified` 表示本地文件最后修改日期，

浏览器会在请求头加`If-Modified-Since`（上次返回的`Last-Modified`的值），询问服务器在该日期后资源是否有更新，有更新的话就会将新的资源发送回来，无更新则返回304

**服务器返回报文**

```http
HTTP/1.1 200 OK
Last-Modified: Thu, 27 Sep 2018 14:06:53 GMT
```

**浏览器请求报文**

```http
GET /main.js HTTP/1.1
Host: www.samples.com
If-Modified-Since: Thu, 27 Sep 2018 14:06:53 GMT
```



#### 2、ETag、If-None-Match

`Etag`是文件指纹，一般通过一致性hash计算，`ETag`的优先级高于`Last-Modified`

`If-None-Match`的header会将上次返回的`Etag`发送给服务器，询问该资源的`Etag`是否有更新，有变动就会发送新的资源回来，无更新则返回304

**浏览器请求**

```http
GET /main.js HTTP/1.1
Host: www.samples.com
If-None-Match:"d2a579b6ada54bba80eb18acf65f223d"
```

**服务器返回**

```http
GET /main.js HTTP/1.1
Host: www.samples.com
Etag:"d2a579b6ada54bba80eb18acf65f223d"
```



