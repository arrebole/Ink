#include <iostream>

using namespace std;
/**
 *  减治法-减常因子-折半查找
 * 
*/

// @params：一个有序数组和它的长度，需要查找的key
// @retrun: key的index
int binarySearch(int a[], int len, int k)
{
    int l = 0, r = len - 1;
    int m;
    while (l <= r)
    {
        m = ((l + r) / 2);
        if (k == a[m])
        {
            return m;
        }
        else if (k < a[m])
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    return -1;
}

int main()
{
    int a[] = {1, 3, 4, 5, 6, 7, 9, 12, 34, 35, 37, 40, 45, 60, 72, 82, 93};
    cout << binarySearch(a, 17, 6) << endl;
    return 0;
}