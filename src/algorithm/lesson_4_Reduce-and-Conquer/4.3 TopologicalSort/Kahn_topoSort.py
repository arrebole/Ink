
# Kahn算法是从每个入度为0的顶点出发
def Kahn_topoSort(graph):
    # 记录顶点的输入边数
    nodes = dict()
    # 初始化 顶点统计入nodes
    for key in graph.keys():
        nodes[key] = 0
    # 统计边 输入边统计入nodes
    for value_list in graph.values():
        for vertex in value_list:
            nodes[vertex] += 1
    # 减源
    # 如果不空循环删减
    while (nodes):
        for key in list(nodes.keys()):
            # 并输出入度为0的点
            # 并将这个点的输出点 -1
            if nodes[key] == 0:
                # 减少关联点的入度
                reduceList = graph[key]
                for i in reduceList:
                    nodes[i] -= 1
                # 输出这个被删除的点
                del nodes[key]
                print(key)

