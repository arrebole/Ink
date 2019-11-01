package coinrow

// CoinRow 选择非相邻硬币，币值最大化
// 包含最后一个硬币f(n-2), 不包含最后硬币f(n-1)
func CoinRow(c []int) int {
	opt := make([]int, len(c))
	// opt[0]和opt[1] 为递归时的出口
	opt[0], opt[1] = c[0], max(c[0], c[1])
	for i := 2; i < len(c); i++ {
		// 如果选择c[i]则 f(n) = c[i] + f(n-2)
		// 不选择则 f(n) = f(n-1)
		// 选择两种情况的最大情况
		opt[i] = max(opt[i-2]+c[i], opt[i])
	}
	return opt[len(c)-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
