
// 将数组的两段合并
void merge(int a[], int l, int m, int r){
    int i, j, k;

    int LEFT_SINZE = m - l;
    int RIGHT_SINZE = r - m + 1;

    // 将数组分割拷贝成两段
    int left[LEFT_SINZE], right[RIGHT_SINZE];
    for (i = l; i < m; i++)  left[i - l] = a[i];
    for (i = m; i <= r; i++) right[i - m] = a[i];

    // 合并
    i = 0, j = 0, k = l;
    while (i < LEFT_SINZE && j < RIGHT_SINZE){
        if (left[i] < right[j]) a[k++] = left[i++];
        else                    a[k++] = right[j++];
    }

    // 合并剩余
    while (i < LEFT_SINZE)   a[k++] = left[i++];
    while (j < RIGHT_SINZE)  a[k++] = right[j++];

}

/**
 * 分治法-自上而下合并排序
 * 
*/
void mergeSort(int a[], int l, int r){
    if (l == r) return;
    
    int m = (r + l) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m + 1, r);
}
