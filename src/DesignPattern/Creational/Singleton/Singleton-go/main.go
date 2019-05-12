package main

import (
	"./db"
)

func main() {
	ins1 := db.GetInstance()
	ins2 := db.GetInstance()

	ins1.Ping()

	if ins1 != ins2 {
		panic("instance is not equal")
	}
}
