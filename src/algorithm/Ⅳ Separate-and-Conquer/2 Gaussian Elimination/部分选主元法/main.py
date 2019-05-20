import re

# 解析字符串
def analysis(equationSet:str)-> (list,list):
    matrix = list()
    vector = list()
    equationSetList = equationSet.split('\n')
    for line in equationSetList:
        ls = line.split(' ')
        t = [int(x) for x in ls[0:-1]]
        matrix.append(t)
        vector.append(int(ls[-1]))
    return matrix,vector

# 解方程组
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


def main():
    # 输入的方程组
    equationSet:str = "2 -1 1 1\n4 1 -1 5\n1 1 1 0"
    # 将方程组解析成向量和矩阵
    matrix,vector = analysis(equationSet)
    # 部分选主元法解方程组
    res:list = betterForwardElimination(matrix,vector)
    # 输出结果
    print(res)

if __name__ == "__main__":
    main()