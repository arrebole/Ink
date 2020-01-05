package leetcode

import "testing"

func TestMajorityElement(t *testing.T) {
	data := []int{3, 2, 3}
	if majorityElement(data) != 3 {
		t.Errorf("majorityElement [3,2,3] != 3")
	}

	data = []int{2, 2, 1, 1, 1, 2, 2}
	if majorityElement(data) != 2 {
		t.Errorf("majorityElement [2, 2, 1, 1, 1, 2, 2] != 2")
	}
}
