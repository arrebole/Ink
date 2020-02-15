package leetcode

func trailingZeroes(n int) int {
	var result = 0
	for n >= 5 {
		result += n % 5
		n /= 5
	}
	return result
}
