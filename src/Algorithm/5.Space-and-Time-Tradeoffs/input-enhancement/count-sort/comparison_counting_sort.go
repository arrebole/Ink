package countsort

// ComparisonCountingSort 比较计数排序
// 输入增强， 先算出列表中小于该元素的元素个数
func ComparisonCountingSort(a []int) []int {
	var result = make([]int, len(a))
	var count = Comparison(a)

	for i := 0; i < len(a); i++ {
		result[count[i]] = a[i]
	}
	return result
}

// Comparison 算出一个列表，列表中小于该元素的个数
func Comparison(a []int) []int {
	var result = make([]int, len(a))
	//计算小于该元素的元素个数
	for i := 0; i < len(a)-1; i++ {
		for j := i + 1; j < len(a); j++ {
			if a[i] < a[j] {
				result[j]++
			} else {
				result[i]++
			}
		}
	}
	return result
}
