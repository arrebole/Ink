package main

import (
	"./tea"
)

func testCreator(f tea.Creator) {
	f.CreateTea().GetInfo()
}

func main() {
	testCreator(&tea.MilkTeaCreator{})
}
