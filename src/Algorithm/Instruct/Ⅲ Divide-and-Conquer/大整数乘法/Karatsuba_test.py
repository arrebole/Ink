from Karatsuba import karatsuba 

def TestKaratsuba():
    if karatsuba(232086, 3781759) != 232086*3781759 :
        print("test Fail")
        exit(0)
    print("test PASS!~")



if __name__ == "__main__":
    TestKaratsuba()