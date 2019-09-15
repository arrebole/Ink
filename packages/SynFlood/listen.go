package main

import(
    "net"
    "fmt"
	"./tcp"
)

// 监听网卡上，发送给127.0.0.1 的所有tcp数据包
func listen(){
	netaddr, _ := net.ResolveIPAddr("ip4", "127.0.0.2")
    conn, _ := net.ListenIP("ip4:tcp", netaddr)
    for {
        buf := make([]byte, 1480)
        n, addr, _ := conn.ReadFrom(buf)
        ycpheader := tcp.NewTCPHeader(buf[0:20])
        fmt.Printf("[recv] len=%d ip=%s %s %s\n", n, addr, ycpheader, string(buf[20:23]))
    }
}