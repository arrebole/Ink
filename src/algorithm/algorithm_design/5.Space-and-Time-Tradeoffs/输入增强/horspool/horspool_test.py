from horspool import horspoolMatching,shiftTable

def TestShiftTable():
    table = shiftTable("barber",200)
    if table[ord('e')] != 1:
        print("test fail")
    else:
        print("PASS")

def TestHorspoolMatching():
    if horspoolMatching("barxer","barrsggwigapabbarxerarbersan") != 14:
        print("test Fail")
    else:
        print("PASS")

if __name__ == "__main__":
    TestShiftTable()
    TestHorspoolMatching()