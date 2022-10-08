package leetcode


func newSet(keys string)map[byte]bool {
	result := make(map[byte]bool)
	for i := range keys{
		result[keys[i]] = true
	}
	return result
}

func allIn(s string, table map[byte]bool) bool {
	for i := range s {
		if _, ok := table[s[i]]; !ok {
			return false
		}
	}
	return true
}

func findWords(words []string) []string {
	var result []string

	tables := []map[byte]bool{ 
		newSet("qwertyuiopQWERTYUIOP"), 
		newSet("asdfghjklASDFGHJKL"), 
		newSet("zxcvbnmZXCVBNM"),
	}

	for i := range words{
		for j := range tables {
			if allIn(words[i], tables[j]) {
				result = append(result, words[i])
				continue
			}
		}
	}
	return result
}