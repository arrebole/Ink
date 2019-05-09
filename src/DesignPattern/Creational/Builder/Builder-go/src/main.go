package main

import (
	"./message"
)

func testBulder(builder message.IBuilder) {
	var director = message.NewDirector(builder)
	var message = director.Construct()
	message.Print()
}

func main() {
	testBulder(&message.DefaultMessageBuild{})
}
