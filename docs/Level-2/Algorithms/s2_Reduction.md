# 减治法

## 直接插入排序

>思想：减治法-减常因子
>
>注释：小数组每次长度+1进行排序。
>
>性能：C<sub>worst</sub> = θ( n<sup>2</sup> ); C<sub>bast</sub> = θ( n ); C<sub>avg</sub> ≈ 1/4 n<sup>n</sup>  = θ ( n<sup>2</sup> )



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

>思想：基于直接插入排序
>
>性能：优于直接插入排序



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

>架构：1、基于减治法、源删除Kahn算法。2、基于暴力法-DFS,输出DFS的逆序
>
>区别：Kahn算法是从每个**入度为0**的顶点出发。基于dfs 是对每个**出度为0**的顶点进行dfs
>
>性能：T(n) = O(n+e)
>
>应用：有向图的排序



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

>输入n，生成1 - n 的所有序列组合。
>
>架构：减治法-生成排序  n(n-1)! = n!



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
void lexicographicPermute(const int n)
{
    // 初始化排列
    int a[n + 1];
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
}
```



### 生成子集

>架构：减治法-生成子集-二进制反射格雷码算法
>
>效果：输入一个 序列，求该序列的所有子序列
>
>应用：分配问题(求最有价值的子集)
>
>同类：暴力法-穷举查找

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

*** 测试输出 ***

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

>架构：减治法-减常因子-折半查找
>
>应用：有序数组的查找
>
>性能：C<sub>avg</sub>( n ) = log<sub>2</sub>n

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

>架构：减治法-减常因子-俄式乘法，位操作
>
>性能：极高，机器底层的基础操作。



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

>J（ 2k ）= 2J( k ) -  1;
>
>J ( 2k + 1 ) = 2J( k ) + 1;





## 减可变规模算法

### 计算中值和选择问题

>划分问题：将大于a的划分在右侧，小于a的划分在左侧
>
>选择问题：寻找数列第k个最小元素的问题。



#### Lomuto 减治划分

```c++
/**
 *  lomuto划分：求数列中值
 *  架构：减治法-减可变规模-lomuto划分
 *  @params l,r,需要规划的开始端和结束端
*/
int lomutoPartition(int a[], int l,int r)
{
    int p = a[0];
    int s = l;
    for (int i = l + 1; i <= r; i++)
    {
        // 如果比p小则扩大s段
        if (a[i] < p)
        {
            s++;
            int t = a[s];
            a[s] = a[i];
            a[i] = t;
        }
    }
    return s;
}
```



#### 快速选择

>架构：反复调用Lomuto划分找到数组中第n小的数
>
>性能：C<sub>worst</sub> = Θ( n<sup>2</sup> )

```c++
#include "lomutoPartition.h"
/**
 * 快速选择是一种从无序列表找到第k小元素的选择算法。
 * 具有很好的平均时间复杂度，然而最坏时间复杂度则不理想.
 * 性能： 从O(n log n)至O(n)，不过最坏情况仍然是O(n2)。
*/
int quickSelect(int a[], int len, int k)
{
    int l = 0, r = len - 1;

    int partitionIdx = lomutoPartition(a, l, r);

    while (l <= r)
    {
        //索引从0开始，需要-1
        if ((k - 1) == partitionIdx)
        {
            break;
        }
        else if ((k - 1) < partitionIdx)
        {
            r = partitionIdx - 1;
        }
        else
        {
            l = partitionIdx + 1;
        }

        partitionIdx = lomutoPartition(a, l, r);
    }
    return a[partitionIdx];
}
```



```c++
int main()
{
    int a[] = {1, 3, 4, 7, 9, 2, 0, 4, 5};
    printf("min 3th of a: %d", quickSelect(a, 9, 3));
    return 0;
}
```



### 插值查找

>架构：查字典思想，通过增长率优化版本的二分查找，只适用于有序数组
>
>性能：与数列均匀度有关，C<sub>best</sub> = O(1);

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

>
>
>

### 拈游戏

>
>
>