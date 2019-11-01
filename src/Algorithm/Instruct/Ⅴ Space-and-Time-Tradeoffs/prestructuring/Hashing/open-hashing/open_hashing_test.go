package openhashing

import "testing"

func TestAdd(t *testing.T) {
	table := New()
	table.Set("xxx", 99)
	table.Set("111", 9)
	table.Set("111", 100)
	if v, _ := table.Get("xxx"); v != 99 {
		t.Fail()
	}
	if v, _ := table.Get("111"); v != 100 {
		t.Fail()
	}
}
