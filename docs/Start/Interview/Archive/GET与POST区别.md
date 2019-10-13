
# GET和POST的区别
> target: 网络-http协议
+ GET和POST都是http request方法，它们在http 请求行中标明
+ GET是幂等方法，POST是非幂等方法
+ GET能够被浏览器缓存，POST无法被缓存
+ **POST比GET多了主体长度信息和类型,在请求头中必须有`Contents-Length`和`Contents-Type`**
+ **POST请求会分包，GET产生一个http数据包，POST产生至少两个http数据包**

