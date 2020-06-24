// @params：一个有序数组和它的长度，需要查找的key
// @retrun: key的index
int binarySearch(int a[], int len, int k){
    int lo = 0, hi = len - 1;
    while (lo <= hi){
        int m = ((lo + hi) / 2);
        if (k == a[m])      return m;
        else if (k < a[m])  hi = m - 1;
        else                lo = m + 1;
    }
    return -1;
}