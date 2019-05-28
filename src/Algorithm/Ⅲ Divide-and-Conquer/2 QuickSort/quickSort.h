
void swapEle(int *a, int *b);
void quickSort(int a[], int lo, int hi);
int partition(int a[], int lo, int hi);

// 分治法 ->快速排序
// 性能：C平均 = 1.39*n*log2*n
void quickSort(int a[], int lo, int hi)
{
    if (lo < hi)
    {
        int s = partition(a, lo, hi);
        quickSort(a, lo, s - 1);
        quickSort(a, s + 1, hi);
    }
}

int partition(int a[], int lo, int hi)
{
    // 选择中轴 p
    int p = a[lo];
    int i = lo, j = hi;
    while (i < j)
    {
        while(i<j && a[j]>=p)
        {
            j--;
        }
        while(i<j && a[i]<=p)
        {
            i++;
        }
        swapEle(&a[i], &a[j]);
    }
    // 中轴归位
    swapEle(&a[lo], &a[j]);
    return j;
}

void swapEle(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}