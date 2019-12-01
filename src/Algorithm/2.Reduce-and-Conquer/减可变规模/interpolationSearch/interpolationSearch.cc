
// 计算增长率
int growthRate(int a, int b, int num)
{
    return (a + b) / num;
}

/**
 *  插值查找：减治法-减可变规模-插值查找
 *  输入：顺序数组，数组长度，需要查找的key
 *  输出：key对应的索引，如果没有则返回-1；
 * 
*/
int interpolationSearch(int a[], int len, int key){

    // 搜索的左右索引
    int l = 0, r = len - 1;
    // 选定的索引
    int index = 0;

    while (a[index] != key && l != r){
        // 通过增长率求取近似索引
        int k = growthRate(a[l], a[r], r - l);
        index = (key - a[0]) / k;
        
        // 命中
        if (a[index] == key) return index;

        // 判断正序还是负序
        if (k >= 0){
            // 缩减搜索范围
            if (a[index] > key) l = index;
            else                r = index;
        }
        else{
            if (a[index] > key) r = index;
            else                l = index;
        }
    }

    return -1;
}

