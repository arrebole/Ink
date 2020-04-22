
// insertionSort 
// f (array[n+1]) = f (array[n]) 
// 时间复杂度  θ( n^2 ) - θ( n );
void insertionSort(int* a, int len){
    //小数组递增, 自下而上
    for (int i = 1; i < len; i++){
        //从第二个元素开始，取出该元素，进行比较排序
        int loacl = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > loacl){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = loacl;
    }
}