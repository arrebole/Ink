package traversal

import "fmt"

// BTNode 二叉树节点
type BTNode struct {
	Value  int
	Parent *BTNode
	Left   *BTNode
	Right  *BTNode
}

func preOrderTraversal(root *BTNode) {
	if root != nil {
		fmt.Println(root.Value)
		preOrderTraversal(root.Left)
		preOrderTraversal(root.Right)
	}
}

func inOrderTraversal(root *BTNode) {
	if root != nil {
		preOrderTraversal(root.Left)
		fmt.Println(root.Value)
		preOrderTraversal(root.Right)
	}
}

func postOrderTraversal(root *BTNode) {
	if root != nil {
		preOrderTraversal(root.Left)
		preOrderTraversal(root.Right)
		fmt.Println(root.Value)
	}
}
