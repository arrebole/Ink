#include <iostream>

#include "quickSort.h"

using namespace std;

int main()
{
    int a[15] = {4, 2, 4, 65, 7, 8, 43, 8, 9, 5, 32, 45, 45, 23, 1};
    quickSort(a, 0, 14);
    for (int i = 0; i < 15; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
