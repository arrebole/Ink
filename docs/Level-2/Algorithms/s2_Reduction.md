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



#### LexicographicPermute（生成有序）

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

>
>
>