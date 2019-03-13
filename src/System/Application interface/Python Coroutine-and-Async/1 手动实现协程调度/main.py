import time

# 通过yield中断函数，实现线程的用户态调度
# 在coroutine1和coroutine2 之间手动调度。
def coroutine1():
    while True:
        print("runing func corountine1")
        yield

def coroutine2():
    print("切换到 func corountine2")


if __name__ == "__main__":
    f = coroutine1()
    while True:
        next(f)
        time.sleep(1)
        coroutine2()
