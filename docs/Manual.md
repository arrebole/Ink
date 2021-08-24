# Manual


## CORS
> 允许请求它自己以外的其它 origin（域，协议和端口）

+ [简单请求](#简单请求) 允许浏览器直接跨域请求
+ [预检请求](#预检请求) 通过预检请求之后，允许浏览器跨域请求

### 简单请求
> 它限制了 `http method` 和 `http headers`

必须是下列HTTP方法之一：
+ `GET`
+ `HEAD`
+ `POST`

只能包含下列HTTP头:
+ `Accept`
+ `Accept-Language`
+ `Content-Language`
+ `Content-Type`
    + `text/plain`
    + `multipart/form-data`
    + `application/x-www-form-urlencoded`
+ 自动设置的(`User-Agent`..)

### 预检请求
> 使用 `OPTIONS` 方法发起一个预检请求到服务器，以获知服务器是否允许该实际请求

#### 检测`Origin`是否允许

1、请求
```http
Access-Control-Allow-Origin: http://foo.example
```
2、响应
```http
Access-Control-Allow-Origin: http://foo.example
```

#### 检测`Method`是否允许

1、请求
```http
Access-Control-Request-Method: POST
```
2、响应
```http
Access-Control-Allow-Methods: POST
```

#### 检测 `Headers` 是否允许

1、请求
```http
Access-Control-Request-Headers: X-PINGOTHER
```
2、响应
```http
Access-Control-Allow-Headers: X-PINGOTHER
```

#### 附带身份凭证的请求
对于跨源 `XMLHttpRequest` 或 `Fetch` 请求，浏览器不会发送身份凭证信息 `cookies`, `authorization`。

如果要发送凭证信息，需要设置 `withCredentials`。

并且对于附带身份凭证的请求，服务器不得设置 `Access-Control-Allow-Origin` 的值为 `*`。

1、请求
```http
GET /resources HTTP/1.1
Host: bar.other
Origin: http://foo.example
Cookie: pageAccess=2
```

2、响应
```http
HTTP/1.1 200 OK
Access-Control-Allow-Origin: http://foo.example
Access-Control-Allow-Credentials: true
```
