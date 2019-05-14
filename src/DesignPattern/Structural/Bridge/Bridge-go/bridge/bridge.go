package bridge

// Abstraction ...
type Abstraction interface {
	GetInfo() string
}

// Implementor ...
type Implementor interface {
	GetName() string
	GetPrice() string
}

// RefindAbstraction ...
type RefindAbstraction struct {
	impl Implementor
}

// GetInfo ...
func (p *RefindAbstraction) GetInfo() string {
	return p.impl.GetName() + p.impl.GetPrice()
}

//--------------------------------------------

// ConcreteAImplementor ...
type ConcreteAImplementor struct{}

// GetName ...
func (p *ConcreteAImplementor) GetName() string {
	return "Concurrent"
}

// GetPrice ...
func (p *ConcreteAImplementor) GetPrice() string {
	return ":100$"
}

// ConcreteBImplementor ...
type ConcreteBImplementor struct{}

// GetName ...
func (p *ConcreteBImplementor) GetName() string {
	return "XXXX"
}

// GetPrice ...
func (p *ConcreteBImplementor) GetPrice() string {
	return ":100000$"
}

//--------------------------------------------------------

// NewAbstractionA ...
func NewAbstractionA() Abstraction {
	return &RefindAbstraction{
		impl: &ConcreteAImplementor{},
	}
}

// NewAbstractionB ...
func NewAbstractionB() Abstraction {
	return &RefindAbstraction{
		impl: &ConcreteBImplementor{},
	}
}
