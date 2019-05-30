
#include <stdio.h>
#include "lib.h"


// dll main函数
BOOL APIENTRY DllMain(
    HANDLE hModule,
    DWORD ul_reason_for_call,
    LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        // 如果被进程加载 则创建新线程执行注入的代码
    case DLL_PROCESS_ATTACH:
        CreateThread(NULL, 0, ThreadProc, NULL, 0, NULL);
        break;
    }
    return TRUE;
}

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
    for (int i = 0; i < 10; i++)
    {
        printf("dll Function running\n");
    }

    return 0;
}