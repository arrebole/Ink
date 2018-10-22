#include <bits/stdc++.h>

using namespace std;

// 排列节点
struct jt_node
{
    int num;
    bool flag; //标记方向，false指向右
};

void johnsonTrotter(int n)
{
    // 初始化排列
    jt_node *a = new jt_node[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i].num = i;
        a[i].flag = false;
    }

    int k = n;
    jt_node temp;
    // 存在一个移动元素
    while (k != 0)
    {
        // @return 输出排序
        for (int i = 1; i <= n; i++)
        {
            cout << a[i].num << " ";
        }
        cout << endl;

        k = 0;
        // 求最大移动元素k
        for (int i = 1; i <= n; i++)
        {
            if (a[i].flag && a[i].num > a[i + 1].num && a[k].num < a[i].num && i < n)
                k = i;
            else if (i > 1 && !a[i].flag && a[i].num > a[i - 1].num && a[k].num < a[i].num)
                k = i;
        }
        // 把k和它箭头指向的相邻元素互换
        if (k != 0)
        {
            if (a[k].flag)
            {
                temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
                k++;
            }
            else
            {
                temp = a[k - 1];
                a[k - 1] = a[k];
                a[k] = temp;
                k--;
            }
        }
        // 调转所有大于k元素的方向 并输出
        for (int i = 1; i <= n; i++)
        {
            if (a[i].num > a[k].num)
                a[i].flag = (a[i].flag ? false : true);
        }
    }
}