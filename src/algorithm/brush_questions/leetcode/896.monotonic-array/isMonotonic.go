package main

func order(A []int) int {
	if  A[len(A)-1] - A[0] > 0{
		return 1
	}
	return -1
}

func isMonotonic(A []int) bool {
	trend := order(A)
	for i := 0; i < len(A) - 1; i++ {
		if A[i+1] != A[i] && (A[i+1] - A[i]) ^ trend < 0 {
			return false
		}
	}
	return true
}