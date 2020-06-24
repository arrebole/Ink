
def boyerMoore(p:str, t:str):
    maxsize = maxSize(p, t)
    badTable = badCharacterTable(p, maxsize)


# maxSize 计算字符串的最大编码
def maxSize(*args)->int:
    result = 0
    for arg in args:
        for _ , ch in enumerate(arg):
            if ord(ch) > result:
                result = ord(ch)
    return result

# 坏字符:
# 右移位数 = 坏字符出现的位置 – 坏字符在模式串中上一次出现的位置
# 变量 t1 来代表这个字符的下标
def badCharacterTable(pattern:str, maxSize:int):
    result = [len(pattern)-1 for _ in range(maxSize+1)]
    for i, ch in enumerate(pattern):
        result[ord[ch]] = i
    return result

# 好后缀, 输入已经匹配到的后缀
# 移动的位数 = 好后缀的下标 - 好前缀的下标
def goodSuffixTable(p: str, k: int):
    # 好后缀
    suffStart = 0
    suffEnd = len(p)-1-k
    for i in range(k):
        pass

    return suffEnd - suffStart
