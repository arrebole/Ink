package adapter

import "strings"

// Target 适配的目标接口
type Target interface {
	Request() string
}

// Adaptee 需要被适配的接口
type Adaptee interface {
	SpecificRequest() string
}

// AdapteeImp ...
type AdapteeImp struct{}

// SpecificRequest ...
func (p *AdapteeImp) SpecificRequest() string {
	return "3s"
}

// Adapter 适配器
type Adapter struct {
	pAdaptee Adaptee
}

// Request ...
func (p *Adapter) Request() string {
	var s = p.pAdaptee.SpecificRequest()
	return strings.Replace(s, "s", "m", 1)
}

// NewAdapter ...
func NewAdapter(p Adaptee) Target {
	return &Adapter{
		pAdaptee: p,
	}
}
