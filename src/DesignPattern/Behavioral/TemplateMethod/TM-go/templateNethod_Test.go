package main

import "fmt"

func main() {
	var fm = NewTemplateMethod(func() {
		fmt.Println("xxxxxxxxx")
	})
	fm.TemplateMethod()
}
