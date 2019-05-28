#
#   lomuto划分：求数列中值
#   架构：减治法-减可变规模-lomuto划分
#   @params l,r,需要规划的开始端和结束端
#

def lomutoPartition(a: list) -> int:
    l = 0
    r = len(a) - 1

    p = a[l]
    s = l
    for i in range(l, r + 1):
        if a[i] < p:
            s += 1
            a[s], a[i] = a[i], a[s]
    a[l], a[s] = a[s], a[l]
    return s
