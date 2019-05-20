package main

import "fmt"

// IFacade ...
type IFacade interface {
	Close()
}

// Facade ...
type Facade struct {
	_door *door
}

// Close ...
func (p *Facade) Close() {
	p._door.closeDoor()
}

// 子系统 door
type door struct {
}

func (p *door) closeDoor() {
	fmt.Println("close door")
}

// NewFacade ...
func NewFacade() IFacade {
	return &Facade{
		_door: &door{},
	}
}
