
# Prim 贪婪技术加权图生成最小树
def Prim(graph: dict, root: str):
    result = list()
    seen = set()
    nodes = list(graph.keys())
    
    # 每次往树中添加[最短]的节点
    # 添加初始节点
    seen.add(root)
    nodes.remove(root)
    # 组成边的两点
    pre = None
    next = None
    #每次找树中的点与最近的剩余点 
    while nodes:
        distance = float('inf')
        for s in seen:
            for d in graph[s]:
                if d in seen or s == d:
                    continue
                # 找到距离树最近的点
                if graph[s][d] < distance:
                    distance = graph[s][d]
                    pre = s
                    next = d
        result.append((pre,next))
        seen.add(next)
        nodes.remove(next)
    
    return result