package leetcode

var table = map[rune]int{
	'a': 2, 'b': 3, 'c': 5, 'd': 7, 'e': 11, 'f': 13, 'g': 17,
	'h': 19, 'i': 23, 'j': 29, 'k': 31, 'l': 37, 'm': 41, 'n': 43,
	'o': 47, 'p': 53, 'q': 59, 'r': 61, 's': 67, 't': 71, 'u': 73,
	'v': 79, 'w': 83, 'x': 89, 'y': 97, 'z': 101,
}

func check(str string) int {
	var result = 1
	for _, v := range str {
		result *= table[v]
	}
	return result
}

func groupAnagrams(strs []string) [][]string {
	var result [][]string
	var aux = make([]int, len(strs))
	var seen = make(map[int]bool)

	for i := 0; i < len(strs); i++ {
		aux[i] = check(strs[i])
	}
	for i := 0; i < len(strs); i++ {
		if _, has := seen[i]; has {
			continue
		}
		temp := []string{strs[i]}
		seen[i] = true
		for j := i + 1; j < len(strs); j++ {
			if _, has := seen[j]; has {
				continue
			}
			if aux[i] == aux[j] {
				temp = append(temp, strs[j])
				seen[j] = true
			}
		}
		result = append(result, temp)
	}
	return result
}
