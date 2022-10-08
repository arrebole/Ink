package closehashing

import "errors"

// HashTable 哈希表
type HashTable struct {
	data [][]*Pair
}

// Pair 哈希表内的元素
type Pair struct {
	Key   string
	Value int
}

// Set 往哈希表中添加元素
func (p *HashTable) Set(key string, value int) {
	it := p.findIndex(p.hash(key), func(item *Pair) bool {
		return item.Key == key
	})

	if it != -1 {
		p.data[p.hash(key)][it].Value = value
		return
	}

	for i, v := range p.data[p.hash(key)] {
		if v == nil {
			p.data[p.hash(key)][i] = &Pair{
				Key:   key,
				Value: value,
			}
		}
	}

}

// Get 获取哈希表中元素的值
func (p *HashTable) Get(key string) (int, error) {
	it := p.findIndex(p.hash(key), func(item *Pair) bool {
		return item.Key == key
	})

	if it == -1 {
		return 0, errors.New("")
	}

	return p.data[p.hash(key)][it].Value, nil
}

// Del 删除哈希表中元素
func (p *HashTable) Del(key string) {
	it := p.findIndex(p.hash(key), func(item *Pair) bool {
		return item.Key == key
	})

	p.data[p.hash(key)][it] = nil
}

func (p *HashTable) hash(data string) int {
	result := 0
	for _, v := range data {
		result += int(v)
	}
	return result % 10
}

func (p *HashTable) findIndex(index int, callback func(item *Pair) bool) int {
	list := p.data[index]
	for i := 0; list[i] != nil; i++ {
		if callback(list[i]) {
			return i
		}
	}
	return -1
}

// New 哈希表构造函数
func New() HashTable {
	table := make([][]*Pair, 10)
	for i := range table {
		table[i] = make([]*Pair, 10)
	}

	return HashTable{
		data: table,
	}
}
