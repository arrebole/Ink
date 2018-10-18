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

