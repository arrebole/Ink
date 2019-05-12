package prototype

// Cloneable ...
type Cloneable interface {
	Clone() Cloneable
	GetName() string
}

// Manager 原型管理器
type Manager struct {
	prototypes map[string]Cloneable
}

// Set 注册原型
func (p *Manager) Set(key string, val Cloneable) {
	p.prototypes[key] = val
}

// Get 获取原型
func (p *Manager) Get(key string) Cloneable {
	return p.prototypes[key]
}

// NewManager ...
func NewManager() *Manager {
	return &Manager{
		prototypes: make(map[string]Cloneable),
	}
}
