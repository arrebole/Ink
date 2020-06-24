
// mySql 近似算法-牛顿法解平方根
int mySqrt(int a){
    if (a == 0) return 0;
    
    long long int x = a;
    while(  x > (a / x) ){
        x = (x + a/x) / 2;
    }
    return (int)x;
}