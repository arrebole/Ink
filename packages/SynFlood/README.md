# 构造TCP数据包实现SynFlood攻击

> 所属: Dos -> Flood -> Tcp -> SynFlood

通过手动构建TCP数据包，伪造发起请求者，使目标服务器对大量的伪造请求产生大量的空连接。

只进行第一次tcp握手，发送一个伪造源的同步数据包，使目标服务器处于等待状态

也可以使用更加邪恶的手段，将源地址改为目标地址，让目标服务器自己与自己产生错误连接

windows上的原始套接字不允许发送tcp数据, 请不要在win下尝试

实验结果:
+ 数据包大于1490，将无法突破局域网
+ 杀伤力极低，只有O(n)， 且常系数k小于1

## How to use?
```bash
# use make
make 
```
```bash
# or use go build
go build ./src/main.go
```
```bash
# ping w 指定线程数量
./ping --host www.baidu.com -w 3
```

```bash
[success] 180.101.49.11 [byte=28][TTL=52]
[success] 180.101.49.11 [byte=28][TTL=52]
[success] 180.101.49.11 [byte=28][TTL=52]
```