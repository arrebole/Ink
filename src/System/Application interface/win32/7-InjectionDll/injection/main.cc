#include <windows.h>
#include <stdio.h>

BOOL LoadDll(DWORD dwProcessId, char *szDllPathName)
{

    //1.获取进程句柄
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);

    //2.计算dll的长度
    DWORD dwLength = strlen(szDllPathName) + 1;

    // 3.在目标进程分配内存
    LPVOID lpAllocAddr = VirtualAllocEx(hProcess, NULL, dwLength, MEM_COMMIT, PAGE_READWRITE);

    // 4.将dll路径写入分配的内存
    BOOL hRet = WriteProcessMemory(hProcess, lpAllocAddr, szDllPathName, dwLength, NULL);

    // 5.获取模块地址
    HMODULE hModule = GetModuleHandle(TEXT("Kernel32.dll"));

    // 6.获取loadLibrary 地址
    long long dwLoadAddr = (long long)GetProcAddress(hModule, "LoadLibraryA");

    // 7.创建远程线程，加载dll
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)dwLoadAddr, lpAllocAddr, 0, NULL);

    // 8.关闭句柄
    CloseHandle(hProcess);
    CloseHandle(hThread);
    CloseHandle(hModule);

    return TRUE;
}

int main()
{
    DWORD dwProcessId;
    char name[] = "./injection/lib.dll";
    scanf("%d", &dwProcessId);
    LoadDll(dwProcessId, name);
    return 0;
}