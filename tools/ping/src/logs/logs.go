package logs

import (
	"bufio"
	"fmt"
	"os"
)

var bufferFd = bufio.NewWriter(os.Stdout)

// Write ...
func Write(code Code, host string, data ...interface{}) {
	fmt.Fprint(bufferFd, code, host, data, "\n")
	bufferFd.Flush()
}
