import random

# 基于dfs的拓扑排序
def DFS_topoSort(graph):

    # 结果栈
    result_Stack = list()

    # 图上的顶点不为空时，随机找点进行dfs
    while (graph):
        # vertex 为取出的顶点
        # 随机一个字典中的key，第二个参数为限制个数
        vertex = random.sample(graph.keys(), 1)[0]
        # 创建dfs栈，跟踪set，
        # 并把随机顶点放入栈中
        stack = list()
        seen = set()
        stack.append(vertex)
        seen.add(vertex)
        # 标记深元素
        deep = ""
        # 当栈不空时继续搜索
        while (len(stack) > 0):
            # 从栈中取元素
            v = stack.pop()
            nodes = graph[v]
            # 如果出度为0 则标记为最深点
            if (len(nodes) == 0):
                deep = v
                continue
            for node in nodes:
                # 如果没见过 就标记并入栈
                if node not in seen:
                    stack.append(node)
                    seen.add(node)

        # 删除最深的元素
        graph.pop(deep)
        for key, value in graph.items():
            for item in value:
                if item == deep:
                    graph[key].remove(deep)
        # 最深的元素入结果栈
        result_Stack.append(deep)
    
    # 输出
    print("dfs 拓扑结果")
    while (result_Stack):
        print(result_Stack.pop(), end=" ")
