
# 基于dfs的拓扑排序
# graph 为 map 结构 邻接链表法表示图
class DFSTopo:
    def __init__(self, graph):
        self._graph = graph
        self._keys = set(graph.keys())
        self._result = list()
    
    def sort(self):
        while len(self._keys) > 0:
            # 随机取一个元素进行dfs
            self._dfs(self._keys.pop())
        self._result.reverse()
        return self._result
    
    def _pushResult(self, value):
        if value not in self._result:
            self._keys.discard(value)
            self._result.append(value)
    
    def _dfs(self, key):
        if len(self._graph[key]) == 0:
            return
        for node in self._graph[key]:
            self._dfs(node)
            # 出栈时，构建dfs森林
            self._pushResult(node)
        self._pushResult(key)
    
