#include <iostream>
#include "mergeSort.h"
#include "mergeBuSort.h"

using namespace std;

int main()
{
    int a[] = {2, 4, 6, 8, 9, 0, 1, 3, 3, 7};
    mergeBuSort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << endl;
    }
    return 0;
}