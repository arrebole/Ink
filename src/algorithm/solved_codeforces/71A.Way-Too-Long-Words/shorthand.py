import sys

def shorthand(In: str)-> str:
    return f"{In[0]}{len(In)-2}{In[-1]}"

def main():
    totalSize = int(sys.stdin.readline())
    for _ in range(totalSize):
        case = sys.stdin.readline().rstrip()
        if len(case) > 10:
            case = shorthand(case)
        print(case)

if __name__ == "__main__":
    main()