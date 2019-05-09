package tea

import "fmt"

type Tea interface {
	GetInfo()
}

type Creator interface {
	CreateTea() Tea
}

type milkTea struct{}

func (p *milkTea) GetInfo() {
	fmt.Printf("i am milkTea\n")
}

type MilkTeaCreator struct{}

func (p *MilkTeaCreator) CreateTea() Tea {
	return &milkTea{}
}
