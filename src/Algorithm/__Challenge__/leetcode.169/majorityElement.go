package leetcode

func majorityElement(nums []int) int {
	var list = make(map[int]int)
	for _, value := range nums {
		list[value]++
	}
	return majority(list)
}

func majority(list map[int]int) int {
	count, result := 0, 0
	for key, val := range list {
		if val > count {
			count, result = val, key
		}
	}
	return result
}
