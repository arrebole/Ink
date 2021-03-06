from LomutoPartition import lomutoPartition


#
#   快速选择 是一种从无序列表找到第k小元素的选择算法。
#   具有很好的平均时间复杂度，然而最坏时间复杂度则不理想.
#   性能： 从O(n log n)至O(n)，不过最坏情况仍然是O(n2)。
#
def quickSelect(a: list, k: int):
    s = lomutoPartition(a)
    if s == (k - 1):
        return a[s]
    elif s > (k - 1):
        return quickSelect(a[:s], k)
    else:
        return quickSelect(a[s+1:], k-1-s)