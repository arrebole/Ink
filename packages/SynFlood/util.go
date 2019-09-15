package main

import (
	"fmt"
	"strconv"
	"strings"
	"net"
	"./tcp"
	
)

// local  为本地ip remote 为对方ip
// source 为本地端口 dest为对方端口
func makeTcpHeader(local, remote string, source, dest uint16) []byte {
	r := &tcp.TCPHeader{
		Source:      source,
		Destination: dest,
		SeqNum:      25,
		AckNum:      0,
		DataOffset:  0, 	   
		Reserved:    0, 	   
		ECN:		 0,
		Ctrl:        tcp.SYN,  
		Window:      0xaaaa,	// 响应数据大小限制
		Checksum:    0,         // Kernel will set this if it's 0
		Urgent:      99,
	}

    r.Checksum = tcp.Csum(r.Marshal(), to4byte(local), to4byte(remote))
	
	fmt.Println("[build]",r.String())
	return r.Marshal()
}

// func addrToSource(addr string) uint16 {
// 	source := strings.Split(addr, ":")
// 	return  stringToUint16(source[1]) 
// }
func to4byte(s string) [4]byte {
	var result [4]byte
	source := strings.Split(s, ".")
	for i := 0; i < 4; i++{
		u, err := strconv.Atoi(source[i])
		if err != nil{
			panic("[to4byte]" + err.Error())
		}
		result[i] = byte(u)
	}
	return result
}

func stringToUint16(s string) uint16 {
	u, err := strconv.Atoi(s)
	if err != nil{
		panic("[stringToUint16]" + err.Error())
	}

	return  uint16(u) 
}

func printTCP(tcpData []byte){
	tcpheader := tcp.NewTCPHeader(tcpData[20:])
	fmt.Println("[recv]", tcpheader)
	fmt.Printf("\n\n")
	fmt.Println(len(tcpData),tcpData)
}

// GetDistIP 获取参数中的host， 解析目标ip: host -> ip
func ipAddr(host string) *net.IPAddr {
	ip, err := net.ResolveIPAddr("ip", host)
	if err != nil {
		panic("fail ResolveIPAddr!")
	}
	return ip
}

func getPulicIP() string {
    conn, _ := net.Dial("udp", "8.8.8.8:80")
    defer conn.Close()
    localAddr := conn.LocalAddr().String()
    idx := strings.LastIndex(localAddr, ":")
    return localAddr[0:idx]
}