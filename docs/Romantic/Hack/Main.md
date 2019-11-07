# Hack

一不小心，就会堕入深渊。获得了强大的力量之后，往往会忘记自己行为的初衷。





## Table of Contents

**Network**

+ **Collect**
  + [Port Scan]()
  + [Sub Domain Enumeration](https://github.com/qazbnm456/awesome-web-security#sub-domain-enumeration)
+ **Injection**
  + [XSS]()
  + [CSRF]()
  + [SQL Injection](https://github.com/qazbnm456/awesome-web-security#sql-injection)
+ **DoS**
     + [PingofDeath]()
     + [PingFlood]()
     + [UDPflood]()
     + [SYNflood]()
     + [Smurf]()
     + [TearDrop]()
     + [LandAttack]()
     + [IPSpoofingDoS]()
+ **DDoS**
  + [CC]()

**Binary Exploitation**

**Lockpicking**

**0dya**

**hack limits**

**Beyond the hack limits**





# Network

## XSS

> **Cross-site scripting (XSS)**: 一种代码注入攻击，允许攻击者在另一个用户的浏览器中执行恶意JavaScript。

**漏洞点**：浏览器执行，用户注入的javascript;

**实现难点**：绕过文本过滤;



### major types

+ `Persistent XSS` 持久型：输入来自网站的数据库

+ `Reflected XSS` 反射型：输入来自受害者的请求
+ `DOM-based XSS` dom型：漏洞位于客户端代码

### consequences

+ **Cookie theft：盗取cookie，伪造登陆；**
+ Keylogging：侦听键盘，窃取密码；

+ Phishing： 伪造的登录表，指向自己的服务器
+ …

[详细操作…](/docs/Newborn/Hack/Injection/XSS.md)

