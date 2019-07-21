# 算法大纲

---

**重要的问题类型**：排序、查找、字符串处理、图问题、组合问题、几何问题、数值问题。

**数据结构**：线性数据结构、树、图、集合和字典

[刷题整理](/docs/Core/Algorithms/Explore.md) 



## Table of Contents

#### Ⅰ 暴力法

+ 暴力排序
   + [选择排序]()
   + [冒泡排序]()
+ 穷举查找
   + [顺序查找]()
   + [蛮力字符串匹配]()
   + [深度优先搜索]()
+ [广度优先搜索]()

#### Ⅱ 减治法

+ 减治排序
  + [插入排序]()
  + [希尔排序]()
  + [拓扑排序]()
+ 生成组合对象
  + [生成排列]()
  + [生成子集]()
+ 减常因子算法
  + [折半查找]()
  + [俄式乘法]()
+ 减可变规模算法
  + [计算中值和选择]()
  + [插值查找]()
  + [二叉查找树的查找与插入]()

#### Ⅲ 分治法

+ 分治排序
  + [归并排序]()
  + [快速排序]()
+ 分而治之
  + [二叉树的遍历]()
  
  + [karatsuba大整数乘法]()
  + [strassen矩阵乘法]()
  
  + [最近对问题]()
  + [凸包问题]()

#### Ⅳ 变治法

+ 变治排序
  + [堆排序]()

+ 预排序法
  + [元素唯一性]()
  + [模式计算]()
  + [查找问题]()
+ 高斯消去法
  
  + [部分选主元法]()
  + [LU分解]()
  + [计算矩阵的逆]()
  + [计算矩阵的行列式]()
+ 霍纳法则和二进制幂
  + [霍纳法则]()
  + [二进制幂]()
+ 平衡查找树
  + [AVL 树]()
  + [2-3 树]()
  + [红黑树]()
+ 问题化简
  + [求最小公倍数]()
  + [计算图中路径数量]()
  + [优化问题的化简]()
  + [线性规划]()
  + [简化为图问题]()

#### 时空权衡

+ 计数排序
  + [桶排序]()
+ 输入增强
  + [Horspool算法]()
  + [Boyer-Moore算法]()
+ 散列法
  + [开散列]()
  + [闭散列]()

#### Ⅴ 动态规划

+ [背包问题]()
+ [记忆化]()
+ [最优二叉树]()
+ [Warshall算法]()
+ [Floyd算法]()

#### Ⅵ 贪婪技术

+ [Prim算法]()
+ [Kruskal算法]()
+ [Dijkstra算法]()
+ [哈夫曼树]()

#### Ⅶ 迭代改进

+ [单纯形法]()
+ [最大流量问题]()
+ [二分图的最大匹配]()
+ [稳定婚姻问题]()

#### Ⅷ 算法能力的极限

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

#### Ⅸ 超越算法的极限

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


### 选择排序


> 时间复杂度：θ(n^2)  但键的交换次数为 θ(n); 
>
> 原理：遍历比较，选择最小的交换。

```c++
/**
 *  选择排序 参数为需要排序的数组，数组的长度
 *  时间复杂度：θ(n^2) 键的交换次数为 θ(n); 
 */
void selection_sort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++){
        int minKey = i;
        for (int j = i + 1; j < len; j++){
            if (arr[j] < arr[minKey]){
                minKey = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minKey];
        arr[minKey] = temp;
    }
}
```

​	



### 冒泡排序

> 时间复杂度：θ(n^2)  键的交换次数为 θ(n^2);
>
> 原理：a[i]与a[i+1]比较 

```c++
/**
 *  冒泡排序
 */
void bubble_sort(int arr[], int len){
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - 1 - i; j++){           
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```



## 线性查找

> 在一个给定的列表中查准一个给定的值

### 顺序查找

> 时间复杂度：T(n) 最好Ω(1), 最差 O(n)
>
> 空间复杂度：S(n) = 1

```c++
// 暴力法——顺序查找
// 时间复杂度：T(n) = θ(n)
int SequentialSearch(int arr[], int len, int key){
    // 创建一个新数组 比原来数组长度+1
    int newArr[len + 1];
    for (int i = 0; i < len; i++){
        newArr[i] = arr[i];
    }
    // 新数组最后一项为传入的 key
    newArr[len] = key;

    int j = 0;
    while (newArr[j] != key){
        j++;
    }
    if (j == len){
        return -1;
    }
    return j;
}
```



### 蛮力法字符串匹配

> 时间复杂度：T(n)最差 O(mn)
>
> 空间复杂度： S（n）= 1

```c++
// t_len: t字符长度，不包括字符串 '\0'
// p_len: p字符长度，不包括字符串 '\0'
int BruteForceStringMatch(char t[], int t_len, char p[], int p_len)
{
    for (int i = 0; t_len - p_len; i++){
        int j = 0;
        while (j < p_len && p[j] == t[i + j]){
            j++;
            if (j == p_len)  return i;
        }
    }
    return -1;
}
```





## 穷举查找

