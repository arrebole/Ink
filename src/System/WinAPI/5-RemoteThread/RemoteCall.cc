#include <Windows.h>
#include <stdio.h>

BOOL RemoteThread(DWORD dwProcessId, LPTHREAD_START_ROUTINE lpStartAddress)
{
    // 定义远程进程id；
    DWORD lpThreadId = 0;

    // 获取远程进程句柄
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
    if (hProcess == NULL)
    {
        printf("err hProcess");
        return false;
    }
    // 创建远程线程
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, lpStartAddress, NULL, 0, &lpThreadId);
    if (hThread == NULL)
    {
        CloseHandle(hProcess);
        printf("err hThread");
        return FALSE;
    }

    // 清理
    CloseHandle(hThread);
    CloseHandle(hProcess);
    return TRUE;
}

int main()
{
    DWORD pid;
    LPTHREAD_START_ROUTINE Address;

    scanf("%d", &pid);
    scanf("%d", &Address);

    RemoteThread(pid, Address);

    printf("success!\n");
    return 0;
}