package main

import (
	"flag"
	//"fmt"
	"time"
	"syscall"
)

var(
	inputThread int
	inputDesHost string
	inputDesPort string
)

func init(){
	flag.IntVar(&inputThread, "w", 1, "Thread number")
	flag.StringVar(&inputDesHost, "host", "127.0.0.2", "dist host")
	flag.StringVar(&inputDesPort, "port", "80", "Dist port")
	flag.Parse()
}


func main() {

	//go listen(inputDesHost)
	//time.Sleep(time.Second * 1)

	// 1、构建原始socket
	// AF_INET: ip头和以太头由内核维护，我们只能操作读取，ip头之上的数据
	// IPPROTO_TCP: 由内核维护的ip头，服务类型指定为TCP
	// ip层没有端口，端口信息在tcp层
	fd, err := syscall.Socket(syscall.AF_INET, syscall.SOCK_RAW, syscall.IPPROTO_TCP)
	if err != nil {
		panic("[net.Dial] " + err.Error())
	}

	// 2、构建 tcp数据包 = ip header + udp header
	// 由于ip头设置由内核维护，所以只需要构建tcp头
	local := getPulicIP()
	remote := inputDesHost
	source := stringToUint16("4396")
	dest := stringToUint16(inputDesPort)

	payload := makeTcpHeader(local,remote, source, dest)
	
	// 3、发送数据包
	// ip头由内核构建，所以需要指定需要传输的ip地址
	err = syscall.Sendto(fd, payload, 0, &syscall.SockaddrInet4{
        Port: 0,
        Addr: to4byte(remote),
	})
	
	if err != nil {
		panic("[conn.Write] " + err.Error())
	}

	// 4、接收返回的数据
	buff := make([]byte, 1024)
	byteLen, err := syscall.Read(fd, buff)
	if err != nil || byteLen == 0 {
		panic("[conn.Read] " + err.Error())
	}

	// 5、输出返回信息
	printTCP(buff)

	time.Sleep(time.Second * 3)
}