#!/usr/bin/python3

from breadth_first_search import BFS

if __name__ == "__main__":
    graph = {
        "A": ["B", "C"],
        "B": ["A", "C", "D"],
        "C": ["A", "B", "D", "E"],
        "D": ["B", "C", "E", "F"],
        "E": ["C", "D"],
        "F": ["D"]
    }
    print(BFS(graph).bfs("A"))