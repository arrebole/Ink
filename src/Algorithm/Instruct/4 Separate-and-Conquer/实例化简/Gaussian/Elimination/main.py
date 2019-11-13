import re

# betterForwardElimination 高斯消去 部分选主元法
def betterForwardElimination(matrix:list,vector:list)->list:
    lenth = len(matrix)
    for i in range(lenth):
        matrix[i].append(vector[i])
    for i in range(lenth):
        pivotrow = i
        for j in range(i+1,lenth):
            if abs(matrix[j][i])>abs(matrix[pivotrow][i]):
                pivotrow = j
        for k in range(i,lenth+1):
            matrix[i][k],matrix[pivotrow][k] = matrix[pivotrow][k],matrix[i][k]
        for j in range(i+1,lenth):
            t = matrix[j][i]/matrix[i,i]
            for k in range(i,lenth+1):
                matrix[j][k] = matrix[j][k] - matrix[i][k]*t
    return []