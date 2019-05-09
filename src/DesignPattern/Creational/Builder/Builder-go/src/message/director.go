package message

// Director ...
type Director struct {
	builder IBuilder
}

// Construct ...
func (p *Director) Construct() *Message {
	p.builder.CreateMessage()
	p.builder.BuildCreateDate()
	p.builder.BuildData()
	return p.builder.GetResult()
}

// NewDirector ...
func NewDirector(builder IBuilder) *Director {
	return &Director{
		builder: builder,
	}
}
