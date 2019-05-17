package main

func main() {
	var core Component = &Core{}
	var product Component = &Decorator{core: core}
	product.Warpper()
}
