#include <iostream>

using namespace std;

int main()
{
    int data[101], right[101];
    int i, n, t, len;

    //往数组内存放数字
    cin >> n;
    for (i = 0; i <= n; i++)
    {
        cin >> data[n];
    }
    len = n;
    //初始right
    for (i = 1; i <= n; i++)
    {
        if (i != n)
            right[i] = i + 1;
        else
            right[i] = 0;
    }

    len++;
    cin >> data[len];

    t = 1;
    while (t != 0)
    {
        if (data[right[t]] > data[len])
        {
            right[len] = right[t];
            right[t] = len;
            break;
        }
        t = right[t];
    }
    t = 1;
    while (t != 0)
    {
        cout << data[t] << endl;
        t = right[t];
    }

    /* code */
    return 0;
}
