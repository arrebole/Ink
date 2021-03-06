from Kahn_topoSort import KahnTopo

if __name__ == "__main__":
    graph = {
        "c1": ["c3"],
        "c2": ["c3"],
        "c3": ["c4","c5"],
        "c4": ["c5"],
        "c5": [],
    }
    ans1 = ["c1","c2","c3","c4","c5"]
    ans2 = ["c2","c1","c3","c4","c5"]
    
    res = KahnTopo(graph).sort()
    if res == ans1 or res == ans2:
        print("OK PASS")
    else:
        print("test fail")