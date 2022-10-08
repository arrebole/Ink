package leetcode

func subsets(nums []int) [][]int {
	result := [][]int{{}}
	for _, v1 := range nums {
		for _, v2 := range result {
			result = append(result, append(append([]int{}, v2...), v1))
		}
	}
	return result
}
