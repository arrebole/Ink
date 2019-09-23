#! /usr/bin/python3
# -*- coding: UTF-8 -*-

import synflood


def TestRandomSrcIP():
    for _ in range(0, 10):
        print(synflood.randomSrcIP())

def TestRandomSrcPort():
    for _ in range(0, 10):
        print(synflood.randomSrcPort())

if __name__ == "__main__":
    TestRandomSrcIP()
    TestRandomSrcPort()
