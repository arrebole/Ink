import random
from heapsort import Heap

def TestHeapSort():
    array = []
    for _ in range(100):
        array.append(random.randint(0,10000))
    h = Heap(array).sort()
    for i in range(99):
        if h[i] > h[i+1]:
            print("test Fail")
            exit(0)
    print("PASS")

if __name__ == "__main__":
    TestHeapSort()