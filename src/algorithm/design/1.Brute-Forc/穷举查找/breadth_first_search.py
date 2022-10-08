#!/usr/bin/python3

# Bfs 广度优先搜索， 输入邻接链表法表示的图, 第一个遍历的key
# 象征谨慎：从最近的元素开始搜索
class BFS():
    def __init__(self, graph: dict):
      self._graph: dict = graph
      self._result: list[str] = []

    def bfs(self, key: str):
        queue: list[str] = [key]
        while(len(queue) > 0):
            local = queue.pop(0)
            for v in self._graph[local]:
                if v not in self._result:
                    self._result.append(v)
                    queue.append(v)
        return self._result
