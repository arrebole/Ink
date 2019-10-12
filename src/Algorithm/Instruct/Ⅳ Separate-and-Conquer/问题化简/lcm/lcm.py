
# gcd 欧几里得算法求最大公约数 
def gcdEuclid(m, n):
    while n != 0:
        r = m % n
        m = n
        n = r
    return m

# lcm 求最小公倍数
# 问题化简为：lcm(m,n) = m*n/gcd(m,n)
def lcm(m: int,n: int)->int:
    return m*n / gcdEuclid(m,n)