### 暴力枚举

> 利用条件

### 深度优先搜索

> 暴力法-深度优先搜索
>
> 时间复杂度：链表法 θ( |v| + |E| ) 矩阵法 θ( |v|^2 )

```c++
/**
 *  通过栈和邻接链表图实现 深度优先搜索
 *  暴力法-深度优先搜索
 *  输入图和起始点
*/
void dfs(map<string, vector<string>> graph, string s)
{
    // 搜索栈
    stack<string> st;
    // 跟踪是否已经到过
    set<string> seen;

    st.push(s);
    seen.insert(s);

    while (!st.empty())
    {
        // 从栈中取一个元素
        string vertex = st.top();
        st.pop();
        // 查询取出的元素
        vector<string> nodes = graph[vertex];
        // 遍历取出的元素
        for (int i = 0; i < nodes.size(); i++)
        {
            // 判断元素是否已经查询过
            string node = nodes[i];
            if (seen.find(node) == seen.end())
            {
                // 如果没有查询过，则把该元素入栈，并标记
                st.push(node);
                seen.insert(node);
            }
            
        }
        cout << vertex << endl;
    }
}
```



### 广度优先搜索

> 暴力法-广度优先搜索
>
> 时间复杂度：链表法 θ( |v| + |E| ) 矩阵法 θ( |v|^2 )

```c++
/**
 *  通过队列和邻接链表图实现 深度优先搜索
 *  暴力法-广度优先搜索
 *  输入图和起始点
*/
void bfs(map<string, vector<string>> graph, string s)
{
    // 搜索队列
    queue<string> qu;
    // 跟踪是否已经到过
    set<string> seen;

    qu.push(s);
    seen.insert(s);

    while (!qu.empty()){
        // 取出队列头
        string vertex = qu.front();
        qu.pop();
        // 查询取出的元素
        vector<string> nodes = graph[vertex];
        // 遍历取出的元素
        for (int i = 0; i < nodes.size(); i++){
            // 判断元素是否已经查询过
            string node = nodes[i];
            if (seen.find(node) == seen.end()){
                // 如果没有查询过，则把该元素推入队列，并标记
                qu.push(node);
                seen.insert(node);
            }
        }
        cout << vertex << endl;
    }
}
```



<br />

# Ⅱ 减治法

## 直接插入排序

> 思想：减治法-减常因子
>
> 注释：小数组每次长度+1进行排序。
>
> 性能：C<sub>worst</sub> = θ( n<sup>2</sup> ); C<sub>bast</sub> = θ( n ); C<sub>avg</sub> ≈ 1/4 n<sup>n</sup>  = θ ( n<sup>2</sup> )

#### 迭代实现直接插入排序 

```c++
void insertionSort(int a[], int len)
{
    //从第二个元素开始，取出该元素，进行比较排序
    //小数组递增
    for (int i = 1; i < len; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}
```





## 希尔排序

> 思想：基于直接插入排序
>
> 性能：优于直接插入排序

#### (风格一)希尔排序实现

```c++
void shellSort(int a[], const int len)
{
    int gap = 1;
    while (gap < len / 3)
    {
        gap = 3 * gap + 1;
    }
    while (gap >= 1)
    {
        for (int i = gap; i < len; i++)
        {
            int v = a[i];
            int j = i - gap;
            while (j >= 0 && a[j] > v)
            {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = v;
        }
        gap = gap / 3;
    }
}
```



#### (风格二)希尔排序实现

```c++
void shellSort(int a[], const int len)
{
    int N = len;
    int h = 1;
    while (h < N / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < N; i++)
        {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
            {
                int temp = a[j];
                a[j] = a[j - h];
                a[j - h] = temp;
            }
        }
        h = h / 3;
    }
}
```



## 拓扑排序

> 架构：1、基于减治法、源删除Kahn算法。2、基于暴力法-DFS,输出DFS的逆序
>
> 区别：Kahn算法是从每个**入度为0**的顶点出发。基于dfs 是对每个**出度为0**的顶点进行dfs
>
> 性能：T(n) = O(n+e)
>
> 应用：有向图的排序



##### 图的表示

```python
    graph = dict()
    graph["A"] = ["C", "B"]
    graph["B"] = ["G", "E"]
    graph["C"] = ["F"]
    graph["D"] = ["A", "B", "C", "G", "F"]
    graph["E"] = []
    graph["F"] = []
    graph["G"] = ["F", "E"]
```



#### 减治法直接实现拓扑排序

```python
# 减治法——减源拓扑排序
# 不断删除入度为0的点
# Kahn算法是从每个入度为0的顶点出发
def Kahn_topoSort(graph):
    # 记录顶点的输入边数
    nodes = dict()
    # 初始化 顶点统计入nodes
    for key in graph.keys():
        nodes[key] = 0
    # 统计边 输入边统计入nodes
    for _, value_list in graph.items():
        for vertex in value_list:
            nodes[vertex] += 1
    # 减源
    # 如果不空循环删减
    while (nodes):
        for key in list(nodes.keys()):
            # 从字典中删除入度为0的点并输出
            # 并将这个点的输出点 -1
            if nodes[key] == 0:
                # 从统计字典中删除点
                del nodes[key]
                # 减少关联点的入度
                reduceList = graph[key]
                for i in reduceList:
                    nodes[i] -= 1
                # 输出这个被删除的点
                print(key)

```



