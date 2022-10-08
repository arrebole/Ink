// copy 将 a复制到b 个数为len
void copy(int* a, int*b, int len){
    for (int i = 0; i < len; i++) {
        b[i] = a[i];
    }
}

// SequentialSearch 简单的将给定列表的连续元素和给定查找键比较
// trick：将查找键添加到列表的末尾，查准必定会成功，就不需要在循环时判断是否越界
// 时间复杂度：T(n) = θ(n)
int SequentialSearch(int* data, int len, int key)
{
    // 创建一个新数组 比原来数组长度+1
    int aux[len + 1];
    copy(data, aux, len);
    
    // 新数组最后一项为传入的 key
    aux[len] = key;

    int result = 0;
    while (aux[result] != key) result++;

    if (result == len) return -1;
    return result;
}