package ping

import (
	"net"
	"time"

	"../icmp"
	"../logs"
)

var icmpBuffer = icmp.New(uint16(1))

// Send ...
func Send(ipaddr *net.IPAddr) {
	sendICMPRequest(icmpBuffer.Bytes(), ipaddr)
}

func sendICMPRequest(icmpByte []byte, destAddr *net.IPAddr) error {
	conn, err := net.DialIP("ip4:icmp", nil, destAddr)
	if err != nil {
		logs.Write(logs.ConnectFail, destAddr.String())
		return err
	}
	defer conn.Close()

	if _, err := conn.Write(icmpByte); err != nil {
		logs.Write(logs.IoWriteFail, destAddr.String())
		return err
	}

	conn.SetReadDeadline((time.Now().Add(time.Second * 2)))

	recv := make([]byte, 30)
	receiveCnt, err := conn.Read(recv)
	if err != nil {
		logs.Write(logs.IoReadFail, destAddr.String())
		return err
	}

	logs.Write(logs.Success, destAddr.String(), "byte =", receiveCnt)

	return err
}
