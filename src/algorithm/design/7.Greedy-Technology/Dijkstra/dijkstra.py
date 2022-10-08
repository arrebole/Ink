import math, heapq

# Dijkstra 求单起点最短路径
# in: G=<V,E> 非负权重加权连通图，s 顶点
def Dijkstra(G: dict, s):
    # 初始化优先队列, 
    priorityQueue = []

    # 距离表，前节点表
    seen, parent, distance = set(), {}, {}
    for v in G.keys():
        parent[v] = None
        distance[v] = math.inf

    # 设置将起点
    distance[s] = 0
    heapq.heappush(priorityQueue, (distance[s], s))

    # 求最短距离
    while len(priorityQueue) > 0:
        d, v = heapq.heappop(priorityQueue)
        seen.add(v)
        for u in G[v].keys():
            if u in seen:
                continue
            if d + G[u][v] < distance[u]:
                distance[u] = d + G[u][v]
                parent[u] = v
                heapq.heappush(priorityQueue, (distance[u], u))
    return parent, distance