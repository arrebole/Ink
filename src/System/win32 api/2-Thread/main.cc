#include <windows.h>
#include <stdio.h>

// 新线程执行的代码
DWORD WINAPI myThreadFunc(LPVOID lpParam)
{
    // 参数需要保存 防止newThread() return，数据丢失
    INT n = *(INT *)lpParam;
    for (INT i = 0; i < n; i++)
    {
        printf("++++%d++++\n", i);
        Sleep(500);
    }
    return 0;
}

void newThread()
{
    INT lpParameter = 12;
    HANDLE hThread = CreateThread(NULL, 0, myThreadFunc, &lpParameter, 0, NULL);
    CloseHandle(hThread);
    return;
}

int main()
{
    // 创建一个线程
    newThread();
    // 主线程继续执行
    for (int i = 0; i < 100; i++)
    {
        printf("====%d====\n", i);
        Sleep(500);
    }
    return 0;
}