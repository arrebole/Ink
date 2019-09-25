import Kahn_topoSort, DFS_topoSort


def main():
    graph = dict()
    graph["A"] = ["C", "B"]
    graph["B"] = ["G", "E"]
    graph["C"] = ["F"]
    graph["D"] = ["A", "B", "C", "G", "F"]
    graph["E"] = []
    graph["F"] = []
    graph["G"] = ["F", "E"]
    Kahn_topoSort.Kahn_topoSort(graph)
    print("...")
    
    c = dict()
    c["c1"] = ["c3"]
    c["c2"] = ["c3"]
    c["c3"] = ["c4","c5"]
    c["c4"] = ["c5"]
    c["c5"] = []
    DFS_topoSort.DFS_topoSort(c)

if __name__ == '__main__':
    main()
