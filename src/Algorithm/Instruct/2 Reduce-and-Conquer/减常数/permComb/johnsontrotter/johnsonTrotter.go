package johnsontrotter

type Perm struct {
	Result []int
}

func toInt(a []int) int {
	result := 0
	for _, v := range a {
		result *= 10
		result += v
	}
	return result
}

// Perm 全排列生成算法 [递归版本] 性能消耗较大
// 全排列生成算法 邻位对换法
func (p *Perm) Perm(a []int, lo int, hi int) {
	if lo == hi {
		p.Result = append(p.Result, toInt(a))
		return
	}
	for i := lo; i <= hi; i++ {
		a[lo], a[i] = a[i], a[lo]
		p.Perm(a, lo+1, hi)
		a[lo], a[i] = a[i], a[lo]
	}
}

//找到最大可移动项
func findMove(aux []int, direction []int) int {
	result := -1
	max := -1
	for i := range aux {
		j := i + direction[i]
		if j < 0 || j >= len(aux) {
			continue
		}
		if aux[i] > max && aux[j] < aux[i] {
			result = i
			max = aux[i]
		}
	}
	return result
}

//反转比移动项大的所有项的移动方向
func reverse(aux []int, d []int, k int) {
	max := aux[k]
	for i := range aux {
		if aux[i] > max {
			d[i] = d[i] * -1
		}
	}
}

// JohnsonTrotter 全排列生成算法 邻位对换法
func JohnsonTrotter(aux []int) []int {
	result := make([]int, 0)

	direc := make([]int, len(aux))
	for i := range direc {
		direc[i] = -1
	}

	for k := findMove(aux, direc); k != -1; k = findMove(aux, direc) {
		result = append(result, toInt(aux))

		// 交换
		t := direc[k] + k
		aux[t], aux[k] = aux[k], aux[t]
		direc[t], direc[k] = direc[k], direc[t]
		// 反转
		reverse(aux, direc, t)
	}
	return result
}
