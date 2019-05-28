#include <iostream>

using namespace std;

void insertionSort(int a[], int len)
{
    for (int i = 1; i < len; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > v)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

int main()
{
    int a[5] = {2, 3, 1, 5, 0};
    insertionSort(a, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}