/*------------------------------------

    求最大公约数

---------------------------------------*/
#include <bits/stdc++.h>

using namespace std;

//++++++++++++++++++++++++++++++++++++++++++++++

// 欧几里得算法(辗转相除法)
// gcd(m,n) = gcd(n,m mod n)
// 退出条件: n = 0
// gcd(60,24) = gcd(24,12) = gcd(12,0) = 12
int Euclid_gcd(int m, int n)
{
    int r;
    while (n != 0)
    {
        r = m % n;
        m = n;
        n = r;
    }

    return m;
}

//++++++++++++++++++++++++++++++++++++++++++

// 连续整数检测法
// 暴力法———不断减小尝试
int Exhaustive_gcd(int m, int n)
{
    int result;

    // 1、取t = min{m,n}
    int t;
    (m > n) ? t = n : t = m;

    while (true)
    {
        // 2、如果t能被 m,n 整除则t为最大公约数
        if (m % t == 0)
        {
            if (n % t == 0)
            {
                result = t;
                break;
            }
        }
        // 3、t反复减小一
        t--;
    }
    return result;
}

//++++++++++++++++++++++++++++++++++++++++++++
int *sieve(int n)
{
    // 初始化标记列表
    int *intList = new int[n + 1];
    for (int i = 2; i <= n; i++)
    {
        intList[i] = i;
    }

    // 筛选倍数关系
    for (int p = 2; p <= (int)sqrt(n); p++)
    {
        if (intList[p] != 0)
        {
            int j = p * p;
            while (j <= n)
            {
                intList[j] = 0;
                j = j + p;
            }
        }
    }

    int i = 0;
    int *result = new int[n];
    // 整理数组
    for (int p = 2; p <= n; p++)
    {
        if (intList[p] != 0)
        {
            result[i] = intList[p];
            i++;
        }
    }

    delete[] intList;
    return result;
}

int main()
{
    int m = 31415, n = 14142;
    // 测试最大公约数算法
    cout << Euclid_gcd(m, n) << endl;
    cout << Exhaustive_gcd(m, n) << endl;
    cout << "埃拉托色尼筛选法" << endl;

    // 测试埃拉托色尼筛选法
    int *siv = sieve(100);
    int i = 0;
    while (siv[i] != 0)
    {
        cout << siv[i] << endl;
        i++;
    }

    delete[] siv;

    return 0;
}