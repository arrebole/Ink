#!/usr/bin/python3

# dfs 深度优先搜索， 输入邻接链表法表示的图, 第一个遍历的key
# 象征勇气：直到找到最远的节点才返回
class DFS():
    def __init__(self, graph: dict):
      self._graph: dict = graph
      self._result: list[str] = []

    def dfs(self, key: str):
        self._dfs(key)
        return self._result
    
    def _dfs(self, key: str):
        self._result.append(key)
        for nodes in self._graph[key]:
            if nodes not in self._result:
                self._dfs(nodes)