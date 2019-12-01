from prim import Prim

def TestPrim():
    graph_dict = { 
        "a":{ "a": 0, "b": 3, "f": 5, "e": 2},
        "b":{ "b": 0, "c": 1, "f": 4, "a": 3},
        "c":{ "c": 0, "b": 1, "f": 4, "d": 6},
        "d":{ "d": 0, "c": 6, "f": 5, "e": 8},
        "e":{ "e": 0, "a": 6, "f": 2, "d": 8},
        "f":{ "f": 0, "a": 5, "b": 4, "c": 4, "d":5, "e":2},
    }
    path = Prim(graph_dict, "a")
    print(path)

if __name__ == "__main__":
    TestPrim()