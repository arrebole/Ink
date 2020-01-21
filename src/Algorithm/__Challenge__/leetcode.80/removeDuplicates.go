package leetcode

func removeDuplicates(nums []int) int {
	var p = 2
	for i := 2; i < len(nums); i++ {
		if nums[p-2] != nums[i] {
			nums[p] = nums[i]
			p++
		}
	}
	return p
}
