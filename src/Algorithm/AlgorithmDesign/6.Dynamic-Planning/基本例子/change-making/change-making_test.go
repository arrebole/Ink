package changemaking

import "testing"

// TestChangeMaking 7.704s
func TestChangeMaking(t *testing.T) {
	d := []int{1, 3, 4, 10}
	if ChangeMaking(d, 39, 0) != 6 {
		t.Fail()
	}
}

// TestDPChangeMaking 0.168s
func TestDPChangeMaking(t *testing.T) {
	d := []int{1, 3, 4, 10}
	if DPChangeMaking(d, 39) != 6 {
		t.Fail()
	}
}
