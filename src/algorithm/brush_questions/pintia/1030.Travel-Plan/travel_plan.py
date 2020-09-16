#! /usr/bin/env python

# 1030 Travel Plan (30分) https://pintia.cn/problem-sets/994805342720868352/problems/994805464397627392
# Type: 最短路径问题
# Exploit: Dijkstra:贪心

import math, heapq

class GraphBuilder():
    def __init__(self):
        self.data = dict()

    def add(self, a, b, distance, cost):
        self.__insert(a, b, distance, cost)
        self.__insert(b, a, distance, cost)

    def __insert(self, key, value, distance, cost):
        if key not in self.data:
            self.data.setdefault(key, dict())
        self.data[key][value] = (distance, cost)

def initMiniTable(graph: dict, node):
    result = {}
    for vertex in graph.keys():
        result[vertex] = (math.inf, math.inf)
    result[node] = (0, 0)
    return result

# dijkstra 寻找起点到终点的最短路径
def dijkstra(g: dict, start):
    seen = set()
    priorityQueue = list()
    parent = { start: None }
    minTable = initMiniTable(g, start)

    heapq.heappush(priorityQueue, (0, 0, start))
    while(len(priorityQueue) > 0):
        distance, cost, vertex = heapq.heappop(priorityQueue)
        seen.add(vertex)

        for node in g[vertex].keys():
            if node not in seen:
                distStart = distance + g[vertex][node][0]
                costStart = cost + g[vertex][node][1]
                if distStart < minTable[node][0] or (distStart == minTable[node][0] and costStart < minTable[node][1]):
                    parent[node] = vertex
                    minTable[node] = (distStart, costStart)
                    heapq.heappush(priorityQueue, (distStart, costStart, node))
    return parent, minTable

# 通过父节点反向查询路径
def searchRoad(parent: dict, target):
    node = D
    result = list()
    while(node != None):
        result.insert(0, node)
        node = parent[node]
    return result

if __name__ == "__main__":
    graph = GraphBuilder()
    N, M, S, D = [int(i) for i in input().split(" ")]
    for i in range(M):
        a, b, dis, cost = [int(i) for i in input().split(" ")]
        graph.add(a, b, dis, cost)
    parent, minTable = dijkstra(graph.data, S)

    # 整理结果
    result = searchRoad(parent, D)
    result.append(minTable[D][0])
    result.append(minTable[D][1])
    print(' '.join([str(i) for i in result]))