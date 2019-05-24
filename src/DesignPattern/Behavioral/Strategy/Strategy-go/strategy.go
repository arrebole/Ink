package main

import "os"

type strategy interface {
	TouchFile()
}

type touchTxtFile struct{}

func (p *touchTxtFile) TouchFile() {
	file, err := os.Create("a.txt")
	if err != nil {
		panic("err")
	}
	file.WriteString(">>>>>>")
	file.Close()
}

// FileManage ...
type FileManage struct {
	_strategy strategy
}

func (p *FileManage) create() {
	p._strategy.TouchFile()
}

// NewTxtFileNanage ...
func NewTxtFileNanage() *FileManage {
	return &FileManage{
		_strategy: &touchTxtFile{},
	}
}
