package util

import (
	"net"
)

// GetDistIP 获取参数中的host， 解析目标ip: host -> ip
func GetDistIP(host string) *net.IPAddr {
	ip, err := net.ResolveIPAddr("ip", host)
	if err != nil {
		panic("fail ResolveIPAddr!")
	}
	return ip
}
