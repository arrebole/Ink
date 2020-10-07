#! /usr/bin/env python

import dijkstra

def test_dijkstra():
    graph = {
        'a': {'b': 3, 'd': 7},
        'b': {'a': 3, 'd': 2, 'c': 4},
        'c': {'b': 4, 'd': 5, 'e': 6},
        'd': {'a': 7, 'b': 2, 'c': 5, 'e': 4},
        'e': {'c': 6, 'd': 4 }
    }
    parent, distance = dijkstra.Dijkstra(graph, 'a')

    assert distance['a'] == 0
    assert distance['b'] == 3
    assert distance['c'] == 7
    assert distance['d'] == 5
    assert distance['e'] == 9

if __name__ == "__main__":
    test_dijkstra()