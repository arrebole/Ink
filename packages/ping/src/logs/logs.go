package logs

import (
	"fmt"
)

// Code ..
type Code = string

const (
	// TimeFail ping 超时
	TimeFail Code = "[TimeFail]"

	// ConnectFail 连接失败
	ConnectFail Code = "[ConnectFail]"

	// IoWriteFail 数据写入网卡发送区失败
	IoWriteFail Code = "[IoWriteFail]"

	// IoReadFail 读取网卡接收失败
	IoReadFail Code = "[IoReadFail]"

	// Success 成功
	Success Code = "[success]"
)

// Write ...
func Write(code Code, host string, data ...string) {
	var cache string
	for _, s := range data {
		cache += s
	}
	fmt.Println(code, host, cache)
}
