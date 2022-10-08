package leetcode

func countSegments(s string) int {
	result := 0
	var parentValue rune = ' '
	for _, v := range s {
		if (v != ' ' && parentValue == ' ') {
			result++
		}
		parentValue = v
	}
	return result;
}