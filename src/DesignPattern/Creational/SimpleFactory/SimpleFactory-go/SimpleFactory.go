package simplefactory

import "fmt"

type product interface {
	getColor()
}

// 设计模式：创建型-简单工厂
// 算法：——
// 复杂度：——
func productFactory(arg string) product {
	switch arg {
	case "A":
		return &productA{}
	case "B":
		return &productB{}
	}
	return nil
}

type productA struct{}

func (p *productA) getColor() {
	fmt.Println("red")
}

type productB struct{}

func (p *productB) getColor() {
	fmt.Println("black")
}
