package main

import (
	"fmt"
)

func selectionSort(arr []int) {
	length := len(arr)
	for i := 0; i < length-1; i++ {
		min := i
		for j := i + 1; j < length; j++ {
			if arr[min] > arr[j] {
				min, j = j, min
			}
		}
		arr[min], arr[i] = arr[i], arr[min]
	}
}

func main() {
	var a = [5]int{1, 0, 2, 4, 3}
	selectionSort(a[:])
	fmt.Println(a)
}
