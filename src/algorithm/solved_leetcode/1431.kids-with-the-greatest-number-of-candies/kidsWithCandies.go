package leetcode

func findMaxValue(nums []int) int {
	if len(nums) <= 0 {
		panic("数组长度不足")
	}

	result := nums[0]
	for i := range nums{
		if nums[i] > result {
			result = nums[i]
		}
	}
	return result
}

func kidsWithCandies(candies []int, extraCandies int) []bool {
	result := make([]bool, len(candies))
	maxValue := findMaxValue(candies)
	for i := range candies {
		result[i] = candies[i] + extraCandies >= maxValue
	}
	return result
}