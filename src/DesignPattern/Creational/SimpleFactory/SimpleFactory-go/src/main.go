package main

import (
	"./color"
)

func testColorFatory(){
	color.CreateColor("red").PrintColor()
	color.CreateColor("black").PrintColor()
}

func main(){
	testColorFatory()
}