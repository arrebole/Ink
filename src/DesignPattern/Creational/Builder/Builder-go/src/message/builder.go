package message

import (
	"strconv"
	"time"
)

// IBuilder ...
type IBuilder interface {
	CreateMessage()
	BuildCreateDate()
	BuildData()
	GetResult() *Message
}

// DefaultMessageBuild ...
type DefaultMessageBuild struct {
	message *Message
}

// CreateMessage ...
func (p *DefaultMessageBuild) CreateMessage() {
	p.message = &Message{}
}

// BuildCreateDate ...
func (p *DefaultMessageBuild) BuildCreateDate() {
	p.message.CreateDate = strconv.Itoa(time.Now().Hour())
}

// BuildData ...
func (p *DefaultMessageBuild) BuildData() {
	p.message.Data = "default message"
}

// GetResult ...
func (p *DefaultMessageBuild) GetResult() *Message {
	return p.message
}
