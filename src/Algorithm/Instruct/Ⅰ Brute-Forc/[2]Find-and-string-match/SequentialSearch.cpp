#include <bits/stdc++.h>

using namespace std;

// 暴力法——顺序查找
// 时间复杂度：T(n) = θ(n)
int SequentialSearch(int arr[], int len, int key)
{
    // 创建一个新数组 比原来数组长度+1
    int newArr[len + 1];
    for (int i = 0; i < len; i++)
    {
        newArr[i] = arr[i];
    }
    // 新数组最后一项为传入的 key
    newArr[len] = key;

    int j = 0;
    while (newArr[j] != key)
    {
        j++;
    }

    if (j == len)
    {
        return -1;
    }

    return j;
}

int main()
{
    int a[8] = {1, 3, 4, 2, 5, 6, 7, 8};
    cout << "index: "<< SequentialSearch(a, 8, 8) << endl;
    return 0;
}