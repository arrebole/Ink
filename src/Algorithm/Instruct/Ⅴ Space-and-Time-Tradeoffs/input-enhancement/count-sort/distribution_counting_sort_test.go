package countsort

import (
	"fmt"
	"testing"
)

func TestDistributionCountingSort(t *testing.T) {
	data := []int{12, 12, 13, 12, 11, 13, 15, 16, 18, 17, 17, 19, 10, 11}
	r := DistributionCountingSort(data, 10, 19)
	for i := 0; i < len(r)-1; i++ {
		if r[i] > r[i+1] {
			t.Log(i)
			t.Fail()
		}
	}
	fmt.Println(r)
}
