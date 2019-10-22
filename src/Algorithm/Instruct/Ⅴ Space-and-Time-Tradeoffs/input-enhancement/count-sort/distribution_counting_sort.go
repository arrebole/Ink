package countsort

// DistributionCountingSort 分布计数排序
// 适用于排序连续的具有上下界的数组 l,u 为数组元素的上下界
func DistributionCountingSort(a []int, l, u int) []int {
	var result = make([]int, len(a))

	// 计算频率
	d := frequency(a, l, u)
	d = distributed(d, l, u)

	for i := len(a) - 1; i >= 0; i-- {
		j := a[i] - l
		result[d[j]-1] = a[i]
		d[j] = d[j] - 1
	}
	return result
}

func frequency(a []int, l, u int) []int {
	var result = make([]int, u-l+1)
	for i := 0; i < len(a); i++ {
		result[a[i]-l]++
	}
	return result
}

func distributed(a []int, l, u int) []int {
	for i := 1; i < u-l+1; i++ {
		a[i] = a[i-1] + a[i]
	}
	return a
}
