#
#   lomuto划分：求数列中值
#   架构：减治法-减可变规模-lomuto划分
#

def lomutoPartition(a: list) -> int:
    p = a[0]
    s = 0
    for i in range(0, len(a)):
        if a[i] < p:
            s += 1
            a[s], a[i] = a[i], a[s]
    a[0], a[s] = a[s], a[0]
    return s
