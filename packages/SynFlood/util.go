package main

import (
	"fmt"
	"strings"
	"strconv"
	"./tcp"
)

func makeTcpHeader(source, dest uint16) []byte {
	r := &tcp.TCPHeader{
		Source:      source,
		Destination: dest,
		SeqNum:      1,
		AckNum:      0,
		DataOffset:  0, 	    // 4 bits
		Reserved:    0, 	    // 6 bits
		Ctrl:        tcp.SYN,  // 6 bits
		Window:      0xaaaa,
		Checksum:    0,         // Kernel will set this if it's 0
		Urgent:      99,
	}
	fmt.Println(r.String())
	return r.Marshal()
}

func addrToSource(addr string) uint16 {
	source := strings.Split(addr, ":")
	return  stringToUint16(source[1]) 
}

func stringToUint16(s string) uint16 {
	u, err := strconv.ParseUint(s, 10, 16)
	if err != nil{
		panic("[stringToUint16]" + err.Error())
	}

	return  uint16(u) 
}

func printTCP(tcpData []byte){
	fmt.Println(tcp.NewTCPHeader(tcpData).String())
}