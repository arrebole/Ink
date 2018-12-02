# 分治法

## 合并排序

>架构：分治法-自上而下合并排序；分治法-自下而上合并排序
>
>性能：C( n ) = n long<sub>2</sub>n; 需要额外内存空间

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

### 计算二叉树的高度

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



### 二叉树的遍历

>架构：分治法-二叉树遍历
>
>性能： C(n) = 2n+1

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

>思想：将大数分解为幂指数相加的形式
>
>架构：分治法-大整数相乘
>
>性能：A( n ) ∈ Θ ( n<sup>long<sub>2</sub>3</sup>)

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
>



##  用分治法解最近对问题和凸包问题

### 最近对问题

>
>
>



### 凸包问题

>
>
>