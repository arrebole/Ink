package widget

import "fmt"

type button interface {
	drawButton()
}

type menu interface {
	drawMenu()
}

//---------------------------------------------
type linuxButton struct{}

func (p *linuxButton) drawButton() {
	fmt.Println("draw LinuxButton")
}

type linuxMenu struct{}

func (p *linuxMenu) drawMenu() {
	fmt.Println("draw linuxMenu")
}

type windowsButton struct{}

func (p *windowsButton) drawButton() {
	fmt.Println("draw windowsButton")
}

type windowsMenu struct{}

func (p *windowsMenu) drawMenu() {
	fmt.Println("draw windowsMenu")
}

//-----------------------------------------
type factory interface {
	createButton() button
	createMenu() menu
}

type LinuxFactory struct{}

func (p *LinuxFactory) createButton() button {
	return &linuxButton{}
}

func (p *LinuxFactory) createMenu() menu {
	return &linuxMenu{}
}

type WindowsFactory struct{}

func (p *WindowsFactory) createButton() button {
	return &windowsButton{}
}

func (p *WindowsFactory) createMenu() menu {
	return &windowsMenu{}
}

//-------------------------------------------

type Client struct {
	myButton button
	myMenu   menu
}

func (p *Client) Draw() {
	p.myButton.drawButton()
	p.myMenu.drawMenu()
}

func New(f factory) *Client {

	return &Client{
		myButton: f.createButton(),
		myMenu:   f.createMenu(),
	}
}
