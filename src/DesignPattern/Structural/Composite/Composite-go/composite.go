package main

import "fmt"

// Component ...
type Component interface {
	PrintInfo()
	Increase(n int)
	Add(comp Component)
}

// Composite ...
type Composite struct {
	data       int
	components []Component
}

// Add ...
func (p *Composite) Add(comp Component) {
	p.components = append(p.components, comp)
}

// PrintInfo ...
func (p *Composite) PrintInfo() {
	fmt.Printf("Componsite %d\n", p.data)
	for _, item := range p.components {
		item.PrintInfo()
	}
}

// Increase ...
func (p *Composite) Increase(n int) {
	p.data += n
	for _, item := range p.components {
		item.Increase(n)
	}
}

// Leaf ...
type Leaf struct {
	data int
}

// Add ...
func (p *Leaf) Add(comp Component) {
	panic("Leaf not add\n")
}

// PrintInfo ...
func (p *Leaf) PrintInfo() {
	fmt.Printf("Leaf %d\n", p.data)
}

// Increase ...
func (p *Leaf) Increase(n int) {
	p.data += n
}
