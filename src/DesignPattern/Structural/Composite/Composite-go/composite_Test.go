package main

// TestComponsite ...
func TestComponsite() {
	var root Component = &Composite{data: 0}
	root.Add(&Leaf{data: 12})
	root.Add(&Leaf{data: 16})
	var comp = &Composite{data: 99}
	comp.Add(&Leaf{data: 55})
	root.Add(comp)

	root.PrintInfo()
	root.Increase(10)
	root.PrintInfo()
}

func main() {
	TestComponsite()
}
