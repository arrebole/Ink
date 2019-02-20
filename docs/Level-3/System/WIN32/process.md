## 进程

### 进程的内存情况

![](/docs/assets/img/process.jpg)



### 创建一个进程

```c++
// 创建一个进程，
// 输入：进程的路径，输入执行新进程添加的参数
void newProcess(TCHAR szProcessName[], TCHAR szCommandLine[])
{
    // 传入启动信息的结构体
    STARTUPINFO si;
    // 接收启动后信息的结构体
    PROCESS_INFORMATION pi;

    // 结构体初始化清零
    ZeroMemory(&si, sizeof(si));
    ZeroMemory(&pi, sizeof(pi));
    si.cb = sizeof(si);

    // 创建进程 bRet: 返回是否成功
    BOOL bRet = CreateProcess(
        szProcessName,      // 不在此指定可执行文件的文件名
        szCommandLine,      // 命令行参数
        NULL,               // 默认进程安全性
        NULL,               // 默认线程安全性
        FALSE,              // 指定当前进程内的句柄不可以被子进程继承
        CREATE_NEW_CONSOLE, // 为新进程创建一个新的控制台窗口
        NULL,               // 使用本进程的环境变量
        NULL,               // 使用本进程的驱动器和目录
        &si,
        &pi);

    if (!bRet)
    {
        return;
    }

    printf("new Process ID: %d \n", pi.dwProcessId);
    printf("new ThreadId ID：%d \n", pi.dwThreadId);

    // 释放 进程句柄和线程句柄
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
}
```



### 结束一个进程

```c++
// 通过pid关闭进程
// 系统api：OpenProcess()  TerminateProcess()
BOOL KillProcessByPID(DWORD pid)
{
    //通过pid 在全局内核句柄表中获取该进程句柄
    HANDLE hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    // 关闭进程
    BOOL err = TerminateProcess(hprocess, 0);
    if(!err)
    {
        return FALSE;
    }
    return TRUE;
}
```

