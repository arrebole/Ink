#! /usr/bin/env python

# reverseInt 反转数字
def reverseInt(n :int):
    return int(str(n)[::-1])

# isPalindromicNumber 判断是否为回文数字
def isPalindromicNumber(n) -> bool:
    return n == reverseInt(n)

def main():
    payload = int(input())
    for i in range(10):
        if isPalindromicNumber(payload):
            print(f"{payload} is a palindromic number.")
            return 0
        rePayload = reverseInt(payload)
        print(f"{payload} + {rePayload} = {payload + rePayload}")
        payload = payload + rePayload
    print("Not found in 10 iterations.")

if __name__ == "__main__":
    main()