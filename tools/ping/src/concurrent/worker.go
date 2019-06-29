package concurrent

import (
	"net"

	"../ping"
)

type worker struct {
	quit chan int
}

func (p *worker) do(job chan *net.IPAddr) {
	go func() {
		for {
			ip := <-job
			ping.Send(ip)
		}

	}()
}
