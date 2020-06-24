package leetcode

// containsNearbyDuplicate  存在重复元素 II
// exploit 时空权衡, 滑动窗口，固定滑块窗口大小。
func containsNearbyDuplicate(nums []int, k int) bool {
	slice := make(map[int]int)
	for k, v := range nums {
		_, ok := slice[v]
		// 在散列表中搜索当前元素，如果找到了就返回 true。
		if ok {
			return true
		}
		// 在散列表中插入当前元素。
		slice[v] = k
		// 如果当前散列表的大小超过了 kk， 删除散列表中最旧的元素。
		if len(slice) > k {
			delete(slice, v)
		}
	}
	return false
}
