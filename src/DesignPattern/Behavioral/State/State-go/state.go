package main

import (
	"os"
)

// State ...
type State interface {
	Handle()
	Next() State
}

// Context ...
type Context struct {
	current State
}

// Exec ...
func (p *Context) Exec() {
	if p.current == nil {
		return
	}
	p.current.Handle()
	p.current = p.current.Next()
}

type mkFileState struct{}

func (p *mkFileState) Handle() {
	file, _ := os.Create("test.txt")
	file.Close()
}

func (p *mkFileState) Next() State {
	return &writeState{}
}

type writeState struct{}

func (p *writeState) Handle() {
	file, _ := os.OpenFile("./test.txt", os.O_WRONLY, 0777)
	file.WriteString("(￣y▽,￣)╭ ")
	file.Close()
}

func (p *writeState) Next() State {
	return nil
}
