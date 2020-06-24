package leetcode

func subtractProductAndSum(n int) int {
	var p, s int
	nums := getNums(n)
	for i := 0; i < len(nums); i++ {
		s += nums[i]
		p *= nums[i]
	}
	return p - s
}

func getNums(n int) []int {
	var result []int
	for n != 0 {
		result = append(result, n%10)
		n /= 10
	}
	return result
}
