from topoSort import Rrduction_topoSort, DFS_topoSort


def main():
    graph = dict()
    graph["A"] = ["C", "B"]
    graph["B"] = ["G", "E"]
    graph["C"] = ["F"]
    graph["D"] = ["A", "B", "C", "G", "F"]
    graph["E"] = []
    graph["F"] = []
    graph["G"] = ["F", "E"]
    Rrduction_topoSort(graph)

if __name__ == '__main__':
    main()
