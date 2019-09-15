# 构造icmp数据包实现ping功能

> 所属: Dos -> Flood -> icmp -> pingFlood

通过手动构建icmp数据包，并实现ping协议，定向ip包的目的地址，可以实现 ping flood

实验结果:
+ 数据包大于1490，将无法突破局域网
+ 杀伤力极低，只有O(n)， 且常系数k小于1
+ 目前没有发现任何价值，单纯造成网络流量阻塞不如udpflood

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