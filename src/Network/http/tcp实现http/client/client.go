package main

import (
	"fmt"
	"net"
)

func conn(url string) net.Conn {
	client, err := net.Dial("tcp", url)
	if err != nil {
		panic("comm error")
	}
	return client
}

func recv(conn net.Conn) []byte {
	var result = make([]byte, 1024)
	conn.Read(result)
	return result
}

func main() {
	client := conn("127.0.0.1:8080")
	client.Write([]byte("GET /hello HTTP/1.1\r\nHost: 127.0.0.1:8080\r\n\r\n"))
	fmt.Println(string(recv(client)))
}
