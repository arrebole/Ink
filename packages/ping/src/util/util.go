package util

import (
	"flag"
	"net"
)

// ParseArg 获取命令行参数
// Samples: ping.exe -host www.bilibili.com
func ParseArg() string {
	host := flag.String("host", "www.baidu.com", "ping dist host")
	flag.Parse()
	return *host
}

// GetDistIP 获取参数中的host， 解析目标ip: host -> ip
func GetDistIP() *net.IPAddr {
	ip, err := net.ResolveIPAddr("ip", ParseArg())
	if err != nil {
		panic("fail ResolveIPAddr!")
	}
	return ip
}
