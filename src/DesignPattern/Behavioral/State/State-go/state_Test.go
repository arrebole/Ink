package main

func main() {
	context := Context{current: &mkFileState{}}
	context.Exec()
	context.Exec()
}
