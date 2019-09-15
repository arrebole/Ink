package main

import (
	"fmt"
	"strconv"
	"net"
	"./tcp"
)

// local  为本地ip remote 为对方ip
// source 为本地端口 dest为对方端口
func makeTcpHeader(source, dest uint16) []byte {
	r := &tcp.TCPHeader{
		Source:      source,
		Destination: dest,
		SeqNum:      1,
		AckNum:      0,
		DataOffset:  5, 	   
		Reserved:    0, 	   
		ECN:		 0,
		Ctrl:        tcp.SYN,  
		Window:      0xaaaa,	// 响应数据大小限制
		Checksum:    0,         // Kernel will set this if it's 0
		Urgent:      99,
	}

    //r.Checksum = tcp.Csum(r.Marshal(), to4byte(local), to4byte(remote))
	
	fmt.Println("[build]",r.String())
	return r.Marshal()
}

// func addrToSource(addr string) uint16 {
// 	source := strings.Split(addr, ":")
// 	return  stringToUint16(source[1]) 
// }

func stringToUint16(s string) uint16 {
	u, err := strconv.Atoi(s)
	if err != nil{
		panic("[stringToUint16]" + err.Error())
	}

	return  uint16(u) 
}

func printTCP(tcpData []byte){
	fmt.Println("[recv]",tcp.NewTCPHeader(tcpData).String())
}

// GetDistIP 获取参数中的host， 解析目标ip: host -> ip
func ipAddr(host string) *net.IPAddr {
	ip, err := net.ResolveIPAddr("ip", host)
	if err != nil {
		panic("fail ResolveIPAddr!")
	}
	return ip
}