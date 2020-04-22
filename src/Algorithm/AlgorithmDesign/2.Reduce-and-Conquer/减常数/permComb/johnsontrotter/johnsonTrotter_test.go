package johnsonTrotter

import (
	"fmt"
	"testing"
)

func TestFindMove(T *testing.T) {
	var a = []int{3, 1, 2}
	var d = []int{-1, -1, -1}

	if findMove(a, d) != 2 {
		T.Fatal(findMove(a, d))
	}
}

func TestJohnsonTrotter(T *testing.T) {
	var a = []int{1, 2, 3}
	for _, v := range JohnsonTrotter(a) {
		fmt.Printf("%d ", v)
	}
}
