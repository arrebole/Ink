<h1 style="text-align:center;">算法大纲</h1>
**数据结构**：线性、树、图、集合和字典

**重要的问题类型**：排序、查找、字符串处理、图问题、组合问题、几何问题、数值问题。



## Table of Contents

#### Ⅰ 暴力法
+ 暴力排序
   + [选择排序](#1.选择排序)
   + [冒泡排序](#2.冒泡排序)
+ 线性查找
   + [顺序查找](#1.顺序查找)
   + [蛮力匹配](#2.蛮力匹配)
+ 穷举查找
   + [深度优先搜索](#1.深度优先搜索)
   + [广度优先搜索](#2.广度优先搜索)

#### Ⅱ 减治法
+ 减常量
  + [插入排序](#1.插入排序])
  + [希尔排序](#2.希尔排序)
  + [拓扑排序](#3.拓扑排序)
  + 生成组合对象
    + [生成排列](#4.生成排列)
    + [生成子集](#5.生成子集)
+ 减常因子算法
  + [折半查找](#1.折半查找)
  + [俄式乘法](#2.俄式乘法)
+ 减可变规模算法
  + [选择问题](#1.选择问题)
  + [插值查找](#2.插值查找)
  + [二叉查找树的查找与插入](#3.二叉查找树的查找与插入)
+ 双指针技巧
  + [左右指针](#1.左右指针)
  + [快慢指针](#2.快慢指针)

#### Ⅲ 分治法
+ 分治排序
  + [归并排序](#1.归并排序)
  + [快速排序](2,快速排序)
+ 分而治之
  + [二叉树的高度](1.二叉树的高度)
  + [二叉树的遍历](#2.二叉树的遍历)
  + [karatsuba大整数乘法](#3.大整数乘法)

#### Ⅳ 变治法

+ 实例化简
  + [预排序]()
    + [元素唯一性]()
    + [模式计算]()
    + [查找问题]()
  + [高斯消去]()
    + [部分选主元]()
+ 改变表现
  + [平衡查找树]()
  + [堆和堆排序]()
  + [霍纳法则]()
  + [二进制幂]()

+ 问题化简
  + [求最小公倍数]()
  + [计算图中路径数量]()
  + [优化问题的化简]()
  + [线性规划]()
  + [简化为图问题]()

#### Ⅴ时空权衡
+ 输入增强
  + [计数排序]()
  + [Horspool算法]()
  + [Boyer-Moore算法]()
+ 预构造
  + [开散列]()
  + [闭散列]()
  + [B树作索引]()

#### Ⅵ 动态规划

+ 三个基本例子
  + [币值最大化]()
  + [找零]()
  + [硬币收集]()

+ [背包问题]()
+ [记忆功能]()
+ [最优二叉树]()
+ [Warshall算法]()
+ [Floyd算法]()

#### Ⅶ 贪婪技术
+ [Prim算法]()
+ [Kruskal算法]()
+ [Dijkstra算法]()
+ [哈夫曼树]()

#### Ⅷ 迭代改进
+ [单纯形法]()
+ [最大流量问题]()
+ [二分图的最大匹配]()
+ [稳定婚姻问题]()

#### Ⅸ 算法能力的极限
+ 如何求下界
  + [平凡下界]()
  + [信息论下界]()
  + [敌手下界]()
  + [问题化简]()
+ 决策树
  + [排序决策树]()
  + [查找有序数组的决策树]()
+ P、NP和NP完全问题
  + [P和NP问题]()
  + [NP完全问题]()

#### Ⅹ 超越算法的极限
+ 回溯法
  + [n皇后问题]()
  + [曼哈顿回路]()
  + [子集]()
  + [一般性说明]()
+ 分支界限法
  + [分配问题]()
  + [背包问题]()
  + [旅行商问题]()
+ NP的近似算法
  + [旅行商问题的近似算法]()
  + [背包问题的近似算法]()
+ 解非线性方程的算法
  + [平分法]()
  + [试位法]()
  + [牛顿法]()



# Ⅰ 暴力法

> 蛮力法(brute force)是一种简单直接地解决问题的方法，常常直接基于问题的描述和所涉及的概念定义
>
> “力”指代计算机的计算能力。

## 暴力排序

### 1.选择排序

> 输入：无序数组； 输出：有序数组
>
> 时间复杂度：θ(n^2)  但键的交换次数为 θ(n)；空间复杂度：1；

```c++
//  selection_sort 将输入的int数组进行选择排序
//  时间复杂度：θ(n^2) 键的交换次数为 θ(n)
//  空间复杂度：0
void selection_sort(int * data, int len){
    for (int i = 0; i < len - 1; i++){
        int minKey = i;
        for (int j = i + 1; j < len; j++){
            // find min key
            if (data[j] < data[minKey]) minKey = j;
        }
        swap(&data[i], &data[minKey]);
    }
}

// swap It swap two int
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
```

​	

### 2.冒泡排序

> 输入：无序数组； 输出：有序数组
>
> 时间复杂度：θ(n^2)  键的交换次数为 θ(n^2);空间复杂度：1；

```c++
//  冒泡排序 参数为需要排序的数组，数组的长度
//  时间复杂度：θ(n^2) 键的交换次数为 θ(n^2); 
void bubble_sort(int data[], int len){
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - 1 - i; j++){           
            if (data[j] > data[j + 1]) 
                swap(&data[j], &data[j + 1]);
        }
    }
}

// swap It swap two int
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
```



## 线性查找

> 在一个给定的列表中查准一个给定的值

### 1.顺序查找

> 输入：字符串和待匹配**字符**； 输出：**字符**在字符串中的索引
>
> 时间复杂度：T(n) 最好Ω(1), 最差 O(n)；空间复杂度：S(n) = 1

```c++
// SequentialSearch 查准数组中给定键的索引
// 简单的将给定列表的连续元素和给定查找键比较
// trick：将查找键添加到列表的末尾，查准必定会成功，就不需要在循环时判断是否越界
// 时间复杂度：T(n) = θ(n)
int SequentialSearch(int* data, int len, int key)
{
    // 创建一个新数组 比原来数组长度+1
    int aux[len + 1];
    copy(data, aux, len);
    
    // 新数组最后一项为传入的 key，就无需判断是否越界
    aux[len] = key;

    int result = 0;
    while (aux[result] != key) result++;

    if (result == len) return -1;
    return result;
}

// copy 将 a复制到b 个数为len
void copy(int* a, int*b, int len){
    for (int i = 0; i < len; i++) {
        b[i] = a[i];
    }
}
```



### 2.蛮力法字符串匹配

> 输入：字符串和待匹配**子串**； 输出：**子串**在字符串中的索引
>
> 时间复杂度：T(n)最差 O(mn)空间复杂度： S（n）= 1

```c++
// BruteForceStringMatch 在data中查准匹配模式的字串， 返回字串的首索引
// 时间复杂度： 平均 Θ(n) 最差( data_len * pattern_len )
int BruteForceStringMatch(char* data, int data_len, char* pattern, int pattern_len) {
    for (int i = 0; i <= (data_len - pattern_len); i++) {
        int j = 0;
        while (j < pattern_len && pattern[j] == data[i + j]) {
            j++;
            if (j == pattern_len) return i;
        }
    }
    return -1;
}
```



## 穷举查找

> 它要求生成问题域中的，每一个元素，选出其中满足问题约束的元素，然后找到一个期望的元素

### 1.深度优先搜索

> 以栈的数据结构，系统的遍历图中的所有点和边
>
> 时间复杂度：链表法 θ( |v| + |E| ) 矩阵法 θ( |v|^2 )

```python
# Dfs 深度优先搜索， 输入邻接链表法表示的图, 第一个遍历的key
# 象征勇气：直到找到最远的节点才返回
class DFS():
    def __init__(self, graph: dict):
      self._graph: dict = graph
      self._result: list[str] = []
    
    def _dfs(self, key: str):
        self._result.append(key)
        for nodes in self._graph[key]:
            if nodes not in self._result:
                self._dfs(nodes)
                
    def dfs(self, key: str):
        self._dfs(key)
        return self._result
```



### 2.广度优先搜索

> 以队列的数据结构，系统的遍历图中的所有点和边
>
> 时间复杂度：链表法 θ( |v| + |E| ) 矩阵法 θ( |v|^2 )

```python
# Bfs 广度优先搜索， 输入邻接链表法表示的图, 第一个遍历的key
# 象征谨慎：从最近的元素开始搜索
class BFS():
    def __init__(self, graph: dict):
      self._graph: dict = graph
      self._result: list[str] = []

    def bfs(self, key: str):
        queue: list[str] = [key]
        while(len(queue) > 0):
            local = queue.pop(0)
            for v in self._graph[local]:
                if v not in self._result:
                    self._result.append(v)
                    queue.append(v)
        return self._result
```





# Ⅱ 减治法

> 减治技术利用了一个问题给定实例的解和同样问题的较小实例的解之间的某种关系
>
> 一旦建立了这种关系，我们可以自顶向下，或者自下而上的运用这种关系

## 减常量

### 1.直接插入排序

> f (小数组长度+1) = f (小数组) 。
>
> 性能：C<sub>worst</sub> = θ( n<sup>2</sup> ); C<sub>bast</sub> = θ( n ); C<sub>avg</sub> ≈ 1/4 n<sup>n</sup>  = θ ( n<sup>2</sup> )

```c++
// insertionSort 
// f (array[n+1]) = f (array[n]) 
// 时间复杂度  θ( n^2 ) - θ( n );
void insertionSort(int* a, int len){
    //小数组递增, 自下而上
    for (int i = 1; i < len; i++){
        //从第二个元素开始，取出该元素，进行比较排序
        int loacl = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > loacl){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = loacl;
    }
}
```



### 2.希尔排序

> 分组插入排序，缩小增量排序
>
> 性能：【非稳定】T = θ(2^n) ~ θ(nlog^2n)

```c++
// shellSort 插入排序的一种缩小增量排序
// 步长的选择是希尔排序的重要部分 T = θ(2^n) ~ θ(nlog^2n)
void shellSort(int a[], const int len){
    int gap = 1, j, temp;
    while (gap < len / 3) gap = 3 * gap + 1;
    while (gap >= 1){
        for (int i = gap; i < len; i++){
            temp = a[i];
            // 将 a[j] 插入到 a[j-grap], a[i-2*gap], a[i-3*gap]中
            for(j = i - gap; j >= 0 && a[j] > temp;  j -= gap)
                a[j + gap] = a[j];
            a[j + gap] = temp;
        }
        gap = gap / 3;
    }
}
```



### 3.拓扑排序

#### Kahn拓扑排序

> 有向图的排序
>
> 性能：T(n) = O(n+e)

```python
# KahnTopoSort 基于减源的拓扑排序, -1策略
class KahnTopo:
    def __init__(self, graph):
        self._graph = graph
   
    # 统计每个结点的边的数量
    def _countEdge(self):
        result = dict()
        # 初始化点
        for key in self._graph.keys():
            result[key] = 0
        # 统计节点的边数
        for value_list in self._graph.values():
            for vertex in value_list:
                result[vertex] += 1
        return result

    def sort(self):
        result = list()
        edgeCount = self._countEdge()
        while (edgeCount):
            for key in list(edgeCount.keys()):
                # 如果边数为0, 则减少关联点的入度并删除
                if edgeCount[key] == 0:
                    for i in self._graph[key]:
                        edgeCount[i] -= 1
                    result.append(key)
                    del edgeCount[key]
        return result

```



#### DFS拓扑排序

> 有向图的排序
>
> 性能：T(n) = O(n+e)

```python
# 基于dfs的拓扑排序 基于暴力法-DFS,输出DFS的逆序
# graph 为 map 结构 邻接链表法表示图
class DFSTopo:
    def __init__(self, graph):
        self._graph = graph
        self._keys = set(graph.keys())
        self._result = list()
        
    def sort(self):
        while len(self._keys) > 0:
            # 随机取一个元素进行dfs
            self._dfs(self._keys.pop())
        self._result.reverse()
        return self._result
    
    def _pushResult(self, value):
        if value not in self._result:
            self._keys.discard(value)
            self._result.append(value)
    
    def _dfs(self, key):
        if len(self._graph[key]) == 0:
            return
        for node in self._graph[key]:
            self._dfs(node)
            # 出栈时，构建dfs森林
            self._pushResult(node)
        self._pushResult(key)
```



### 4.生成排列

##### JohnsonTrotter

> 输入：数组，输出：数组的所有序列组合。
>
> 性能：T = n(n-1)! ≈ n!

```go
// JohnsonTrotter 全排列生成算法 邻位对换法
func JohnsonTrotter(aux []int) []int {
	result := make([]int, 0)
	direc := make([]int, len(aux))
	for i := range direc {
		direc[i] = -1
	}

	for k := findMove(aux, direc); k != -1; k = findMove(aux, direc) {
		result = append(result, toInt(aux))
		// 交换
		t := direc[k] + k
		aux[t], aux[k] = aux[k], aux[t]
		direc[t], direc[k] = direc[k], direc[t]
		// 反转
		reverse(aux, direc, t)
	}
	return result
}

// 数组转化成数字
func toInt(a []int) int {
	result := 0
	for _, v := range a {
		result *= 10
		result += v
	}
	return result
}

//反转比移动项大的所有项的移动方向
func reverse(aux []int, d []int, k int) {
	max := aux[k]
	for i := range aux {
		if aux[i] > max {
			d[i] = d[i] * -1
		}
	}
}

//找到最大可移动项
func findMove(aux []int, direction []int) int {
	result := -1
	max := -1
	for i := range aux {
		j := i + direction[i]
		if j < 0 || j >= len(aux) {
			continue
		}
		if aux[i] > max && aux[j] < aux[i] {
			result = i
			max = aux[i]
		}
	}
	return result
}
```

##### LexicographicPermute

```go
// 以字典序产生排序
// Permute 生成字典序排列
func LexicographicPermute(n int) []int {
	var result = []int{}
	var aux = createList(n)
	for {
		// 将排列添加到结果
		result = append(result, aToInt(aux))
		// 找到最大升序元素 aux[i] < aux[i+1]
		i := findMaxOrdered(aux)
		if i == -1 {
			break
		}
		// 找到最大索引j使得 aux[i] < aux[j]
		j := findMaxBigIndex(aux, aux[i])
		// 交换 a[i],a[j]
		aux[i], aux[j] = aux[j], aux[i]
		// 反转 aux[i+1...n]
		recover(aux, i+1, n-1)
	}
	return result
}

// createList 输入n 输出[1,2..n]
func createList(n int) []int {
	var result = make([]int, n)
	for i := 0; i < n; i++ {
		result[i] = i + 1
	}
	return result
}

// aToInt 将数组转化为数字
// {1，2，3} -> 123
func aToInt(a []int) int {
	var result = 0
	for _, v := range a {
		result *= 10
		result += v
	}
	return result
}

//  recover 反转数组
func recover(a []int, lo, hi int) {
	for lo < hi {
		a[lo], a[hi] = a[hi], a[lo]
		lo++
		hi--
	}
}

// findMaxBigIndex 找到比n大的数的最大索引
func findMaxBigIndex(a []int, n int) int {
	var result = -1
	for i, v := range a {
		if v > n {
			result = i
		}
	}
	return result
}

// findMaxOrdered 寻找数组中最大升序
func findMaxOrdered(a []int) int {
	var result = -1
	for i := 0; i < len(a)-1; i++ {
		if a[i] < a[i+1] {
			result = i
		}
	}
	return result
}
```



### 5.生成子集

> 架构：减治法-生成子集-二进制反射格雷码算法
>
> 效果：输入一个 序列，求该序列的所有子序列
>
> 应用：分配问题(求最有价值的子集)
>


#### 二进制反射格雷码

```go
// BRGC 二进制反射格雷姆码 生成幂集
// 生成二进制数组[[1,0,1]..] -> 对应子集的映射
func BRGC(n int) [][]byte {
	var list [][]byte
	if n == 1 {
		list = [][]byte{[]byte{0}, []byte{1}}
	} else {
		L1 := BRGC(n - 1)
		L2 := recoverCode(L1)

		L1 = shift(L1, byte(0))
		L2 = shift(L2, byte(1))

		list = append(L1, L2...)
	}
	return list
}

// shift 将n加到a的每一个位串前
func shift(a [][]byte, n byte) [][]byte {
	for i := 0; i < len(a); i++ {
		a[i] = append([]byte{n}, a[i]...)
	}
	return a
}

// recover 反转 a
func recoverCode(a [][]byte) [][]byte {
	var result = [][]byte{}
	// 深拷贝
	for i := range a {
		t := append([]byte{}, a[i]...)
		result = append(result, t)
	}
	// 反转
	i, j := 0, len(a)-1
	for i < j {
		result[i], result[j] = result[j], result[i]
		i++
		j--
	}
	return result
}
```





## 减常因子算法

### 1.折半查找

> 有序数组中的的快速查找
>
> 性能：C<sub>avg</sub>( n ) = log<sub>2</sub>n

```c++
// @params：一个有序数组和它的长度，需要查找的key
// @retrun: key的index
int binarySearch(int a[], int len, int k){
    int lo = 0, hi = len - 1;
    while (lo <= hi){
        int m = (lo + hi) / 2;
        if (k == a[m])      return m;
        else if (k < a[m])  hi = m - 1;
        else                lo = m + 1;
    }
    return -1;
}
```



### 2.俄式乘法

> 架构：减治法-减常因子-俄式乘法，位操作
>
> 性能：极高，机器底层的基础操作。

```c++
/**
 *  减治法-减常因子-俄式乘法
 *  n * m = n/2 * 2m
 *  n * m = (n-1)/2 * 2m + m 
*/
int RussianPeasant(int n, int m){
    int sum = 0;
    while (n > 1){
        // n * m = n/2 * 2m
        if (n % 2 == 0){
            n = n >> 1;
            m = m << 1;
        }
        //n * m = (n-1)/2 * 2m + m
        else{
            // 先把 m 存放 sum 中
            // 当 m = 1 时 (n-1)/2 * 2m 被加入sum中
            n = (n - 1) >> 1;
            sum += m;
            m = m << 1;
        }
    }
    return (sum + m);
}
```





## 减可变规模算法

### 1.选择问题

#### Lomuto划分

> 将大于a的划分在右侧，小于a的划分在左侧

```python
#
#   lomuto划分：求数列中值
#   架构：减治法-减可变规模-lomuto划分
#   @params l,r,需要规划的开始端和结束端
#
def lomutoPartition(a: list) -> int:
    p = a[0]
    s = 0
    for i in range(0, len(a)):
        if a[i] < p:
            s += 1
            a[s], a[i] = a[i], a[s]
    a[0], a[s] = a[s], a[0]
    return s

```



#### 快速选择

> 架构：反复调用Lomuto划分找到数组中第n小的数
>
> 性能：C<sub>worst</sub> = Θ( n<sup>2</sup> )

```python
#
#   快速选择是一种从无序列表找到第k小元素的选择算法。
#   具有很好的平均时间复杂度，然而最坏时间复杂度则不理想.
#   性能： 从O(n log n)至O(n)，不过最坏情况仍然是O(n2)。
#
def quickSelect(a: list, k: int):
    s = lomutoPartition(a)
    if s == (k - 1):
        return a[s]
    elif s > (k - 1):
        return quickSelect(a[:s], k)
    else:
        return quickSelect(a[s+1:], k-1-s)

```



### 2.插值查找

> 架构：查字典思想，通过增长率优化版本的二分查找，只适用于有序数组
>
> 性能：与数列均匀度有关，C<sub>best</sub> = O(1);

```c++
/**
 *  插值查找：减治法-减可变规模-插值查找
 *  输入：顺序数组，数组长度，需要查找的key
 *  输出：key对应的索引，如果没有则返回-1；
 * 
*/
int interpolationSearch(int a[], int len, int key){

    // 搜索的左右索引
    int l = 0, r = len - 1;
    // 选定的索引
    int index = 0;

    while (a[index] != key && l != r){
        // 通过增长率求取近似索引
        int k = growthRate(a[l], a[r], r - l);
        index = (key - a[0]) / k;
        
        // 命中
        if (a[index] == key) return index;

        // 判断正序还是负序
        if (k >= 0){
            // 缩减搜索范围
            if (a[index] > key)  l = index;
            else                 r = index;
        }
        else{
            if (a[index] > key)  r = index;
            else                 l = index;
        }
    }

    return -1;
}

// 计算增长率
int growthRate(int a, int b, int num)
{
    return (a + b) / num;
}
```



### 3.二叉查找树的查找和插入

> 架构：减治法-减可变规模-二叉查找树的插入和查找
>
> 性能：查找 C<sub>avg</sub>= O( log 2 (n) )

#### 插入

```typescript
// BSTtreeInsert 二叉查找树的插入 非递归版本
export function BSTtreeInsert(root: TreeNode, node: TreeNode){
    let local = root;
    while(true){
        if(local.Left == null && node.Value <= local.Value) {
            local.Left = node;
            return;
        }
        if (local.Right == null && node.Value > local.Value ) {
            local.Right = node;
            return;
        }

        if(local.Left != null && node.Value <= local.Value ){
            local = local.Left;
            continue;
        }

        if(local.Right != null && node.Value > local.Value){
            local = local.Right;
            continue;
        } 
    }
}
```

#### 查找

```c++
// BSTtreeInsert 二叉查找树的插入(递归版本)
export function BSTtreeSearch(root: TreeNode, key: number){
    if (root.Value == key) return true
    
    if( root.Left != null && key <= root.Value) {
        return BSTtreeSearch(root.Left, key)
    }
    else if( root.Right != null && key > root.Value) {
        return BSTtreeSearch(root.Right, key)
    else  return false
}
```



## 双指针技巧

### 1.左右指针

> 左右指针主要解决数组（或者字符串）中的问题

#### 数组翻转

```go
// Reverse 双指针反转selice
func Reverse(slice []int) []int {
	var lo, hi = 0, len(slice) - 1
	for hi > lo {
		slice[lo], slice[hi] = slice[hi], slice[lo]
		hi--
		lo++
	}
	return slice
}
```



### 2.快慢指针

> 主要解决链表中的问题

#### 链表环路

```go
// HasCycle 判断链表是否有环路
func HasCycle(root *Node) bool {
	var slow, fast = root, root

	for fast.Next != nil {
		slow = slow.Next
		fast = fast.Next.Next
		if slow == fast {
			return true
		}
	}
	return false
}
```





# Ⅲ 分治法

> 递推式 T(n) = a·T(n/b) + f(n)，f(n)是分解和合并需要的时间函数；当a=1，分治退化为减治

## 分治排序

### 1.合并排序

> 架构：分治法-自上而下合并排序；分治法-自下而上合并排序
>
> 性能：C( n ) = n long<sub>2</sub>n; 稳定排序，cpu缓存命中低

#### 合并排序-自上而下

```c++
// 分治法-自上而下合并排序
void mergeSort(int a[], int l, int r){
    if (l == r) return;
    
    int m = (r + l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m + 1, r);
}

// 将数组的两段合并
void merge(int a[], int l, int m, int r){
    int i, j, k;

    int LEFT_SINZE = m - l;
    int RIGHT_SINZE = r - m + 1;

    // 将数组分割拷贝成两段
    int left[LEFT_SINZE], right[RIGHT_SINZE];
    for (i = l; i < m; i++)  left[i - l] = a[i];
    for (i = m; i <= r; i++) right[i - m] = a[i];

    // 合并
    i = 0, j = 0, k = l;
    while (i < LEFT_SINZE && j < RIGHT_SINZE){
        if (left[i] < right[j]) a[k++] = left[i++];
        else                    a[k++] = right[j++];
    }

    // 合并剩余
    while (i < LEFT_SINZE)   a[k++] = left[i++];
    while (j < RIGHT_SINZE)  a[k++] = right[j++];

}
```



#### 合并排序-自下而上

```c++
// 自下而上归并排序
void mergeBuSort(int a[], int len){
    // 辅助数组aux；
    int *aux = (int *)malloc(sizeof(int) * len);
    for (int sz = 1; sz < len; sz += sz){
        for (int lo = 0; lo < len - sz; lo += sz + sz){
            int t = lo + sz + sz - 1;
            int min = t > len - 1 ? len - 1 : t;
            merge(a, aux, lo, lo + sz - 1, min);
        }
    }

    free(aux);
}

// 将a[lo..mid]和 a[mid+1..hi]归并
void merge(int a[], int aux[], int lo, int mid, int hi){
    int i = lo, j = mid + 1;
    // 将a[lo..hi]复制到aux[lo..hi]
    for (int k = lo; k <= hi; k++)  aux[k] = a[k];
    
    // 归并到a[lo..hi]
    for (int k = lo; k <= hi; k++){
        if (i > mid)                a[k] = aux[j++];
        else if (j > hi)            a[k] = aux[i++];
        else if (aux[j] < aux[i])   a[k] = aux[j++];
        else                        a[k] = aux[i++];
    }
}
```



### 2.快速排序

> 架构：分治法-快速排序， 通过不断的划分实现排序
>
> 性能：不稳定排序 C<sub>avg</sub>=1.39*n*log<sub>2</sub>n

```c++
// 分治法 ->快速排序
// 性能：C平均 = 1.39*n*log2*n
// 性能：C平均 = 1.39*n*log2*n
void quickSort(int a[], int lo, int hi){
    if (lo < hi){
        int s = HoarePartition(a, lo, hi);
        quickSort(a, lo, s - 1);
        quickSort(a, s + 1, hi);
    }
}

int HoarePartition(int a[], int lo, int hi){
	// 以最左边的数(lo)为基准
	int base = a[lo];
	while (lo < hi) {
		// 从序列右端开始，向左遍历，直到找到小于base的数
		while (lo < hi && a[hi] >= base)    hi--;
		// 找到了比base小的元素，将这个元素放到最左边的位置
		a[lo] = a[hi];
 
		// 从序列左端开始，向右遍历，直到找到大于base的数
		while (lo < hi && a[lo] <= base)    lo++;
		// 找到了比base大的元素，将这个元素放到最右边的位置
		a[hi] = a[lo];
	}
	// 最后将base放到lo位置。此时，lo位置的左侧数值应该都比lo小；
	// 而lo位置的右侧数值应该都比lo大。
	a[lo] = base;
	return lo;
}
```



## 分而治之

### 1.二叉树的高度

> 架构：分治法-二叉树高度搜索
>
> 性能： C(n) = 2n+1

```go
// TreeHeight 分治法计算二叉树的高度
func TreeHeight(root *BTNode) int {
	if root == nil {
		return -1
	}

	return Max(TreeHeight(root.Right), TreeHeight(root.Left)) + 1
}

// Max 返回最大值
func Max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```



### 2.二叉树的遍历

> 架构：分治法-二叉树遍历
>
> 性能： C(n) = 2n+1

##### 前序遍历

```go
// 入栈时输出
func preOrderTraversal(root *BTNode) {
	if root != nil {
		fmt.Println(root.Value)
		preOrderTraversal(root.Left)
		preOrderTraversal(root.Right)
	}
}
```



##### 中序遍历

```go
// 中序遍历
// 用于二叉树排序
func inOrderTraversal(root *BTNode) {
	if root != nil {
		preOrderTraversal(root.Left)
		fmt.Println(root.Value)
		preOrderTraversal(root.Right)
	}
}
```



##### 后序遍历

```go
// 后序遍历
// 出栈时输出
func postOrderTraversal(root *BTNode) {
	if root != nil {
		preOrderTraversal(root.Left)
		preOrderTraversal(root.Right)
		fmt.Println(root.Value)
	}
}
```



### 3.大整数乘法

> 思想：将大数分解为幂指数相加的形式
>
> 架构：分治法-大整数相乘
>
> 性能：A( n ) ∈ Θ ( n<sup>long<sub>2</sub>3</sup>)

```python
# karatsuba 将大数分解为幂指数相加的形式
# ab = c10^n + d10^n/2 + d
def karatsuba(num1: int, num2: int)->int:

    # 递归终止条件
    if (num1 < 10) or (num2 < 10):
        return num1 * num2

    # 计算拆分长度
    num1Str = str(num1)
    num2Str = str(num2)

    maxLength = max(len(num1Str), len(num2Str))
    splitPosition = int(maxLength / 2)

    # 拆分为 high1, low1, high2, low2
    high1, low1, high2, low2 = 0, 0, 0, 0
    if len(num1Str[: -splitPosition]) < 1:
        high1 = 0
        low1 = int(num1Str[-splitPosition:])
    else:
        high1 = int(num1Str[:-splitPosition])
        low1 = int(num1Str[-splitPosition:])

    if len(num2Str[: -splitPosition]) < 1:
        high2 = 0
        low2 = int(num2Str[-splitPosition:])
    else:
        high2 = int(num2Str[:-splitPosition])
        low2 = int(num2Str[-splitPosition:])

    # 计算z2, z0, z1, 此处的乘法使用递归
    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)

    return (z2 * 10 ** (2 * splitPosition)) + ((z1 - z2 - z0)*10**(splitPosition)) + z0

```





# Ⅳ 变治法

>变换思想

## 实例化简

>变换为同样问题的一个更简单的实例，我们称之为实例化简

### 1.预排序

>有序列表更容易求解。

#### 元素的唯一性

```javascript
// PresortElementUniqueness 预排序检测数组唯一性
function PresortElementUniqueness(a) {
    let t = a.concat();
    mergeSort(t);// 先进行归并排序
    for (let i = 0; i < t.length - 1; i++) {
        if (t[i] == t[i + 1]) return false;
    }
    return true;
}
```



#### 模式计算

```javascript
// PresortMod 预排序检测数组频率出现最多的元素
function PresortMode(a) {
    let t = a.concat();
    mergeSort(t); // 进行归并排序
    let i = 0, modefrequency = 0, modevalue = null;
    while (i <= t.length - 1) {
        let runlength = 1, runvalue = t[i];
        while (i + runvalue <= t.length - 1 && t[i + runlength] == runvalue) {
            runlength++;
        }
        if (runlength > modefrequency) {
            modefrequency = runlength;
            modevalue = runvalue;
        }
        i += runlength;
    }
    return modevalue;
}
```



#### 查找问题

>先排序再进行折半查找，如果我们要在同一个列表中进行多次查找，在排序上花费一些时间是值得的。
>
>T<sub>sort</sub>( n ) + T<sub>search</sub> = Θ(n log n) + Θ(long n)
>

```javascript

// PresortSearch 先排序再进行折半查找
function PresortSearch(a, key) {
    let t = a.concat();
    let l = 0, r = t.length - 1, m = 0;
    mergeSort(t);
    while (l <= r) {
        m = parseInt((l + r) / 2);
        if (t[m] == key) 	return m;
        if (key < a[m])  	r = m - 1;
        else 				l = m + 1;

    }
    return -1;
}
```



### 2.平衡查找树

> 平衡树的自平衡是将实例化简的类型

#### AVL Tree

...



### 3.堆和堆排序

> 堆的构建是实例化简的类型

#### 堆的构建

```python
# 堆的构建
class Heap:
    def __init__(self, data: list):
        self.data = data
        self._heapBottomUp()
    
    # heapBottomUp 自底向上构建最大堆
    def _heapBottomUp(self):
        for i in range(int(len(self.data)/2)-1, -1, -1):
            self._heapify(len(self.data), i)
    
    # n 为堆节点个数， root为小堆的根节点
    def _heapify(self, n: int, root: int):
        c1 = 2 * root + 1
        c2 = 2 * root + 2
        max = root
        # 将最大子节点与根节点做交换
        if c1 < n and self.data[c1] > self.data[max]:
            max = c1
        if c2 < n and self.data[c2] > self.data[max]:
            max = c2
        if max != root:
            self.data[max],self.data[root] = self.data[root],self.data[max]
            self._heapify(n, max)
```

#### 堆排序

```python
def sort(self):
    for i in range(len(self.data)-1, -1, -1):
        self.data[i], self.data[0] = self.data[0],self.data[i]
        self._heapify(i, 0)
        return self.data
```



## 改变表现

> 变换为同样实例的不同表现，我们称之为改变表现，例如方程的变形

### 1.霍纳法则

```python
# Horner 霍纳法则计算多项式(改变表现技术的例子)
# 例如 p(x) = 2x^4 + x^3 + 3x^2 + x-5
# =>  x(x(x(2x - 1) + 3) + 1) - 5
# p-> 多项式系数(从高到低排列)
def Horner(P: list, x) ->int:
    p = P[0]
    for i in range(1, len(P)):
        p = x*p + P[i]
    return p
```



### 2.二进制幂

...



## 问题化简

>变换为另一个问题的实例，我们称之为问题化简。

### 1.求最小公倍数

```python
# lcm 求最小公倍数
# 问题化简为：lcm(m,n) = m*n/gcd(m,n)
def lcm(m: int, n: int)->int:
    return m*n / gcdEuclid(m,n)

# gcd 欧几里得算法求最大公约数 
def gcdEuclid(m, n):
    while n != 0:
        r = m % n
        m = n
        n = r
    return m
```



### 2.计算图中路径数量

### 3.优化问题的化简

### 4.线性规划

### 5.简化为图问题





# Ⅴ时空权衡

> 时间与空间的权衡

## 输入增强

> 这个思想是对问题的部分或全部输入做预处理，然后将获得的额外的信息进行存储，以加速后面的问题。
>
> 我们把这个方法称为输入增强

### 1.计数排序

#### 比较计数排序

> 性能：C(n) = n(n-1)/2 => O(n) = n^2

```go
// ComparisonCountingSort 比较计数排序
// 输入增强， 先算出列表中小于该元素的元素个数
func ComparisonCountingSort(a []int) []int {
	var result = make([]int, len(a))
	var count = Comparison(a)

	for i := 0; i < len(a); i++ {
		result[count[i]] = a[i]
	}
	return result
}

// Comparison 算出一个列表，列表中小于该元素的个数
func Comparison(a []int) []int {
	var result = make([]int, len(a))
	//计算小于该元素的元素个数
	for i := 0; i < len(a)-1; i++ {
		for j := i + 1; j < len(a); j++ {
			if a[i] < a[j] {
				result[j]++
			} else {
				result[i]++
			}
		}
	}
	return result
}
```



#### 分布计数排序

> 性能：O(n) = n; 线性复杂度

```go
// DistributionCountingSort 分布计数排序
// 适用于排序连续的具有上下界的数组 l,u 为数组元素的上下界
func DistributionCountingSort(a []int, l, u int) []int {
	var result = make([]int, len(a))
    
	d := frequency(a, l, u)
	d = distributed(d, l, u)

	for i := len(a) - 1; i >= 0; i-- {
		j := a[i] - l
		result[d[j]-1] = a[i]
		d[j] = d[j] - 1
	}
	return result
}
// 计算出频率值
func frequency(a []int, l, u int) []int {
	var result = make([]int, u-l+1)
	for i := 0; i < len(a); i++ {
		result[a[i]-l]++
	}
	return result
}
// 分布值表示的是最后一次出现的正确位置
func distributed(a []int, l, u int) []int {
	for i := 1; i < u-l+1; i++ {
		a[i] = a[i-1] + a[i]
	}
	return a
}
```



### 2.Horspool算法

> horspoolMatching 字符串匹配算法
>
> 性能：O(n)~O(n*m)

```python
# horspoolMatching 时空权衡输入增强字符串匹配
# 创建移动表来设置每次移动距离
def horspoolMatching(p:str, t:str):
    table = shiftTable(p, max(maxCode(t),maxCode(p)))
    i = len(p)-1
    while i <= len(t) - 1:
        k = 0
        while k <= len(p)-1 and p[len(p)-1-k] == t[i-k]:
            k = k+1
        if k == len(p):
            return i-len(p)+1
        else:
            i = i+table[ord(t[i])]
    return -1

# shiftTable 构建移动表
def shiftTable(p:str, maxSize:int)->list:
    result = list()
    for i in range(maxSize+1):
        result.append(len(p))
    for i, ch in enumerate(p):
        result[ord(ch)] = len(p)-i-1
    return result

# maxCode 找到字符串最大的编码
def maxCode(s:str)->int:
    result = 0
    for _, ch in enumerate(s):
        if ord(ch) > result:
            result = ord(ch)
    return result
```



## 预构造

> 简单的使用额外的空间来实现更快的数据存储,强调存储结构

### 1.散列法

#### 开散列(分离链)

```go
// 使用链表的解决碰撞
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
```



#### 闭散列(开式寻址)

```go
// 使用二维数组解决碰撞
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
```



# Ⅵ 动态规划

> 解决计算重复子问题

## 三个基本例子

#### 1.币值最大化

```go
// CoinRow 选择非相邻硬币，币值最大化
// 包含最后一个硬币f(n-2), 不包含最后硬币f(n-1)
func CoinRow(c []int) int {
	opt := make([]int, len(c))
    // opt[0]和opt[1] 为递归时的出口
	opt[0], opt[1] = c[0], max(c[0], c[1])
	for i := 2; i < len(c); i++ {
        // 如果选择c[i]则 f(n) = c[i] + f(n-2)
        // 不选择则 f(n) = f(n-1)
        // 选择两种情况的最大情况
		opt[i] = max(opt[i-2]+c[i], opt[i])
	}
	return opt[len(c)-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
```



#### 2.找零

```go
// DPChangeMaking 动态规划求解找零问题
// f(n)为最小硬币数量
// | f(0) = 0
// | f(n) = min{ f(n-dj) } + 1
func DPChangeMaking(d []int, n int) int {
	opt := make([]int, n+1)
	opt[0] = 0
	for i := 1; i <= n; i++ {
		temp := 99999
		// i为表中的总价格，d[j-1] 单枚硬币的价格
		// opt[i-d[j-1]]: 子问题的答案,
		// 遍历子问题的答案与新加一枚硬币的组合
		for j := 1; j <= len(d) && i >= d[j-1]; j++ {
			temp = min(opt[i-d[j-1]], temp)
		}
		opt[i] = temp + 1
	}
	return opt[n]
}

func min(arg ...int) int {
	result := arg[0]
	for _, v := range arg {
		if v < result {
			result = v
		}
	}
	return result
}
```



#### 3.硬币收集

```go
// DPRobotCoinCollection 动态规划解决硬币收集问题
func DPRobotCoinCollection(c [][]int) int {
	f := createMatrix(len(c), len(c[0]))
	// 先计算第一行子问题
	f[0][0] = c[0][0]
	for i := 1; i < len(c[0]); i++ {
		f[0][i] = f[0][i-1] + c[0][i]
	}
	// 按照子问题递推
	for i := 1; i < len(c); i++ {
		f[i][1] = f[i-1][1] + c[i][1]
		for j := 1; j < len(c[0]); j++ {
			// 取上方和右边的最大值
			f[i][j] = max(f[i-1][j], f[i][j-1]) + c[i][j]
		}
	}
	return f[len(c)-1][len(c[0])-1]
}

func createMatrix(i, j int) [][]int {
	result := make([][]int, i)
	for k := 0; k < i; k++ {
		result[k] = make([]int, j)
	}
	return result
}
```



## 背包问题

## 记忆功能

## 最优二叉树

## Warshall算法

## Floyd算法





# Ⅶ 贪婪技术

> 通过一系列步骤来构造问题的解，每一步对目前构造的部分解做一个扩展，直到获得问题的完整解为止。
>
> 每一步必须满足条件：可行性；局部最优；不可取消；

## Prim算法

```python
# Prim 贪婪技术加权图生成最小树
def Prim(graph: dict, root: str):
    result = list()
    seen = set()
    nodes = list(graph.keys())
    
    # 每次往树中添加[最短]的节点
    # 添加初始节点
    seen.add(root)
    nodes.remove(root)
    # 组成边的两点
    pre = None
    next = None
    #每次找树中的点与最近的剩余点 
    while nodes:
        distance = float('inf')
        for s in seen:
            for d in graph[s]:
                if d in seen or s == d:
                    continue
                # 找到距离树最近的点
                if graph[s][d] < distance:
                    distance = graph[s][d]
                    pre = s
                    next = d
        result.append((pre,next))
        seen.add(next)
        nodes.remove(next)
    
    return result
```



## Kruskal算法

## Dijkstra算法

## 哈夫曼树





# Ⅷ 迭代改进

## 单纯形法

## 最大流量问题

## 二分图的最大匹配

## 稳定婚姻问题



# Ⅸ 算法能力的极限

## 如何求下界

## 决策树

## P、NP和NP完全问题





# Ⅹ超越算法的极限

## 回溯法

> 每次构造解的一个分量，然后评估这个分量，如果无法接受则进行回溯。

### N皇后问题

```typescript
export class NQueen {
    constructor(n: number) {
        this.N = n;
        this.result = new Array<number[]>();
        this.checkerboard = new Array(n);
    }
    private N: number // 棋盘大小
    private result: number[][] //记录所有解
    private checkerboard: number[] //记录当前解
    // check 验证摆放是否合法
    private check(row: number, col: number): boolean {
        for (let i = 0; i < row; i++) {
            // 都不在同一行、同一列以及同一斜线
            if (this.checkerboard[i] == col
                || this.checkerboard[i] - col == i - row
                || this.checkerboard[i] - col == row - i
            ) return false;
        }
        return true
    }
    // backtracking 回溯法求n皇后的摆放解
    private backtracking(row: number) {
        // 递归出口：当搜索行数等于所有行数时
        // 将答案记录到结果中
        if (row == this.N) {
            this.result.push(this.checkerboard.concat())
            return;
        }
        for (let col = 0; col < this.N; col++) {
            if (this.check(row, col)) {
                this.checkerboard[row] = col
                this.backtracking(row + 1)
            }
        }
    }
    public exec(): number[][] {
        this.backtracking(0)
        return this.result
    }
}
```



## 分支界限法

### 分配问题



## NP的近似算法

## 解非线性方程的算法

