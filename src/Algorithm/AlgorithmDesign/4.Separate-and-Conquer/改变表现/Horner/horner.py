# Horner 霍纳法则计算多项式(改变表现技术的例子)
# 例如 p(x) = 2x^4 + x^3 + 3x^2 + x-5
#           =>  x(x(x(2x - 1) + 3) + 1) - 5
# p-> 多项式系数(从高到低排列)
def Horner(P: list, x) ->int:
    p = P[0]
    for i in range(1, len(P)):
        p = x*p + P[i]
    return p