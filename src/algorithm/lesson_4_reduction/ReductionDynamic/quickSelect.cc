#include "lomutoPartition.h"
#include "quickSelect.h"
/**
 * 快速选择是一种从无序列表找到第k小元素的选择算法。
 * 具有很好的平均时间复杂度，然而最坏时间复杂度则不理想.
 * 性能： 从O(n log n)至O(n)，不过最坏情况仍然是O(n2)。
*/
int quickSelect(int a[], int len, int k)
{
    int l = 0, r = len - 1;

    int partitionIdx = lomutoPartition(a, l, r);

    while (l <= r)
    {
        if ((k - 1) == partitionIdx)
        {
            break;
        }
        else if ((k - 1) < partitionIdx)
        {
            r = partitionIdx - 1;
        }
        else
        {
            l = partitionIdx + 1;
        }

        partitionIdx = lomutoPartition(a, l, r);
    }
    return a[partitionIdx];
}