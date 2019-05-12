package db

import (
	"fmt"
	"sync"
)

var once sync.Once //提供全局唯一性操作
var uniqueInstance *Singletion

// Singletion ...
// Pattern: creational-Singletion(双重校验锁-线程安全)
// Algorithm: _
type Singletion struct{}

// Ping ...
func (p *Singletion) Ping() {
	fmt.Println("test...")
}

// GetInstance 获取唯一实例
func GetInstance() *Singletion {
	// 全局范围内，只会执行一次
	once.Do(func() {
		uniqueInstance = &Singletion{}
	})
	return uniqueInstance
}
