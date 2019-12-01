package lexicographic

import "testing"

func TestCreateList(t *testing.T) {
	for i, v := range createList(10) {
		if v != i+1 {
			t.Fail()
		}
	}
}

func TestPermute(t *testing.T) {
	var data = Permute(3)
	for i := 0; i < len(data)-1; i++ {
		if data[i] >= data[i+1] {
			t.Fail()
		}
	}
}

func BenchmarkPermute(b *testing.B) {
	for i := 0; i < b.N; i++ {
		Permute(5)
	}
}
