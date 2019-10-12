# 分治法 - karatsuba大数相乘
def karatsuba(num1: int, num2: int)->int:
    # 递归终止条件
    if (num1 < 10) or (num2 < 10):
        return num1 * num2
    # 计算拆分长度
    num1Str = str(num1)
    num2Str = str(num2)

    maxLength = max(len(num1Str), len(num2Str))
    splitPosition = int(maxLength / 2)

    # 拆分为 high1, low1, high2, low2
    high1, low1, high2, low2 = 0, 0, 0, 0
    if len(num1Str[: -splitPosition]) < 1:
        high1 = 0
        low1 = int(num1Str[-splitPosition:])
    else:
        high1 = int(num1Str[:-splitPosition])
        low1 = int(num1Str[-splitPosition:])

    if len(num2Str[: -splitPosition]) < 1:
        high2 = 0
        low2 = int(num2Str[-splitPosition:])
    else:
        high2 = int(num2Str[:-splitPosition])
        low2 = int(num2Str[-splitPosition:])

    # 计算z2, z0, z1, 此处的乘法使用递归
    z0 = karatsuba(low1, low2)
    z1 = karatsuba((low1 + high1), (low2 + high2))
    z2 = karatsuba(high1, high2)

    return (z2 * 10 ** (2 * splitPosition)) + ((z1 - z2 - z0)*10**(splitPosition)) + z0
