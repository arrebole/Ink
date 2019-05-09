package message

import (
	"fmt"
)

// Message is
type Message struct {
	CreateDate string
	Data       string
}

// Print is
func (p *Message) Print() {
	fmt.Printf("time: %s \ndata: %s", p.CreateDate, p.Data)
}
