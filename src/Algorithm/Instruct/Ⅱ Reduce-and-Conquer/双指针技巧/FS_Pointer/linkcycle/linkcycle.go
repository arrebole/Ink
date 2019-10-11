package linkcycle

// Node 链表节点
type Node struct {
	Value int
	Next  *Node
}

// HasCycle 判断链表是否有环路
func HasCycle(root *Node) bool {
	var slow, fast = root, root

	for fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			return true
		}
	}
	return false
}
