package lexicographic

// createList 输入n 输出[1,2..n]
func createList(n int) []int {
	var result = make([]int, n)
	for i := 0; i < n; i++ {
		result[i] = i + 1
	}
	return result
}

// aToInt 将数组转化为数字
// {1，2，3} -> 123
func aToInt(a []int) int {
	var result = 0
	for _, v := range a {
		result *= 10
		result += v
	}
	return result
}

// findMaxBigIndex 找到比n大的数的最大索引
func findMaxBigIndex(a []int, n int) int {
	var result = -1
	for i, v := range a {
		if v > n {
			result = i
		}
	}
	return result
}

// findMaxOrdered 寻找数组中最大升序
func findMaxOrdered(a []int) int {
	var result = -1
	for i := 0; i < len(a)-1; i++ {
		if a[i] < a[i+1] {
			result = i
		}
	}
	return result
}

func recover(a []int, lo, hi int) {
	for lo < hi {
		a[lo], a[hi] = a[hi], a[lo]
		lo++
		hi--
	}
}

// Permute 生成字典序排列
func Permute(n int) []int {
	var result = []int{}
	var aux = createList(n)

	for {
		// 将排列添加到结果
		result = append(result, aToInt(aux))

		// 找到最大升序元素 aux[i] < aux[i+1]
		i := findMaxOrdered(aux)
		if i == -1 {
			break
		}
		// 找到最大索引j使得 aux[i] < aux[j]
		j := findMaxBigIndex(aux, aux[i])
		// 交换 a[i],a[j]
		aux[i], aux[j] = aux[j], aux[i]
		// 反转 aux[i+1...n]
		recover(aux, i+1, n-1)
	}
	return result
}
