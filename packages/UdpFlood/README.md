# 构造TCP数据包实现SynFlood攻击

> 所属: Dos -> Flood -> UDP -> UdpFlood

udp定向流量，暴力发送数据无视对方是否接受，以拥塞网络为目的

实验结果:
+ 不确定流量是否到达目的端口
+ 对服务器不具备杀伤性，以造成网络拥挤为目的，阻碍其他访问者 
+ 需要大量的流量，但是一旦超越了对方宽带瓶颈，将是必杀的。
+ 杀伤力 只有O(n) 存在最大值，为对方带宽

## How to use?
```bash
go build
```
```bash
# w 指定线程数量
UdpFlood.exe -host www.futanaicha.club -port 443 -w 3
```
