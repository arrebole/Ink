package reverse

import "testing"

func TestReverse(t *testing.T) {
	var data = []int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
	data = Reverse(data)

	for i, v := range data {
		if v != 11-i {
			t.Fail()
		}
	}
}
