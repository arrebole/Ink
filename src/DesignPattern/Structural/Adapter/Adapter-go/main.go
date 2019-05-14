package main

import (
	"fmt"

	"./adapter"
)

func main() {
	// 需要适配的对象
	var adapteeImp = &adapter.AdapteeImp{}

	// 使用适配器进行适配
	var adapter = adapter.NewAdapter(adapteeImp)

	// 使用
	fmt.Printf("%s", adapter.Request())

}
