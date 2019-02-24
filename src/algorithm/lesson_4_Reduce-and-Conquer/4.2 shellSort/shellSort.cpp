#include <bits/stdc++.h>

using namespace std;
void shell_Sort(int a[], const int len)
{
    int gap = 1;
    while (gap < len / 3)
    {
        gap = 3 * gap + 1;
    }
    while (gap >= 1)
    {
        for (int i = gap; i < len; i++)
        {
            int v = a[i];
            int j = i - gap;
            while (j >= 0 && a[j] > v)
            {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = v;
        }
        gap = gap / 3;
    }

}

void shellSort(int a[], const int len)
{
    int N = len;
    int h = 1;
    while (h < N / 3)
    {
        h = 3 * h + 1;
    }
    while (h >= 1)
    {
        for (int i = h; i < N; i++)
        {
            for (int j = i; j >= h && a[j] < a[j - h]; j -= h)
            {
                int temp = a[j];
                a[j] = a[j - h];
                a[j - h] = temp;
            }
        }
        h = h / 3;
    }
}

int main()
{
    int a[11] = {2, 4, 1, 5, 6, 9, 1, 2, 4, 5, 6};
    int b[11] = {2, 4, 1, 5, 6, 9, 1, 2, 4, 5, 6};
    shell_Sort(a, 11);
    shellSort(b, 11);
    return 0;
}