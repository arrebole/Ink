class Edge:
    def __init__(self, a: str, b: str, d: float):
        self.pair = (a, b)
        self.distance = d

# 创建最小边的排序列表        
def createEdgeList(graph: dict):
    result = list()
    seen = set() # 用于去除重复 
    for s in graph:
        for p in graph[s]:
            if s != p and (s + p) not in seen and (p + s) not in seen:
                seen.add(s+p)
                result.append(Edge(s, p, graph[s][p]))
    return sorted(result, cmp=lambda x,y:cmp(x.distance, y.distance))

# hasCycle 判断是否有环路
def hasCycle(e: list, edge: tuple):
    left, right = edge[0], edge[1]
    while left != right:
        pass
    return True


# kruskal 按照边为单位逐渐加入树中
def kruskal(graph: dict):
    result = list()
    
    seen = set()
    nodes = graph.keys()

    pre, next = None, None
    # 当所有顶点都加入树中时结束
    while len(seen) < len(nodes):
        distance = float('inf')
        for s in nodes:
            for d in nodes:
                if s == d or (s in seen and d in seen):
                    continue
                if graph[s][d] < distance:
                    distance = graph[s][d]
                    pre = s
                    next = d
    
    return result