#
#  python 协程/异步 例子
#  python 3.5+
#  2018-8-25
#


import asyncio


async def print_num(n):
    await asyncio.sleep(2)
    print(n)

# 单个协程实现
def main1():
    loop = asyncio.get_event_loop()
    loop.run_until_complete(print_num(5))


# 多个协程
def main2():

    # 创建协程
    loop = asyncio.get_event_loop()

    # 安排任务
    coroutine_list = [print_num(num) for num in range(10)]
    coroutine = asyncio.wait(coroutine_list)

    # 执行任务
    loop.run_until_complete(coroutine)

    # 关闭任务
    loop.close()




if __name__ == '__main__':
    main1()
    main2()
