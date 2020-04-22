package linkcycle

import "testing"

func TestHasCycle(t *testing.T) {
	var root = &Node{Value: 10}
	var local = root
	for i := 0; i < 300; i++ {
		local.Next = &Node{Value: i}
		local = local.Next
	}
	local.Next = root

	if !HasCycle(root) {
		t.Fail()
	}
}
