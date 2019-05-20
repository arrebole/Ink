package main

import (
	"fmt"
	"os"
)

// Subject ...
type Subject interface {
	TouchFile(fileName string)
}

// Proxy ...
type Proxy struct {
	real Subject
}

// TouchFile ...
func (p Proxy) TouchFile(fileName string) {
	p.real.TouchFile(fileName)
	fmt.Println("完成...")
}

// realSubject ...
type realSubject struct{}

func (p realSubject) TouchFile(fileName string) {
	file, err := os.Create("./" + fileName)
	if err != nil {
		panic("无法创建文件")
	}
	file.WriteString("xxxxxxxxxx")
	file.Close()
}

// NewProxy ...
func NewProxy() Subject {
	return Proxy{
		real: realSubject{},
	}
}
