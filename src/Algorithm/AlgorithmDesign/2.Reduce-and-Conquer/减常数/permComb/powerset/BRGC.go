package powerset

// BRGC 二进制反射格雷姆码 生成幂集
func BRGC(n int) [][]byte {
	var list [][]byte
	if n == 1 {
		list = [][]byte{[]byte{0}, []byte{1}}
	} else {
		L1 := BRGC(n - 1)
		L2 := recoverCode(L1)

		L1 = shift(L1, byte(0))
		L2 = shift(L2, byte(1))

		list = append(L1, L2...)
	}
	return list
}

// shift 将n加到a的每一个位串前
func shift(a [][]byte, n byte) [][]byte {
	for i := 0; i < len(a); i++ {
		a[i] = append([]byte{n}, a[i]...)
	}
	return a
}

// recover 反转 a
func recoverCode(a [][]byte) [][]byte {
	var result = [][]byte{}
	// 深拷贝
	for i := range a {
		t := append([]byte{}, a[i]...)
		result = append(result, t)
	}
	// 反转
	i, j := 0, len(a)-1
	for i < j {
		result[i], result[j] = result[j], result[i]
		i++
		j--
	}
	return result
}
