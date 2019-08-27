package main

import (
	"./ping"
	"./util"
)

func main() {
	ip := util.GetDistIP()
	ping.New(ip).Send()
}
