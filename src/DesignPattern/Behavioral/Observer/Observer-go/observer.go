package main

import "fmt"

type observer interface {
	Update()
}

// ConcreteObserver ...
type ConcreteObserver struct {
	subject       *Subuject
	observerState int
}

// Update ...
func (p *ConcreteObserver) Update() {
	if p.observerState != p.subject.GetState() {
		fmt.Println("变化了")
	}
	p.observerState = p.subject.GetState()
}

// Subuject ...
type Subuject struct {
	observers []observer
	data      int
}

// Attact ...
func (p *Subuject) Attact(obs observer) {
	p.observers = append(p.observers, obs)
}

// SetState ...
func (p *Subuject) SetState(state int) {
	p.data = state
	p.Notify()
}

// GetState ...
func (p *Subuject) GetState() int {
	return p.data
}

// Notify ...
func (p *Subuject) Notify() {
	for _, v := range p.observers {
		v.Update()
	}

}
