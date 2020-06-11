
// climbStairs 爬楼梯
// 🗡动态规划
int climbStairs(int n){
    if(n <= 1) return 1;

    // n = (n-1) + (n-2) 
    // => 尾递归 c(1) = 1, c(2) = 2, c(3) = c(2) + c(1), c(4) = c(3) + c(2)
    int c0 = 1, c1 = 2, t;
    for(int i = 2; i < n; i++){
        t = c1;
        c1 = c0 + c1;
        c0 = t;
    }

    return c1;
}