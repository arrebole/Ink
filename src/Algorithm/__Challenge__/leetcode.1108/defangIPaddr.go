package leetcode

import (
	"fmt"
	"strings"
)

func defangIPaddr(address string) string {
	split := strings.Split(address, ".")
	return fmt.Sprintf("%s[.]%s[.]%s[.]%s", split[0], split[1], split[2], split[3])
}