#### 基于深度优先搜索实现拓扑排序

```python
import random

# 基于dfs的拓扑排序
def DFS_topoSort(graph):
    # 结果栈
    result_Stack = list()
    # 图上的顶点不为空时，随机找点进行dfs
    while (graph):
        # vertex 为取出的顶点
        # 随机一个字典中的key，第二个参数为限制个数
        vertex = random.sample(graph.keys(), 1)[0]
        # 创建dfs栈，跟踪set，
        # 并把随机顶点放入栈中
        stack = list()
        seen = set()
        stack.append(vertex)
        seen.add(vertex)
        # 标记深元素
        deep = ""
        # 当栈不空时继续搜索
        while (len(stack) > 0):
            # 从栈中取元素
            v = stack.pop()
            nodes = graph[v]
            # 如果出度为0 则标记为最深点
            if (len(nodes) == 0):
                deep = v
                continue
            for node in nodes:
                # 如果没见过 就标记并入栈
                if node not in seen:
                    stack.append(node)
                    seen.add(node)

        # 删除最深的元素
        graph.pop(deep)
        for key, value in graph.items():
            for item in value:
                if item == deep:
                    graph[key].remove(deep)
        # 最深的元素入结果栈
        result_Stack.append(deep)
    
    # 输出
    print("dfs 拓扑结果")
    while (result_Stack):
        print(result_Stack.pop(), end=" ")

```

## 生成组合对象的算法

### 生成排列

> 输入n，生成1 - n 的所有序列组合。
>
> 架构：减治法-生成排序  n(n-1)! = n!



#### JohnsonTrotter(生成无序)

```c++
// 排列节点
struct jt_node
{
    int num;
    bool flag; //标记方向，false指向右
};
```



```c++
// 减治法 —— 生成排列
//性能： 生成排列的最有效的算法之一,时间复杂度为O(n!)
void johnsonTrotter(int n)
{
    // 初始化排列
    jt_node *a = new jt_node[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i].num = i;
        a[i].flag = false;
    }

    int k = n;
    jt_node temp;
    // 存在一个移动元素
    while (k != 0)
    {
        // @return 输出排序
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].num << " ";
        }
        cout << endl;

        k = 0;
        // 求最大移动元素k
        for (int i = 1; i <= n; i++)
        {
            if (a[i].flag && a[i].num > a[i + 1].num && a[k].num < a[i].num && i < n)
                k = i;
            else if (i > 1 && !a[i].flag && a[i].num > a[i - 1].num && a[k].num < a[i].num)
                k = i;
        }
        // 把k和它箭头指向的相邻元素互换
        if (k != 0)
        {
            if (a[k].flag)
            {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
                k++;
            }
            else
            {
                temp = a[k - 1];
                a[k - 1] = a[k];
                a[k] = temp;
                k--;
            }
        }
        // 调转所有大于k元素的方向 并输出
        for (int i = 1; i <= n; i++)
        {
            if (a[i].num > a[k].num)
                a[i].flag = (a[i].flag ? false : true);
        }
    }
}
```



#### LexicographicPermute（生成字典序）

```c++
// 以字典序产生排序
// 输入：一个正整数 n
// 输出：在字典序下{1,...,n} 所有排列的列表
void lexicographicPermute(int n)
{
    // 初始化排列
    int *a = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = i;
    }
    // @return +++显示输出初始+++
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    bool isHaveAscend = true; //是否存在两个连续升序
    while (isHaveAscend)
    {
        // 找到a(i)<a(i+1)的i最大值
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i + 1] && maxi < i)
                maxi = i;
        }
        // 找到a(i)<a(j) j的最大索引
        int maxj = maxi;
        for (int j = maxi; j <= n; j++)
        {
            if (a[j] > a[maxi])
                maxj = j;
        }

        // 交换ai和aj
        int temp = a[maxi];
        a[maxi] = a[maxj];
        a[maxj] = temp;

        // 利用栈反序 a[i+1] - a[n]
        stack<int> st;
        for (int i = maxi + 1; i <= n; i++)
        {
            st.push(a[i]);
        }
        for (int i = maxi + 1; i <= n; i++)
        {
            a[i] = st.top();
            st.pop();
        }

        // 判断是否存在两个连续升序
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i + 1] > a[i])
            {
                flag = false;
            }
        }
        if (flag)
            isHaveAscend = false;

        // @return +++显示输出+++
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    delete[] a
}
```



### 生成子集

> 架构：减治法-生成子集-二进制反射格雷码算法
>
> 效果：输入一个 序列，求该序列的所有子序列
>
> 应用：分配问题(求最有价值的子集)
>
> 同类：暴力法-穷举查找

#### 二进制反射格雷码

