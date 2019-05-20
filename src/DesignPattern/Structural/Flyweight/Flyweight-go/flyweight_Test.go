package main

import "fmt"

func main() {
	f := NewWeightFactory()
	for i := 35; i <= 100; i++ {
		fmt.Printf("%s\n", f.GetFlyweight(i).GetValue())
	}
}
