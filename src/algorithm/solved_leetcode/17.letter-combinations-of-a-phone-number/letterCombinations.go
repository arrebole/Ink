package leetcode

var table = map[byte][]string{
	'2': {"a", "b", "c"},
	'3': {"d", "e", "f"},
	'4': {"g", "h", "i"},
	'5': {"j", "k", "l"},
	'6': {"m", "n", "o"},
	'7': {"p", "q", "r", "s"},
	'8': {"t", "u", "v"},
	'9': {"w", "x", "y", "z"},
}

func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}
	var result = table[digits[0]]
	for i := 1; i < len(digits); i++ {
		result = comb(result, digits[i])
	}
	return result
}

func comb(combination []string, nextDigits byte)[]string {
	var result []string
	for _, v1 := range combination {
		for _, v2 := range table[nextDigits] {
			result = append(result, v1+v2)
		}
	}
	return result
}
