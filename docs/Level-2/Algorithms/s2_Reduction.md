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

>架构1：基于减治法、源删除算法。
>
>架构2：基于暴力法-DFS,输出DFS的逆序
>
>性能：T(n) = O(n+e)



##### 图的表示

```c++
    map<string, vector<string>> graph;
    graph["a"] = {"b","c"};
    graph["b"] = {"e","g"};
    graph["c"] = {"f"};
    graph["d"] = {"a", "b", "g", "f","c"};
    graph["e"] = {};
    graph["f"] = {};
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

