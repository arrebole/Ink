package main

import (
	"./prototype"
)

func main() {
	// 原型管理器
	manage := prototype.NewManager()

	// 创建原型并注册
	myPrototype := &prototype.Product{
		Name: "xxx",
	}
	manage.Set("test", myPrototype)

	// 从原型管理器中取出 并克隆
	clonePrototype := manage.Get("test").Clone()

	println(myPrototype.GetName())
	println(clonePrototype.GetName())
	println(myPrototype == clonePrototype)
}
