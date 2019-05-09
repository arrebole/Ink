package widget

import "fmt"

type Button interface {
	DrawButton()
}

type Menu interface {
	DrawMenu()
}

//---------------------------------------------
type linuxButton struct{}

func (p *linuxButton) DrawButton() {
	fmt.Println("draw LinuxButton")
}

type linuxMenu struct{}

func (p *linuxMenu) DrawMenu() {
	fmt.Println("draw linuxMenu")
}

type windowsButton struct{}

func (p *windowsButton) DrawButton() {
	fmt.Println("draw windowsButton")
}

type windowsMenu struct{}

func (p *windowsMenu) DrawMenu() {
	fmt.Println("draw windowsMenu")
}

type Factory interface {
	CreateButton() Button
	CreateMenu() Menu
}

type LinuxFactory struct{}

func (p *LinuxFactory) CreateButton() Button {
	return &linuxButton{}
}

func (p *LinuxFactory) CreateMenu() Menu {
	return &linuxMenu{}
}

type WindowsFactory struct{}

func (p *WindowsFactory) CreateButton() Button {
	return &windowsButton{}
}

func (p *WindowsFactory) CreateMenu() Menu {
	return &windowsMenu{}
}
