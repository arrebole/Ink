#!/usr/bin/env python3

from queue import PriorityQueue

class Task:
    def __init__(self, cost=0, deep=1):
        self.lb = 0
        self.cost = cost
        self.seen = list()

    def lowerBound(self, g):
        sum = self.cost
        for n in range(len(self.seen),len(g)):
            min = 999999
            for i, v in enumerate(g[n]):
                if min > v and i not in self.seen:
                    min = v
            sum+=min
        self.lb = sum
        return self
    
    def visit(self, n):
        self.seen.append(n)
        return self
    
    def deep(self):
        return len(self.seen)

    def __gt__(self, other):
        return self.lb > other.lb

def minCost(taskItem: list, menu)->int:
    for i in taskItem:
        for index, v in enumerate(menu[len(menu)-1]): 
            if index not in i.seen:
                i.cost += v
    
    result = taskItem[0].cost
    for i in taskItem:
        if i.cost < result:
            result = i.cost
    return result


def search(menu: list, item: Task):
    result = list()
    for i, v in enumerate(menu[item.deep()]):
        if i not in item.seen: 
            newItem = Task(item.cost + v, item.deep()+1)
            newItem.seen = [j for j in item.seen]
            newItem.visit(i).lowerBound(menu)
            result.append(newItem)
    return result


# distribution 利用分支限界法求分配问题, 核心优先队列的排序，最优下界
def distribution(menu: list)->int:
    pQueue = PriorityQueue()
    container = None

    # 将第一个人员入优先队列
    for i,v in enumerate(menu[0]):
        item = Task(cost=v).visit(i).lowerBound(menu)
        pQueue.put(item)
    
    while True:
        item = pQueue.get()
        if item.deep() >= len(menu) - 1:
            break
        
        container = search(menu, item)
        for i in container:
            pQueue.put(i)
    
    # 在最深一层找答案
    return minCost(container, menu)

        