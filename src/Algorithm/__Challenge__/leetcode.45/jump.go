package leetcode

// jump
// expolit 贪心算法 计算第 i 跳所能到达的最远位置，如果大于数组长度，则返回 i
func jump(nums []int) int {
	var (
		count    = 0
		step     = 0
		position = 0
	)

	for position < len(nums)-1 {
		var maxPosition = 0
		for i := position + 1; i <= position+nums[position]; i++ {
			if (position + nums[i]) > maxPosition {
				maxPosition = position + nums[i]
				step = i - position
			}
		}
		position = position + step
		count++
	}

	return count
}
