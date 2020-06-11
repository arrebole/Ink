package leetcode

// TreeNode ...
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func minDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	return bfs(root)
}

func bfs(root *TreeNode) int {
	var result = 0
	var queue = []*TreeNode{root}
	for len(queue) != 0 {
		result++
		var newQueue []*TreeNode
		for _, v := range queue {
			if v.Left == nil && v.Right == nil {
				return result
			}
			if v.Left != nil {
				newQueue = append(newQueue, v.Left)
			}
			if v.Right != nil {
				newQueue = append(newQueue, v.Right)
			}
		}
		queue = newQueue
	}
	return result
}
