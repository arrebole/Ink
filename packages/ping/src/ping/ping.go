package ping

import (
	"bytes"
	"fmt"
	"net"
	"time"

	"../icmp"
	"../logs"
)

// Ping ...
type Ping struct {
	icmpBuffer bytes.Buffer
	distAddr   *net.IPAddr
	times      int
}

// New 创建Ping
func New(dist *net.IPAddr) *Ping {
	return &Ping{
		icmpBuffer: icmp.New(uint16(1)),
		distAddr:   dist,
		times:      3,
	}
}

// Send ...
func (p *Ping) Send() error {
	conn, err := p.connSocket()
	if err != nil {
		return err
	}
	defer conn.Close()

	conn.SetReadDeadline((time.Now().Add(time.Second * 2)))
	for i := 0; i < p.times; i++ {
		p.write(conn)
		p.recv(conn)
	}
	return err
}

// 创建发送数据的socket
func (p *Ping) connSocket() (*net.IPConn, error) {
	result, err := net.DialIP("ip4:icmp", nil, p.distAddr)
	if err != nil {
		logs.Write(logs.ConnectFail, p.distAddr.String())
		return result, err
	}
	return result, err
}

// 写入需要发送的数据
func (p *Ping) write(conn *net.IPConn) error {
	_, err := conn.Write(p.icmpBuffer.Bytes())
	if err != nil {
		logs.Write(logs.IoWriteFail, p.distAddr.String())
		return err
	}
	return nil
}

// 接受响应数据
func (p *Ping) recv(conn *net.IPConn) error {
	recvBuff := make([]byte, 1024)
	recvLen, err := conn.Read(recvBuff)
	if err != nil {
		logs.Write(logs.IoReadFail, p.distAddr.String())
		return err
	}
	ttf := fmt.Sprintf("[TTL=%d]", recvBuff[8])
	byteLen := fmt.Sprintf("[byte=%d]", recvLen)
	logs.Write(logs.Success, p.distAddr.String(), byteLen, ttf)
	return nil
}
