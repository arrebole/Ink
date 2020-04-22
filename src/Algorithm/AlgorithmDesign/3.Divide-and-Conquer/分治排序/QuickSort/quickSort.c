
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
// 分治法 ->快速排序
// 性能：C平均 = 1.39*n*log2*n
void quickSort(int a[], int lo, int hi){
    if (lo < hi){
        int s = HoarePartition(a, lo, hi);
        quickSort(a, lo, s - 1);
        quickSort(a, s + 1, hi);
    }
}

