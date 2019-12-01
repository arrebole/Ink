
/**
 *  减治法-减常因子-俄式乘法
 *  n * m = n/2 * 2m
 *  n * m = (n-1)/2 * 2m + m 
*/
int RussianPeasant(int n, int m){
    int sum = 0;
    while (n > 1){
        // n * m = n/2 * 2m
        if (n % 2 == 0){
            n = n >> 1;
            m = m << 1;
        }
        //n * m = (n-1)/2 * 2m + m
        else{
            // 先把 m 存放 sum 中
            // 当 m = 1 时 (n-1)/2 * 2m 被加入sum中
            n = (n - 1) >> 1;
            sum += m;
            m = m << 1;
        }
    }
    return (sum + m);
}