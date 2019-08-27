package icmp

import (
	"bytes"
	"encoding/binary"
)

// ICMP 报文头的结构
type ICMP struct {
	Type        uint8
	Code        uint8
	CheckSum    uint16
	Identifier  uint16
	SequenceNum uint16
}

// checkSum 计算检验码
func checkSum(data []byte) uint16 {
	var (
		sum    uint32
		length = len(data)
		index  int
	)
	for length > 1 {
		sum += uint32(data[index])<<8 + uint32(data[index+1])
		index += 2
		length -= 2
	}
	if length > 0 {
		sum += uint32(data[index])
	}
	sum += (sum >> 16)

	return uint16(^sum)
}

// 获取ICMP的总和校验码
func fillCheckSum(aIcmp *ICMP, buff bytes.Buffer) {
	aIcmp.CheckSum = checkSum(buff.Bytes())
}

func makeIcmpBuffer(pICMP *ICMP) bytes.Buffer {
	var result bytes.Buffer
	// 计算CheckSum
	binary.Write(&result, binary.BigEndian, pICMP)
	fillCheckSum(pICMP, result)
	// 最终写入
	result.Reset()
	binary.Write(&result, binary.BigEndian, pICMP)
	return result
}

// New 创建一个icmp数据包
// 传入 序号（sequence）
func New(seq uint16) bytes.Buffer {
	ping := ICMP{
		Type:        8,
		Code:        0,
		CheckSum:    0,
		Identifier:  0,
		SequenceNum: seq,
	}

	return makeIcmpBuffer(&ping)
}
