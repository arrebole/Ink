package main

import (
	"fmt"

	"./bridge"
)

func main() {
	var bridger1 = bridge.NewAbstractionA()
	fmt.Printf("%s\n", bridger1.GetInfo())

	var bridger2 = bridge.NewAbstractionB()
	fmt.Printf("%s\n", bridger2.GetInfo())
}
