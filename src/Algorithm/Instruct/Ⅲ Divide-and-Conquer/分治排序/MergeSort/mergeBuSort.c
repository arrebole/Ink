#include <stdlib.h>

// 将a[lo..mid]和 a[mid+1..hi]归并
void merge(int a[], int aux[], int lo, int mid, int hi){
    int i = lo, j = mid + 1;
    // 将a[lo..hi]复制到aux[lo..hi]
    for (int k = lo; k <= hi; k++)  aux[k] = a[k];
    
    // 归并到a[lo..hi]
    for (int k = lo; k <= hi; k++){
        if (i > mid)                a[k] = aux[j++];
        else if (j > hi)            a[k] = aux[i++];
        else if (aux[j] < aux[i])   a[k] = aux[j++];
        else                        a[k] = aux[i++];
    }
}


/**
 * 自下而上归并排序
*/
void mergeBuSort(int a[], int len){
    // 辅助数组aux；
    int *aux = (int *)malloc(sizeof(int) * len);
    for (int sz = 1; sz < len; sz += sz){
        for (int lo = 0; lo < len - sz; lo += sz + sz){
            int t = lo + sz + sz - 1;
            int min = t > len - 1 ? len - 1 : t;
            merge(a, aux, lo, lo + sz - 1, min);
        }
    }

    free(aux);
}

