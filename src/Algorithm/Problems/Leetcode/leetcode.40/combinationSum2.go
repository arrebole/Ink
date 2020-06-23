package leetcode

import "sort"

// combinationSum2 组合总和 II
// expolite 回溯； T(n) = O(N*logN)
func combinationSum2(candidates []int, target int) [][]int {
	var result [][]int
	var combin func([]int, int, int)

	sort.Ints(candidates)
	combin = func(curr []int, i, sum int) {
		if sum == 0 {
			result = append(result, append([]int{}, curr...))
			return
		}
		for j := i; j < len(candidates); j++ {
			//可以让同一层级，不出现相同的元素。但是却允许了不同层级之间的重复
			if j > i && candidates[j] == candidates[i-1] {
				continue
			}
			if (sum - candidates[j]) >= 0 {
				combin(append(curr, candidates[j]), j, sum-candidates[j])

			}
		}
	}
	combin([]int{}, 0, target)
	return result
}
