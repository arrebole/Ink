package main

import (
	"flag"
	//"os"
	//"fmt"
	"syscall"
)

var(
	inputThread int
	inputDisHost string
	inputDisPort string
)

func init(){
	flag.IntVar(&inputThread, "w", 1, "Thread number")
	flag.StringVar(&inputDisHost, "host", "www.baidu.com", "dist host")
	flag.StringVar(&inputDisPort, "port", "80", "Dist port")
	flag.Parse()
}


func main() {

	// 1、构建原始socket
	// AF_INET: ip头和以太头由内核维护，我们只能操作读取，ip头之上的数据
	// IPPROTO_TCP: 由内核维护的ip头，服务类型指定为TCP
	// ip层没有端口，端口信息在tcp层
	fd, err := syscall.Socket(syscall.AF_INET, syscall.SOCK_RAW, syscall.IPPROTO_TCP)
	if err != nil {
		panic("[net.Dial] " + err.Error())
	}
	//file := os.NewFile(uintptr(fd), fmt.Sprintf("fd %d", fd))

	// 2、构建 tcp数据包 = ip header + udp header
	// 由于ip头设置由内核维护，所以只需要构建tcp头
	payload := makeTcpHeader(stringToUint16("80"), stringToUint16(inputDisPort))
	
	// 3、将数据包写入socket fd，发送数据包
	byteLen,err := syscall.Write(fd, payload)
	if err != nil {
		panic("[conn.Write] " + err.Error())
	}

	// 4、接收返回的数据
	buff := make([]byte, 1024)
	byteLen, err = syscall.Read(fd, buff)
	if err != nil || byteLen == 0{
		panic("[conn.Read] " + err.Error())
	}

	// 5、输出返回信息
	printTCP(buff)
}