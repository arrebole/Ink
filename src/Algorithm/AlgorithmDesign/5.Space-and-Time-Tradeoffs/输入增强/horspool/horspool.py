# shiftTable 构建移动表
def shiftTable(p:str, maxSize:int)->list:
    result = list()
    for i in range(maxSize+1):
        result.append(len(p))

    for i, ch in enumerate(p):
        result[ord(ch)] = len(p)-i-1
    
    return result

def maxCode(s:str)->int:
    result = 0
    for _, ch in enumerate(s):
        if ord(ch) > result:
            result = ord(ch)
    return result

# horspoolMatching 时空权衡输入增强字符串匹配
def horspoolMatching(p:str, t:str):
    table = shiftTable(p, max(maxCode(t),maxCode(p)))
    i = len(p)-1
    while i <= len(t) - 1:
        k = 0
        while k <= len(p)-1 and p[len(p)-1-k] == t[i-k]:
            k = k+1
        if k == len(p):
            return i-len(p)+1
        else:
            i = i+table[ord(t[i])]
    return -1