package main

import (
	"net"

	"./concurrent"
)

func makeIP() []*net.IPAddr {
	var result []*net.IPAddr
	ip, _ := net.ResolveIPAddr("ip", "123.125.114.144")
	for i := 0; i < 1000; i++ {
		result = append(result, ip)
	}
	return result
}

func main() {
	ipAddrs := makeIP()

	app := concurrent.New()
	app.Dispatch(ipAddrs)

	concurrent.WG.Wait()
}