```c++
// 定义位串
struct bitsNode
{
    list<int> data;
};
/**
 * 
 * 减治法-生成子集-二进制反射格雷码算法
*/ 
list<struct bitsNode> BRGC(int n)
{
    list<struct bitsNode> L;
    if (n == 1)
    {
        // 表l包含位串 0 和 1；
        struct bitsNode init1 ,init2;
        init1.data.push_back(0);
        init2.data.push_back(1);
        L.push_back(init1);
        L.push_back(init2);
    }
    else
    {
        // 递归
        list<struct bitsNode> L1 = BRGC(n - 1);
        // 把表l1倒序复制给l2
        // 高级技巧 链表反转
        list<struct bitsNode> L2(L1.rbegin(), L1.rend());
        for (list<struct bitsNode>::iterator i = L2.begin(); i != L2.end(); i++)
        {
            list<int> t((*i).data.rbegin(), (*i).data.rend());
            i->data = t;
        }
        // 把0加到表l1中的每个位串前
        for (list<struct bitsNode>::iterator i = L1.begin(); i != L1.end(); i++)
        {
            i->data.push_front(0);
        }
        // 把1加到表l2中的每个位串前
        for (list<struct bitsNode>::iterator i = L2.begin(); i != L2.end(); i++)
        {
            i->data.push_front(1);
        }
        // 把表l2添加到表l1后方得到表l
        L.insert(L.end(), L1.begin(), L1.end());
        L.insert(L.end(), L2.begin(), L2.end());
    }
    return L;
}
```



#### 利用二进制反射格雷码生成所有子集



```c++
void PowerSet(int a[], int len)
{
    // 生成格雷码集合
    list<struct bitsNode> bgc = BRGC(len);

    // 取出格雷码
    for (list<struct bitsNode>::iterator i = bgc.begin(); i != bgc.end(); i++)
    {
        list<int> t = i->data;
        vector<int> vertex; // 存放单个格雷码
        for (list<int>::iterator j = t.begin(); j != t.end(); j++)
        {
            vertex.push_back(*j);
        }
        // 通过格雷码生成子集
        for (int i = 0; i < len;i++)
        {
            if(vertex[i] == 1)
            {
                cout << a[i];
            }
        }
        cout << endl;
    }
}
```

**测试输出**

```c++
int main()
{
    int a[3] = {6, 2, 3};
    PowerSet(a,3);
    return 0;
}

/******输出**********
      3
      23
      2
      63
      623
      62
      6
******************/
```



## 减常因子算法



#### 折半查找

> 架构：减治法-减常因子-折半查找
>
> 应用：有序数组的查找
>
> 性能：C<sub>avg</sub>( n ) = log<sub>2</sub>n

```c++
// @params：一个有序数组和它的长度，需要查找的key
// @retrun: key的index
int binarySearch(int a[], int len, int k)
{
    int l = 0, r = len - 1;
    int m;
    while (l <= r)
    {
        m = ((l + r) / 2);
        if (k == a[m])
        {
            return m;
        }
        else if (k < a[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}
```



#### 俄式乘法

> 架构：减治法-减常因子-俄式乘法，位操作
>
> 性能：极高，机器底层的基础操作。



```c++
/**
 *  减治法-减常因子-俄式乘法
 *  n * m = n/2 * 2m
 *  n * m = (n-1)/2 * 2m + m 
*/
int RussianPeasant(int n, int m)
{
    int sum = 0;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            // n * m = n/2 * 2m
            n = n >> 1;
            m = n << 1;
        }
        else
        {
            //n * m = (n-1)/2 * 2m + m
            // m为奇数时，先把 m 存放 sum 中
            // 当 m = 1 时 (n-1)/2 * 2m 被加入sum中
            sum += m;
            n = (n - 1) >> 1;
            m = m << 1;
        }
    }
    return sum;
}
```



#### 约瑟夫斯问题

> J（ 2k ）= 2J( k ) -  1;
>
> J ( 2k + 1 ) = 2J( k ) + 1;





## 减可变规模算法

### 计算中值和选择问题

> 划分问题：将大于a的划分在右侧，小于a的划分在左侧
>
> 选择问题：寻找数列第k个最小元素的问题。



#### Lomuto 减治划分

```python
#
#   lomuto划分：求数列中值
#   架构：减治法-减可变规模-lomuto划分
#   @params l,r,需要规划的开始端和结束端
#

def lomutoPartition(a: list) -> int:
    l = 0
    r = len(a) - 1

    p = a[l]
    s = l
    for i in range(l, r + 1):
        if a[i] < p:
            s += 1
            a[s], a[i] = a[i], a[s]
    a[l], a[s] = a[s], a[l]
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
def quickSelect(a: list, k: int) -> int:
    l = 0
    r = len(a)
    s = lomutoPartition(a)
    if s == (l + k - 1):
        return a[s]
    elif s > (l + k - 1):
        return quickSelect(a[l:s], k)
    else:
        return quickSelect(a[s+1:r], l+k-1-s)

```



