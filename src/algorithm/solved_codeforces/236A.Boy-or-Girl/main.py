#! /usr/bin/env python

import sys

def resolve(s: str):
    isGirl = len(set(s)) % 2 == 0
    return "CHAT WITH HER!" if isGirl else "IGNORE HIM!"

def main():
    print(resolve(sys.stdin.readline().strip()))

if __name__ == "__main__":
    main()