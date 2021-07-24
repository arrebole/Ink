package main

// 填充为16的倍数
func appendMultiple16(buff []byte) []byte {
	return append(buff, make([]byte, 16-len(buff)%16)...)
}

// 计算校验和
func checksum(buff []byte) []byte {
	return []byte{}
}

// 追加校验和
func appendChecksum(buff []byte) []byte {
	return append(buff, checksum(buff)...)
}
