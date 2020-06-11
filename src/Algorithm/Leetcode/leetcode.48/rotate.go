package leetcode

// rotate 矩阵旋转
// export 蛮力； T(n) = O(n); 对于旋转，可以翻折实现
func rotate(matrix [][]int) {
	// 1. 上下反转
	for i := 0; i < len(matrix)/2; i++ {
		matrix[i], matrix[len(matrix)-1-i] = matrix[len(matrix)-1-i], matrix[i]
	}
	// 2.对角线反转
	for i := 0; i < len(matrix); i++ {
		for j := i; j < len(matrix); j++ {
			matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]
		}
	}
}
