package leetcode

import (
	"sort"
)

func combinationSum(candidates []int, target int) [][]int {
	var result [][]int
	sort.Ints(candidates)
	backtrack(&result, candidates, []int{}, 0, target)
	return result
}

func backtrack(out *[][]int, candidates, curr []int, i, target int) {
	if target == 0 {
		*out = append(*out, append([]int{}, curr...))
		return
	}

	for j := i; j < len(candidates); j++ {
		if (target - candidates[j]) >= 0 {
			backtrack(out, candidates, append(curr, candidates[j]), j, target-candidates[j])
		}
	}
}
