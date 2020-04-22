from lcm import lcm

def TestLcm():
    if lcm(24,60) != 120:
        print("test Fail")
        return
    if lcm(60,24) != 120:
        print("test Fail")
        return
    print("test PASS")

if __name__ == "__main__":
    TestLcm()