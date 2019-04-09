package main

import "./widget"

func main() {

	client1 := widget.New(&widget.LinuxFactory{})
	client1.Draw()

	client2 := widget.New(&widget.WindowsFactory{})
	client2.Draw()
}
