#include <bits/stdc++.h>

using namespace std;

struct bitsNode
{
    list<int> data;
};
list<struct bitsNode> BRGC(int n)
{
    list<struct bitsNode> L;
    if (n == 1)
    {
        // 表l包含位串 0 和 1；
        struct bitsNode init1, init2;
        init1.data.push_back(0);
        init2.data.push_back(1);
        L.push_back(init1);
        L.push_back(init2);
    }
    else
    {
        // 递归
        list<struct bitsNode> L1 = BRGC(n - 1);
        // 把表l1倒序复制给l2
        // 高级技巧 链表反转
        list<struct bitsNode> L2(L1.rbegin(), L1.rend());
        for (list<struct bitsNode>::iterator i = L2.begin(); i != L2.end(); i++)
        {
            list<int> t((*i).data.rbegin(), (*i).data.rend());
            i->data = t;
        }
        // 把0加到表l1中的每个位串前
        for (list<struct bitsNode>::iterator i = L1.begin(); i != L1.end(); i++)
        {
            i->data.push_front(0);
        }
        // 把1加到表l2中的每个位串前
        for (list<struct bitsNode>::iterator i = L2.begin(); i != L2.end(); i++)
        {
            i->data.push_front(1);
        }
        // 把表l2添加到表l1后方得到表l
        L.insert(L.end(), L1.begin(), L1.end());
        L.insert(L.end(), L2.begin(), L2.end());
    }
    return L;
}

void PowerSet(int a[], int len)
{
    // 生成格雷码集合
    list<struct bitsNode> bgc = BRGC(len);

    // 取出格雷码
    for (list<struct bitsNode>::iterator i = bgc.begin(); i != bgc.end(); i++)
    {
        list<int> t = i->data;
        vector<int> vertex; // 存放单个格雷码
        for (list<int>::iterator j = t.begin(); j != t.end(); j++)
        {
            vertex.push_back(*j);
        }
        // 通过格雷码生成子集
        for (int i = 0; i < len;i++)
        {
            if(vertex[i] == 1)
            {
                cout << a[i];
            }
        }
        cout << endl;
    }
}

int main()
{
    int a[3] = {6, 2, 3};
    PowerSet(a,3);
    return 0;
}