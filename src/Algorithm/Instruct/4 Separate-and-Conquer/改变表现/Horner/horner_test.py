from horner import Horner


def TestHorner():
    if Horner([2, -1, 3, 1, -5], 3) != 160:
        print(f"test Fail")
    else:
        print("PASS")

if __name__ == "__main__":
    TestHorner()