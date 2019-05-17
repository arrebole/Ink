package main

import "fmt"

// Component ...
type Component interface {
	Warpper() int
}

// Core ...
type Core struct{}

// Warpper ...
func (p *Core) Warpper() int {
	base := 200
	fmt.Printf("基础价格 %d\n", base)
	return base
}

// Decorator ...
type Decorator struct {
	core Component // 维持一个指向Component对象的指针
}

// Warpper ...
func (p *Decorator) Warpper() int {
	add := 100
	fmt.Printf("增加包装 +%d\n", add)
	return add + p.core.Warpper()
}
