import heapq

def TestHeap():
    heap = []
    heapq.heappush(heap, 100)
    heapq.heappush(heap, 10)
    heapq.heappush(heap, 20)
    heapq.heappush(heap, 150)
    heapq.heappush(heap, 44)
    heapq.heappush(heap, 90)
    heapq.heappush(heap, 38)
    print(heap)

TestHeap()