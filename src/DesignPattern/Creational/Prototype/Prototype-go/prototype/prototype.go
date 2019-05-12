package prototype

// Product ..
type Product struct {
	Name string
}

// Clone ...
func (p *Product) Clone() Cloneable {
	return &Product{
		Name: p.Name,
	}
}

// GetName ...
func (p *Product) GetName() string {
	return p.Name
}
