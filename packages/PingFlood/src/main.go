package main

import (
	"flag"
	"time"

	"./ping"
	"./util"
)

var (
	host   string
	worker int
	//size   int
)

func init() {
	flag.IntVar(&worker, "w", 1, "启用线程数")
	flag.StringVar(&host, "host", "www.baidu.com", "ping dist host")
	//flag.IntVar(&size, "size", 980, "数据包大小")
	flag.Parse()
}

func main() {
	ip := util.GetDistIP(host)
	// 启用并发socket数量
	for i := 0; i < worker; i++ {
		go ping.New(ip).Send()
	}
	time.Sleep(time.Second * 200)
}
