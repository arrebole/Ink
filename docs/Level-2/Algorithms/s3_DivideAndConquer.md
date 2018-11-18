# 分治法

## 合并排序

>架构：分治法-自上而下合并排序；分治法-自下而上合并排序
>
>性能：C( n ) = n long<sub>2</sub>n; 需要额外内存空间

#### 合并排序-自上而下

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



#### 合并排序-自下而上

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

