package main

// Flyweight ...
type Flyweight interface {
	GetValue() string
}

// ConcreteFlyweight ...
type ConcreteFlyweight struct {
	value string
}

// GetValue ...
func (p *ConcreteFlyweight) GetValue() string {
	return p.value
}

// FlyweightFactory ...
type FlyweightFactory struct {
	pool map[int]Flyweight
}

// GetFlyweight ...
func (p *FlyweightFactory) GetFlyweight(key int) Flyweight {
	value, ok := p.pool[key]
	if !ok {
		value = &ConcreteFlyweight{value: string(key)}
		p.pool[key] = value
		return value
	}
	return value
}

// NewWeightFactory ...
func NewWeightFactory() *FlyweightFactory {
	return &FlyweightFactory{
		pool: make(map[int]Flyweight),
	}
}
