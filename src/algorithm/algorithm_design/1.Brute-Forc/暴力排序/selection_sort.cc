// swap It swap two int
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//  selection_sort 将输入的int数组进行选择排序
//  时间复杂度：θ(n^2) 键的交换次数为 θ(n)
//  空间复杂度：0
void selection_sort(int * data, int len){
    for (int i = 0; i < len - 1; i++){
        int minKey = i;
        for (int j = i + 1; j < len; j++){
            // find min key
            if (data[j] < data[minKey]) minKey = j;
        }
        swap(&data[i], &data[minKey]);
    }
}

