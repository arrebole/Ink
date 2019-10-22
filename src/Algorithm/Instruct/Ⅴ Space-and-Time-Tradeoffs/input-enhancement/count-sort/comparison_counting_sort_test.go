package countsort

import (
	"math/rand"
	"testing"
	"time"
)

func TestComparisonCountingSort(t *testing.T) {
	var data = make([]int, 1000)
	rand.Seed(time.Now().Unix())
	for i := 0; i < len(data); i++ {
		data[i] = rand.Intn(10000)
	}

	r := ComparisonCountingSort(data)
	for i := 0; i < len(r)-1; i++ {
		if r[i] > r[i+1] {
			t.Fail()
		}
	}
}
