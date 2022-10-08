package treeheight

import "testing"

func TestTreeHeight(t *testing.T) {
	var root = &BTNode{}
	root.Left = &BTNode{}
	root.Right = &BTNode{}
	root.Left.Left = &BTNode{}
	root.Left.Left.Left = &BTNode{}

	if TreeHeight(root) != 3 {
		t.Fail()
	}
}
