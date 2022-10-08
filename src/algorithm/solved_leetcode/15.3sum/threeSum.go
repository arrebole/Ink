package leetcode

import "sort"

func threeSum(nums []int) [][]int {
	var result [][]int
	sort.Ints(nums)

	for i, v := range nums {
		// 去除重复元素
		if i > 0 && v == nums[i-1] {
			continue
		}
		lo, hi := i+1, len(nums)-1
		for lo < hi {
			if (nums[lo] + nums[hi] + v) == 0 {
				result = append(result, []int{v, nums[lo], nums[hi]})
				// 重复元素
				for lo < hi && nums[lo] == nums[lo+1] {
					lo++
				}
				for lo < hi && nums[hi] == nums[hi-1] {
					hi--
				}
				lo++
				hi--
			} else if (nums[lo] + nums[hi] + v) > 0 {
				hi--
			} else if (nums[lo] + nums[hi] + v) < 0 {
				lo++
			}
		}
	}
	return result
}
