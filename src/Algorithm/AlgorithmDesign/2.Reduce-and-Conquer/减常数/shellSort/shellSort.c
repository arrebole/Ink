// shellSort 插入排序的一种缩小增量排序
// 步长的选择是希尔排序的重要部分 T = θ(2^n) ~ θ(nlog^2n)
void shellSort(int a[], const int len){
    int gap = 1, j, temp;
    while (gap < len / 3) gap = 3 * gap + 1;
    while (gap >= 1){
        for (int i = gap; i < len; i++){
            temp = a[i];
            // 将 a[j] 插入到 a[j-grap], a[i-2*gap], a[i-3*gap]中
            for(j = i - gap; j >= 0 && a[j] > temp;  j -= gap)
                a[j + gap] = a[j];
            a[j + gap] = temp;
        }
        gap = gap / 3;
    }
}