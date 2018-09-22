

/*-------------------------------------------------

    递归实现斐波那契数 update: 2018-9-22 

---------------------------------------------------*/

#include <iostream>

using namespace std;

// 普通递归 时间复杂度O(2^N),空间复杂度O(n)
int fibonacci(int n);

// 优化递归 时间复杂度O(n) 尾递归 类似迭代法
int fibonacci(int a, int b, int n);

//迭代法
int fibonacci2(int n);

int main()
{
    //获取需要数列长度
    int len;
    cin >> len;

    // 处理输入错误
    if (len <= 0)
    {
        cout << "error" << endl;
        return 0;
    }

    // 输出数列
    for (int i = 0; i < len; i++)
    {
        cout << fibonacci(i) << endl;
        cout << fibonacci(1, 1, i) << endl;
        cout << fibonacci2(i) << endl;
        cout << "<<<<<<<<<<" << endl;
    }

    /* code */
    return 0;
}

// 未优化实现
int fibonacci(int n)
{
    if (n < 3)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

// 优化实现
// 类似迭代法
int fibonacci(int a, int b, int n)
{
    if (n < 3)
    {
        return b;
    }

    return fibonacci(b, a + b, n - 1);
}

//迭代法
int fibonacci2(int n)
{
    int f0 = 1;
    int f1 = 1;
    int sum = 0;
    if (n < 3)
    {
        return 1;
    }

    /*
        循环交换 f0->f1 f1->sum sum->f0+f1
    */
    for (int i = 3; i <= n; i++)
    {
        sum = f0 + f1;
        f0 = f1;
        f1 = sum;
    }

    return sum;
}