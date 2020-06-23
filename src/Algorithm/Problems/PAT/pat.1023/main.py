#! /usr/bin/env python

def findNotZeroIndex(array):
    minIndex = 0
    for (i, v) in enumerate(array):
        if v != 0:
            minIndex = i
            break
    return minIndex

def nums(array):
    result = []
    for (i, v) in enumerate(array):
        for j in range(v):
            result.append(i)
    return result

def main():
    payload = [int(i) for i in input().split(' ')]

    queue = nums(payload)
    i = findNotZeroIndex(queue)
    queue[0], queue[i] = queue[i], queue[0]
    print(''.join([ str(s) for s in queue])) 

if __name__ == "__main__":
    main()