package openhashing

import "errors"

type pair struct {
	Key   string
	Value int
	next  *pair
	pre   *pair
}

// HashTable 哈希表
type HashTable struct {
	data []*pair
}

// Set 哈希表插入
func (p *HashTable) Set(key string, value int) {
	it := p.find(p.hash(key), func(i *pair) bool {
		return i.Key == key
	})
	// 如果元素不存在则正常插入
	if it == nil {
		item := &pair{
			Key:   key,
			Value: value,
			next:  p.data[p.hash(key)],
		}
		if p.data[p.hash(key)] != nil {
			p.data[p.hash(key)].pre = item
		}
		p.data[p.hash(key)] = item
	} else {
		it.Value = value
	}
}

// Get 哈希表查询
func (p *HashTable) Get(key string) (int, error) {
	result := p.find(p.hash(key), func(i *pair) bool {
		return i.Key == key
	})

	if result != nil {
		return result.Value, nil
	}
	return 0, errors.New("not found")
}

// Delete 哈希表删除元素
func (p *HashTable) Delete(key string) bool {
	result := p.find(p.hash(key), func(i *pair) bool {
		return i.Key == key
	})

	// 不存在则返回错误
	if result == nil {
		return false
	}
	// 删除元素是第一个 | 不是第一个
	if result.pre == nil {
		p.data[p.hash(key)] = result.next
	} else {
		result.pre.next = result.next
	}
	return true
}

func (p *HashTable) hash(data string) int {
	result := 0
	for _, v := range data {
		result += int(v)
	}
	return result % 10
}

func (p *HashTable) find(index int, callback func(i *pair) bool) *pair {
	for i := p.data[index]; i != nil; i = i.next {
		if callback(i) {
			return i
		}
	}
	return nil
}

// New 开散列构造函数
func New() HashTable {
	return HashTable{
		data: make([]*pair, 10),
	}
}
