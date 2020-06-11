package leetcode

import "sort"

// ListNode ...
type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeKLists(lists []*ListNode) *ListNode {
	return create(getVals(lists))
}

func getVals(lists []*ListNode) []int {
	result := []int{}
	for _, v := range lists {
		for v != nil {
			result = append(result, v.Val)
			v = v.Next
		}
	}
	sort.Ints(result)
	return result
}

func create(aux []int) *ListNode {
	if len(aux) == 0 {
		return nil
	}
	var result = &ListNode{Val: aux[0]}
	var head = result
	for i := 1; i < len(aux); i++ {
		head.Next = &ListNode{
			Val: aux[i],
		}
		head = head.Next
	}
	return result
}
