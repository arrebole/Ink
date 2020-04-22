// swap It swap two int
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}


//   bubble_sort 参数为需要排序的数组，数组的长度
//   时间复杂度：θ(n^2) 键的交换次数为 θ(n^2); 
void bubble_sort(int data[], int len){
    for (int i = 0; i < len - 1; i++){
        for (int j = 0; j < len - 1 - i; j++){           
            if (data[j] > data[j + 1]) 
                swap(&data[j], &data[j + 1]);
        }
    }
}