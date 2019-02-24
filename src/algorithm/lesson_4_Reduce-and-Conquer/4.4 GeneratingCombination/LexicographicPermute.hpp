#include <bits/stdc++.h>

using namespace std;

// 以字典序产生排序
// 输入：一个正整数 n
// 输出：在字典序下{1,...,n} 所有排列的列表
void lexicographicPermute(const int n)
{
    // 初始化排列
    int a[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = i;
    }
    // 显示输出初始
    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    bool isHaveAscend = true; //是否存在两个连续升序
    while (isHaveAscend)
    {
        // 找到a(i)<a(i+1)的i最大值
        int maxi = 0;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i + 1] && maxi < i)
                maxi = i;
        }
        // 找到a(i)<a(j) j的最大索引
        int maxj = maxi;
        for (int j = maxi; j <= n; j++)
        {
            if (a[j] > a[maxi])
                maxj = j;
        }

        // 交换ai和aj
        int temp = a[maxi];
        a[maxi] = a[maxj];
        a[maxj] = temp;

        // 反序 a[i+1] - a[n]
        stack<int> st;
        for (int i = maxi + 1; i <= n; i++)
        {
            st.push(a[i]);
        }
        for (int i = maxi + 1; i <= n; i++)
        {
            a[i] = st.top();
            st.pop();
        }

        // 判断是否存在两个连续升序
        bool flag = true;
        for (int i = 1; i < n; i++)
        {
            if (a[i + 1] > a[i])
            {
                flag = false;
            }
        }
        if (flag)
            isHaveAscend = false;

        // 显示输出
        for (int i = 1; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
}