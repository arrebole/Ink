package coincollection

// RobotCoinCollection 😈暴力法解硬币收集问题
// 方格位置 (i, j)
func RobotCoinCollection(c [][]int, i, j, s int) int {
	if i == 0 && j == 0 {
		return s
	}

	temp := 0
	if j > 0 {
		temp = max(RobotCoinCollection(c, i, j-1, s), temp)
	}
	if i > 0 {
		temp = max(RobotCoinCollection(c, i-1, j, s), temp)
	}
	return temp + c[i][j]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// DPRobotCoinCollection 动态规划解决硬币收集问题
func DPRobotCoinCollection(c [][]int) int {
	f := createMatrix(len(c), len(c[0]))

	f[0][0] = c[0][0]
	for i := 1; i < len(c[0]); i++ {
		f[0][i] = f[0][i-1] + c[0][i]
	}

	for i := 1; i < len(c); i++ {
		f[i][1] = f[i-1][1] + c[i][1]
		for j := 1; j < len(c[0]); j++ {
			// 取上方和右边的最大值
			f[i][j] = max(f[i-1][j], f[i][j-1]) + c[i][j]
		}
	}
	return f[len(c)-1][len(c[0])-1]
}

func createMatrix(i, j int) [][]int {
	result := make([][]int, i)
	for k := 0; k < i; k++ {
		result[k] = make([]int, j)
	}
	return result
}
