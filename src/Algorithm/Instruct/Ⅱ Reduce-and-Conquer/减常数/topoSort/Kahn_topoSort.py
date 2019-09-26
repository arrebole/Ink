
# KahnTopoSort 基于减源的拓扑排序
class KahnTopo:
    def __init__(self, graph):
        self._graph = graph
   
    # 统计每个结点的边的数量
    def _countEdge(self):
        result = dict()
        # 初始化点
        for key in self._graph.keys():
            result[key] = 0
        # 统计节点的边数
        for value_list in self._graph.values():
            for vertex in value_list:
                result[vertex] += 1
        return result

    def sort(self):
        result = list()
        edgeCount = self._countEdge()
        while (edgeCount):
            for key in list(edgeCount.keys()):
                # 如果边数为0, 则减少关联点的入度并删除
                if edgeCount[key] == 0:
                    for i in self._graph[key]:
                        edgeCount[i] -= 1
                    result.append(key)
                    del edgeCount[key]
        return result



