package main

import "fmt"

// AbstractClass ...
type AbstractClass interface {
	TemplateMethod()
}

// ConcreteClass ..
type ConcreteClass struct {
	step2 func()
}

// TemplateMethod ...
func (p *ConcreteClass) TemplateMethod() {
	p.step1()
	p.step2()
	p.step3()
}

func (p *ConcreteClass) step1() {
	fmt.Println("step 1 ...")
}

func (p *ConcreteClass) step3() {
	fmt.Println("step 3 ...")
}

// NewTemplateMethod ...
func NewTemplateMethod(f func()) AbstractClass {
	return &ConcreteClass{
		step2: f,
	}
}
