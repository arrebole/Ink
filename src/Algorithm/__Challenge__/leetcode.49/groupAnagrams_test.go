package leetcode

import (
	"io/ioutil"
	"strings"
	"testing"
)

func testCase() []string {
	data, _ := ioutil.ReadFile("./_testcase.csv")
	return strings.Split(string(data), ",")
}

func TestGroupAnagrams(t *testing.T) {
	groupAnagrams(testCase())
}
