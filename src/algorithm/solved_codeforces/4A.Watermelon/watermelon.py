#! /usr/bin/env python

import sys, enum

class Response(enum.Enum):
    YES = "YES"
    NO  = "NO"

def isEven(n: int) -> bool:
    return n > 0 and not (n & 1)

def isDivideEven(n: int) -> Response:
    if n > 2 and isEven(n):
        return Response.YES
    return Response.NO

def main():
    totalSize = int(sys.stdin.readline())
    print(isDivideEven(totalSize).value)

if __name__ == "__main__":
    main()