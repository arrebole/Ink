package color

import "fmt"

type Color interface {
	PrintColor()
}

type Red struct{}

func (p *Red) PrintColor() {
	fmt.Println("red")
}


type Black struct{}

func (p *Black) PrintColor() {
	fmt.Println("black")
}

// 设计模式：创建型-简单工厂
// 算法：——
// 复杂度：——
func CreateColor(arg string) Color {
	switch arg {
	case "red":
		return &Red{}
	case "black":
		return &Black{}
	}

	return nil
}


