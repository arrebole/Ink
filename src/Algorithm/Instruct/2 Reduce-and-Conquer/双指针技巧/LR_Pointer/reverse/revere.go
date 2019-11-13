package reverse

// Reverse 双指针反转selice
func Reverse(slice []int) []int {
	var lo, hi = 0, len(slice) - 1
	for hi > lo {
		slice[lo], slice[hi] = slice[hi], slice[lo]
		hi--
		lo++
	}
	return slice
}
