# HTTP缓存
> target: 网络-http协议

根据是否与服务器协商分为
+ 强缓存
+ 协商缓存

## 强缓存
### 1、Expires
Expires是http1.0提出的一个**表示资源过期时间**的http头内容，它描述的是一个绝对时间

### 2、Cache-Control
Cache-Control 出现于 HTTP / 1.1，**由服务器返回**， **优先级高于 Expires** ,表示的是相对时间

## 协商缓存
### 1、Last-Modified，If-Modified-Since
最后一次修改时间
### 2、ETag、If-None-Match
文件指纹hash