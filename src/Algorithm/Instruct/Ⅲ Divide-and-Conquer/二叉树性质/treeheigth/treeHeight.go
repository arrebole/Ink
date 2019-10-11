package treeheight

// BTNode 二叉树节点
type BTNode struct {
	Parent *BTNode
	Left   *BTNode
	Right  *BTNode
}

// TreeHeight 分治法计算二叉树的高度
func TreeHeight(root *BTNode) int {
	if root == nil {
		return -1
	}

	return Max(TreeHeight(root.Right), TreeHeight(root.Left)) + 1
}

// Max 返回最大值
func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
