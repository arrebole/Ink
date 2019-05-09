package main

import "./widget"

// 抽象工厂客户端
// 仅使用由 AbstractFactory 和 AbstractProduct类声明的接口

func client(f widget.Factory) {
	f.CreateButton().DrawButton()
	f.CreateMenu().DrawMenu()
}

func main() {
	client(&widget.LinuxFactory{})
	client(&widget.WindowsFactory{})
}
