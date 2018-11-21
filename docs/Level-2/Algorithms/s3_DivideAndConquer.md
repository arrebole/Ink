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



## 快速排序

>架构：分治法-快速排序
>
>性能：C<sub>avg</sub>=1.39*n*log<sub>2</sub>n

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

#### 计算二叉树的高度

>架构：分治法-二叉树高度搜索
>
>性能： C(n) = 2n+1

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



#### 二叉树的遍历

>架构：分治法-二叉树遍历
>
>性能： C(n) = 2n+1

##### 前序遍历

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



##### 中序遍历

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



##### 后序遍历

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

