package changemaking

// ChangeMaking 暴力法求解找零问题
// f(n)为最小硬币数量
// | f(0) = 0
// | f(n) = min{ f(n-dj) } + 1
func ChangeMaking(d []int, n int, k int) int {
	if n == 0 {
		return k
	}

	cache := []int{}
	for i := 0; i < len(d); i++ {
		if n-d[i] >= 0 {
			cache = append(cache, ChangeMaking(d, n-d[i], k))
		}
	}
	return min(cache...) + 1
}

func min(arg ...int) int {
	result := arg[0]
	for _, v := range arg {
		if v < result {
			result = v
		}
	}
	return result
}

// DPChangeMaking 动态规划求解找零问题
// f(n)为最小硬币数量
// | f(0) = 0
// | f(n) = min{ f(n-dj) } + 1
func DPChangeMaking(d []int, n int) int {
	opt := make([]int, n+1)
	opt[0] = 0

	for i := 1; i <= n; i++ {
		temp := 99999
		// i为表中的总价格，d[j-1] 单枚硬币的价格
		// opt[i-d[j-1]]: 子问题的答案,
		// 遍历子问题的答案与新加一枚硬币的组合
		for j := 1; j <= len(d) && i >= d[j-1]; j++ {
			temp = min(opt[i-d[j-1]], temp)
		}
		opt[i] = temp + 1
	}

	return opt[n]
}