```c++
def main():
    a = [0, 27, 3, 6, 2, 1, 7, 8]
    index = quickSelect(a, 5)
    print(index)

```



### 插值查找

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
int interpolationSearch(int a[], int len, int key)
{

    // 搜索的左右索引
    int l = 0, r = len - 1;
    // 选定的索引
    int index = 0;

    while (a[index] != key && l != r)
    {
        // 通过增长率求取近似索引
        int k = growthRate(a[l], a[r], r - l);
        index = (key - a[0]) / k;

        if (a[index] == key)
        {
            return index;
        }
        // 判断正序还是负序
        if (k >= 0)
        {
            // 缩减搜索范围
            if (a[index] > key)
                l = index;
            else
                r = index;
        }
        else
        {
            if (a[index] > key)
                r = index;
            else
                l = index;
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



### 二叉查找树的查找和插入

> 架构：减治法-减可变规模-二叉查找树的插入和查找
>
> 性能：查找 C<sub>avg</sub>= O( log 2 (n) )

```c++
// 二叉查找树节点
struct BST_node
{
    int data;
    BST_node *left;
    BST_node *right;

    BST_node(int _data);
    ~BST_node();
};

BST_node::BST_node(int _data)
{
    data = _data;
    left = nullptr;
    right = nullptr;
}

BST_node::~BST_node()
{
    delete left;
    delete right;
}
```

#### 

```c++
// 二叉查找树类
class BST_tree
{
  protected:
    // 根节点
    struct BST_node *root;

  public:
    // 构造和析构
    BST_tree();
    ~BST_tree();

    // 二叉查找树添加节点
    // item：需要添加的节点数据，t：插入位置，默认传入根节点自动匹配插入位置
    struct BST_node *inseart(int item);
    // 二叉查找树查找
    int search(int key);
};

// 构造函数
BST_tree::BST_tree()
{
    this->root = nullptr;
}

// 释放内存
BST_tree::~BST_tree()
{
    delete root;
}
```

#### 二叉查找树的插入

```c++
// 二叉查找树的插入
struct BST_node *BST_tree::inseart(int item)
{
    BST_node *local = this->root;
    // 不存在根节点时 将数据创建为根节点
    if (this->root == nullptr)
    {
        this->root = new BST_node(item);
        local = this->root;
        return local;
    }
    // 迭代寻找合适的节点插入数据
    while (true)
    {
        // 如果节点适合则插入
        if (local->left == nullptr && item <= local->data)
        {
            local->left = new BST_node(item);
            local = local->left;
            return local;
        }
        if (local->right == nullptr && item >= local->data)
        {
            local->right = new BST_node(item);
            local = local->right;
            return local;
        }
        // 如果节点不适合则切换
        if (local->left != nullptr && item <= local->data)
        {
            local = local->left;
        }
        else if (local->right != nullptr && item >= local->data)
        {
            local = local->right;
        }
    }
    return local;
}
```

#### 二叉查找树的查找

```c++
// 二叉查找树的查找
int BST_tree::search(int key)
{
    // 将当前节点指向根节点
    BST_node *local = this->root;
    while (local != nullptr)
    {
        // 匹配成功则返回数据
        if (key == local->data)
        {
            return local->data;
        }

        // 不匹配则左右切换
        if (key >= local->data)
        {
            local = local->right;
        }
        else if (key <= local->data)
        {
            local = local->left; 
        }
    }
    return local->data;
}
```



### 拈游戏

> 重点：异或操作，nim和

```c++
// 输入：东西的总数和单次获取的限制数量
// 输出：先手的胜负，true 是胜利
bool nim(int total, int limit)
{
    int flag;
    int remain = total % limit;
    flag = limit ^ remain;

    if (flag == 0)
        return false;
    return true;
}
```



<br />

# Ⅲ 分治法

## 合并排序

> 架构：分治法-自上而下合并排序；分治法-自下而上合并排序
>
> 性能：C( n ) = n long<sub>2</sub>n; 需要额外内存空间

### 合并排序-自上而下

```c++
/**
 * 分治法-自上而下合并排序
 * 
*/
void mergeSort(int a[], int l, int r)
{
    if (l == r)
    {
        return;
    }
    int m = (r + l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m + 1, r);
}
```

```c++
// 将数组的两段合并
void merge(int a[], int l, int m, int r)
{
    int i, j, k;

    int LEFT_SINZE = m - l;
    int RIGHT_SINZE = r - m + 1;

    // 将数组分割拷贝成两段
    int left[LEFT_SINZE], right[RIGHT_SINZE];
    for (i = l; i < m; i++)
    {
        left[i - l] = a[i];
    }
    for (i = m; i <= r; i++)
    {
        right[i - m] = a[i];
    }

    // 合并
    i = 0, j = 0, k = l;
    while (i < LEFT_SINZE && j < RIGHT_SINZE)
    {
        if (left[i] < right[j])
        {
            a[k++] = left[i++];
        }
        else
        {
            a[k++] = right[j++];
        }
    }

    // 合并剩余
    while (i < LEFT_SINZE)
    {
        
        a[k++] = left[i++];
        
    }
    while (j < RIGHT_SINZE)
    {
        a[k++] = right[j++];
    }
}
```



### 合并排序-自下而上

```c++
/**
 * 自下而上归并排序
*/
void mergeBuSort(int a[], int len)
{
    // 辅助数组aux；
    int *aux = new int[len];
    for (int sz = 1; sz < len; sz += sz)
    {
        for (int lo = 0; lo < len - sz; lo += sz + sz)
        {
            int t = lo + sz + sz - 1;
            int min = t > len - 1 ? len - 1 : t;
            merge(a, aux, lo, lo + sz - 1, min);
        }
    }

    delete[] aux;
}
```

```c++
// 将a[lo..mid]和 a[mid+1..hi]归并
void merge(int a[], int aux[], int lo, int mid, int hi)
{
    int i = lo, j = mid + 1;
    // 将a[lo..hi]复制到aux[lo..hi]
    for (int k = lo; k <= hi; k++)
    {
        aux[k] = a[k];
    }
    // 归并到a[lo..hi]
    for (int k = lo; k <= hi; k++)
    {
        // 当一个数组归并完毕
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        // 将小的先归并
        else if (aux[j] < aux[i])
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
}
```



## 快速排序

> 架构：分治法-快速排序
>
> 性能：C<sub>avg</sub>=1.39*n*log<sub>2</sub>n

```c++
// 分治法 ->快速排序
// 性能：C平均 = 1.39*n*log2*n
void quickSort(int a[], int lo, int hi)
{
    if (lo < hi)
    {
        int s = HoarePartition(a, lo, hi);
        quickSort(a, lo, s - 1);
        quickSort(a, s + 1, hi);
    }
}
```

```c++
int HoarePartition(int a[], int lo, int hi)
{
	// 以最左边的数(lo)为基准
	int base = a[lo];
	while (lo < hi) {
		// 从序列右端开始，向左遍历，直到找到小于base的数
		while (lo < hi && a[hi] >= base)
			hi--;
		// 找到了比base小的元素，将这个元素放到最左边的位置
		a[lo] = a[hi];
 
		// 从序列左端开始，向右遍历，直到找到大于base的数
		while (lo < hi && a[lo] <= base)
			lo++;
		// 找到了比base大的元素，将这个元素放到最右边的位置
		a[hi] = a[lo];
	}
 
	// 最后将base放到lo位置。此时，lo位置的左侧数值应该都比lo小；
	// 而lo位置的右侧数值应该都比lo大。
	a[lo] = base;
	return lo;
}
```



## 二叉树遍历及其相关特性

### 计算二叉树的高度

> 架构：分治法-二叉树高度搜索
>
> 性能： C(n) = 2n+1

```c++
struct node
{
    char data;
    node *left;
    node *right;
    node(char ch) : data(ch)
    {
        this->left = nullptr;
        this->right = nullptr;
    };
};

int treeHeight(node *t)
{
    if (t == nullptr)
        return -1;
    else
        return max(height(t->left), height(t->right)) + 1;
}

int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}
```



### 二叉树的遍历

> 架构：分治法-二叉树遍历
>
> 性能： C(n) = 2n+1

#### 前序遍历

```c++
// 入栈时输出
void preOrderTraversal(node *root)
{
    if (root != nullptr)
    {
        printf("%c\n", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}
```



#### 中序遍历

```c++
// 中序遍历
// 用于二叉树排序
void inOrderTraversal(node *root)
{
    if (root != nullptr)
    {
        inOrderTraversal(root->left);
        printf("%c\n", root->data);
        inOrderTraversal(root->right);
    }
}
```



#### 后序遍历

```c++
// 后序遍历
// 出栈时输出
void postOrderTraversal(node *root)
{
    if (root != nullptr)
    {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%c\n", root->data);
    }
}
```



## 大整数乘法和Strassen矩阵乘法

### karatsuba 大整数乘法

> 思想：将大数分解为幂指数相加的形式
>
> 架构：分治法-大整数相乘
>
> 性能：A( n ) ∈ Θ ( n<sup>long<sub>2</sub>3</sup>)

```python
# Solve problem: 降低大数相乘的时间复杂度
# Thought： 将大数分解为幂指数相加的形式
# Architecture： 分治法-karatsuba乘法
# performance： n**(long2 3)
# @params {int,int} 需要相乘的两个大数
# @return int 相乘的结果
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



### Strassen矩阵乘法

> 
>

。。。



## 用分治法解最近对问题和凸包问题

### 最近对问题

> 
>

```c++
#pragma one
#include <math.h>
#include <stdio.h>
#include <vector>
#define DBL_MAX 1.7976931348623158e+308  // max value

struct Point {
  double x, y;
};
class CloestPair {
 private:
  int size;
  char flage;
  Point* aux;     // 辅助函数
  Point* axis_x;  // x轴排序
  Point* axis_y;  // y轴排序

  void clean() {
    if (aux != nullptr) delete[] aux;
    if (axis_x != nullptr) delete[] axis_x;
    if (axis_y != nullptr) delete[] axis_y;
  };

  void merge(Point* a, int lo, int mid, int hi) {
    int i = lo, j = mid + 1;
    // copy to aux array
    for (int k = lo; k <= hi; k++) {
      this->aux[k] = a[k];
    }
    if (this->flage == 'x') {
      for (int k = lo; k <= hi; k++) {
        if (i > mid)
          a[k] = aux[j++];
        else if (j > hi)
          a[k] = aux[i++];
        else if (aux[j].x < aux[i].x)
          a[k] = aux[j++];
        else
          a[k] = aux[i++];
      }
    } else if (this->flage == 'y') {
      for (int k = lo; k <= hi; k++) {
        if (i > mid)
          a[k] = aux[j++];
        else if (j > hi)
          a[k] = aux[i++];
        else if (aux[j].y < aux[i].y)
          a[k] = aux[j++];
        else
          a[k] = aux[i++];
      }
    }
  };
  void MergeSort(Point* a, int lo, int hi) {
    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    MergeSort(a, lo, mid);
    MergeSort(a, mid + 1, hi);
    merge(a, lo, mid, hi);
  };
  void copy(Point* from, Point* to, int len) {
    for (int i = 0; i < len; i++) {
      to[i] = from[i];
    }
  };
  double min(double a, double b) {
    if (a > b) {
      return b;
    }
    return a;
  }
  double EfficientClosestPair(Point* P, Point* Q, int _size) {
    double dminsq = DBL_MAX;

    if (_size <= 3) {
      // copy to aux array a;
      // 将点合并到一个辅助数组
      int len = _size * 2;
      Point* a = new Point[len];
      for (int i = 0; i < _size; i++) {
        a[i] = P[i];
      }
      for (int i = _size; i < len; i++) {
        a[i] = Q[i];
      }
      // Brute force method for the shortest distance
      // 蛮力法求最近距离
      for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
          double dis = pow(a[i].x - a[j].x, 2) + pow(a[i].y - a[j].y, 2);
          if (dis != 0 && dis < dminsq) dminsq = dis;
        }
      }
      delete[] a;

    } else {
      int mid = _size / 2;

      Point* Pl = new Point[mid];
      Point* Ql = new Point[mid];
      Point* Pr = new Point[_size - mid];
      Point* Qr = new Point[_size - mid];

      copy(P, Pl, mid);
      copy(Q, Ql, mid);
      copy(P, Pr, _size - mid);
      copy(Q, Qr, _size - mid);

      double Dl = EfficientClosestPair(Pl, Ql, mid);
      double Dr = EfficientClosestPair(Pr, Qr, _size - mid);

      double d = min(Dl, Dr);
      double m = P[(_size / 2) - 1].x;

      std::vector<Point> vec;
      for (int i = 0; i < _size; i++) {
        if (abs(Q[i].x - m) < d) {
          vec.push_back(Q[i]);
        }
      }
      dminsq = pow(d, 2);

      int num = vec.size();
      for (int i = 0; i < num; i++) {
        int k = i + 1;
        while (k <= num - 1 && pow(vec[k].y - vec[i].y, 2) < dminsq) {
          double t = pow(vec[k].x - vec[i].x, 2) + pow(vec[k].y - vec[i].y, 2);
          dminsq = min(t, dminsq);
          k++;
        }
      }
    }

    return sqrt(dminsq);
  };

 public:
  // 构造函数
  CloestPair() {
    this->aux = nullptr;
    this->axis_x = nullptr;
    this->axis_y = nullptr;
  };

  // 析构函数
  ~CloestPair() { this->clean(); };

  // 计算最近对
  double solveCloestPair(Point* a, int _size) {
    // 先清理内存
    this->clean();

    // 分配内存
    size = _size;
    aux = new Point[size]();
    axis_x = new Point[size]();
    axis_y = new Point[size]();

    // 复制内容
    for (int i = 0; i < _size; i++) {
      axis_x[i] = a[i];
      axis_y[i] = a[i];
    }

    // 排序
    flage = 'x';
    MergeSort(axis_x, 0, _size - 1);
    flage = 'y';
    MergeSort(axis_y, 0, _size - 1);

    // 分治求最短距离
    return EfficientClosestPair(axis_x, axis_y, this->size);
  }
};
```

测试

```c++
int main() {
  int n = 20;

  CloestPair* cp = new CloestPair();
  Point a[] = {{1, 3}, {2, 7}, {1, 8}, {6, 0}};
  double dis = cp->solveCloestPair(a, 4);
  delete cp;
  printf("min dist: %lf\n", dis);
  return 0;
}
```



### 凸包问题

> 
>

…



<br />

# Ⅳ 变治法

## 预排序

>思想：有序列表更容易求解。

### 检测数组中元素的唯一性

```javascript
/**
 * @description 预排序检测数组唯一性
 * @param {array} a 
 * @returns {boolean}
 */
function PresortElementUniqueness(a) {
    let t = a.concat();
    mergeSort(t);
    for (let i = 0; i <= t.length - 2; i++) {
        if (t[i] == t[i + 1]) return false;
    }
    return true;
}

/**
 * @description 分治法-自下而上的归并排序
 * @param {array} a 
 */
function mergeSort(a) {
    let n = a.length;
    let aux = new Array(n);

    let min = (m, n) => m > n ? n : m;

    let merge = (a, lo, mid, hi) => {
        let i = lo, j = mid + 1;
        for (let k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }
        for (let k = lo; k <= hi; k++) {
            if (i > mid)                a[k] = aux[j++];
            else if (j > hi)            a[k] = aux[i++];
            else if (aux[j] < aux[i])   a[k] = aux[j++];
            else                        a[k] = aux[i++];
        }
    }

    for (let sz = 1; sz < n; sz += sz) {
        for (let lo = 0; lo < n - sz; lo += sz + sz) {
            merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
        }
    }
}
```

测试

```javascript
function main() {
    let a = [3, 5, 6, 7, 8, 2, 8, 34, 6, 23, 12, 24, 6, 37, 7];
    console.log(PresortElementUniqueness(a));
}
```



### 模式计算

```javascript

/**
 * @description 预排序检测数组频率出现最多的元素
 * @param {array} a 
 * @returns {boolean}
 */
function PresortMode(a) {
    let t = a.concat();
    mergeSort(t);
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

/**
 * @description 分治法-自下而上的归并排序
 * @param {array} a 
 */
function mergeSort(a) {
    let n = a.length;
    let aux = new Array(n);

    let min = (m, n) => m > n ? n : m;

    let merge = (a, lo, mid, hi) => {
        let i = lo, j = mid + 1;
        for (let k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }
        for (let k = lo; k <= hi; k++) {
            if (i > mid) a[k] = aux[j++];
            else if (j > hi) a[k] = aux[i++];
            else if (aux[j] < aux[i]) a[k] = aux[j++];
            else a[k] = aux[i++];
        }
    }

    for (let sz = 1; sz < n; sz += sz) {
        for (let lo = 0; lo < n - sz; lo += sz + sz) {
            merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
        }
    }
}
```

测试

```javascript
function main() {
    let a = [1, 1, 8, 5, 5, 6, 8, 8, 34, 6, 7, 5, 8, 6, 2, 5, 9, 10, 5];
    console.log(PresortMode(a));
}
```



### 查找问题

>架构:	先排序再进行折半查找。
>
>性能: 	T<sub>sort</sub>( n ) + T<sub>search</sub> = Θ(n log n) + Θ(long n)
>
> 如果我们要在同一个列表中进行多次查找，在排序上花费一些时间是值得的。

```javascript

/**
 * @description 变治法-预排序查找
 * @param {array} a  
 * @param {int} key 
 */
function PresortSearch(a, key) {
    let t = a.concat();
    let l = 0, r = t.length - 1, m = 0;
    mergeSort(t);
    while (l <= r) {
        m = parseInt((l + r) / 2);
        if (t[m] == key) {
            return m;
        }
        if (key < a[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    return -1;
}


/**
 * @description 分治法-自下而上的归并排序
 * @param {array} a 
 */
function mergeSort(a) {
    let n = a.length;
    let aux = new Array(n);

    let min = (m, n) => m > n ? n : m;

    let merge = (a, lo, mid, hi) => {
        let i = lo, j = mid + 1;
        for (let k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }
        for (let k = lo; k <= hi; k++) {
            if (i > mid) a[k] = aux[j++];
            else if (j > hi) a[k] = aux[i++];
            else if (aux[j] < aux[i]) a[k] = aux[j++];
            else a[k] = aux[i++];
        }
    }

    for (let sz = 1; sz < n; sz += sz) {
        for (let lo = 0; lo < n - sz; lo += sz + sz) {
            merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
        }
    }
}

```

测试
```javascript
function main() {
    let a = [3, 5, 7, 1, 9, 2, 3, 5, 7, 8, 9, 9, 0, 3, 12, 1, 14, 20, 17, 10]
    console.log(PresortSearch(a, 8));
}
```



## 高斯消去法

### 部分选主元法

```python
def betterForwardElimination(matrix:list,vector:list)->list:
    lenth = len(matrix)
    for i in range(lenth):
        matrix[i].append(vector[i])
    for i in range(lenth):
        pivotrow = i
        for j in range(i+1,lenth):
            if abs(matrix[j][i])>abs(matrix[pivotrow][i]):
                pivotrow = j
        for k in range(i,lenth+1):
            matrix[i][k],matrix[pivotrow][k] = matrix[pivotrow][k],matrix[i][k]
        for j in range(i+1,lenth):
            t = matrix[j][i]/matrix[i,i]
            for k in range(i,lenth+1):
                matrix[j][k] = matrix[j][k] - matrix[i][k]*t
    return []
```



### LU分解



### 计算矩阵的逆



### 计算矩阵的行列式





## 平衡查找树

### AVL 树

### 2-3 树

### 红黑树

