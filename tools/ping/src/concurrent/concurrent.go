package concurrent

import (
	"net"
	"sync"
)

const maxWorker = 1

// WG ...
var WG sync.WaitGroup
var jobs []chan *net.IPAddr

// Concurrent ...
type Concurrent struct {
	handle []worker
}

// Dispatch 将ip分发给ping线程的管道
func (p *Concurrent) Dispatch(iPAddrs []*net.IPAddr) {
	WG.Add(1)
	for k, v := range p.handle {
		v.do(jobs[k])
	}
	go func() {
		for _, v := range iPAddrs {
		bables:
			for _, worke := range jobs {
				select {
				case worke <- v:
					break
				default:
					goto bables
				}
			}
		}
		WG.Done()
	}()
}

// New ...
func New() *Concurrent {
	result := &Concurrent{
		handle: make([]worker, maxWorker),
	}
	// 创建管道
	for i := 0; i < maxWorker; i++ {
		jobs = append(jobs, make(chan *net.IPAddr, 5))
		result.handle[i].quit = make(chan int)
	}
	return result
}
