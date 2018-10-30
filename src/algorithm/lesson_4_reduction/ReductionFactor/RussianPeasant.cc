#include <bits/stdc++.h>

using namespace std;

/**
 *  减治法-减常因子-俄式乘法
 *  n * m = n/2 * 2m
 *  n * m = (n-1)/2 * 2m + m 
*/
int RussianPeasant(int n, int m)
{
    int sum = 0;
    while (n > 0)
    {
        if (n % 2 == 0)
        {
            // n * m = n/2 * 2m
            n /= 2;
            m *= 2;
        }
        else
        {
            //n * m = (n-1)/2 * 2m + m
            // 先把 m 存放 sum 中
            // 当 m = 1 时 (n-1)/2 * 2m 被加入sum中
            sum += m;
            n = (n - 1) / 2;
            m *= 2;
        }
    }
    return sum;
}

int main()
{
    cout << RussianPeasant(6, 8) << endl;
    return 0;
}