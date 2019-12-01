from quickSelect import quickSelect


def TestQuickSelect():
    a = [0, 27, 3, 6, 2, 1, 7, 8, 12, 9, 10]
    if quickSelect(a, 7) != 8:
        print("test Fail")
        exit(0)
    print("test PASS!")

if __name__ == "__main__":
    TestQuickSelect()
