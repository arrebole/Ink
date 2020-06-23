package leetcode

func generateParenthesis(n int) []string {
	var result []string
	backtrack(&result, "", 0, 0, n)
	return result
}

func backtrack(r *[]string, str string, open int, close int, max int) {
	if len(str) == 2*max {
		*r = append(*r, str)
	}
	if open < max {
		backtrack(r, str+"(", open+1, close, max)
	}
	if close < open {
		backtrack(r, str+")", open, close+1, max)
	}
}
