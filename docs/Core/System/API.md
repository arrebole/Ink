# 操作系统应用层接口

## 目录索引

###  Win32接口

+ [创建和结束进程]()
+ [创建线程]()
+ [GDI]()
+ [DLL注入]()

###  Coroutine/异步

+  [python实现]()
+  [javaScript实现]()



## Win32接口

### 创建和结束进程

>

#### 创建一个进程

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

#### 结束一个进程

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

### 创建线程

>

#### 创建一个线程

```c++
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
    // 调用win api CreateThread->创建线程
    HANDLE hThread = CreateThread(NULL, 0, myThreadFunc, &lpParameter, 0, NULL);
    CloseHandle(hThread);
    return;
}
```



#### 创建远程线程

```c++
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
```



### GDI

>

#### 绘制矩形
```c++
void drawRectangle()
{
    // 1.设备对象的句柄 (null表示桌面)
    HWND hwnd = NULL;

    // 2.设备对象上下文
    HDC hdc = GetDC(hwnd);

    // 3.绘制工具, 刷子
    HBRUSH hbrush = (HBRUSH)GetStockObject(DC_BRUSH);
    SelectObject(hdc, hbrush);
    SetDCBrushColor(hdc, RGB(0xff, 00, 00));

    // 4.绘制
    while (true)
    {
        Rectangle(hdc, 0, 0, 1400, 900);
        Sleep(50);
    }

    // 5.清理
    DeleteObject(hbrush);
    DeleteDC(hdc);
}
```



### DLL注入

>

#### 简单的dll注入

```c++
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
```







## Coroutine/异步

协程是轻量级的线程，主要应用在io密集型非阻塞操作。其主要实例为异步非阻塞模型，利用单线程模拟并发。

异步的实质是在单线程中控制函数的调度，将需要等待的函数挂起，继续执行后面的函数，在事件驱动下再回头执行挂起的函数。

### python中的实现

pthon中的协程异步是通过 yield（构造器）实现。yield 有类似return的功能，能在函数中实现中断挂起。

```python
def say():
    yield "hello"
    yield "world"

c = say()           #返回构造器函数
print(next(say))	#执行到 返回hello 处被挂起，通过next可以继续被挂起的任务
print(next(say))	# 继续返回 world
```



python 3.5+ 对异步操作进行了封装，通过async/await 和asyncio包 能够容易实现,在src中有详细代码

- async 修饰的是异步函数
- await 后面的是异步函数 



```python
async def print_num(n):
    await asyncio.sleep(2) # 睡两秒 模拟io
    print(n)
```

单协程实现

```python
# 获取事件驱动
loop = asyncio.get_event_loop()
# 调用协程
loop.run_until_complete(print_num(5))
```



多个协程

```python
#1、创建协程
loop = asyncio.get_event_loop()
#2、安排任务
coroutine_list = [print_num(num) for num in rang(10)]
corountine = asyncio.wait(corountine_list)
#3、执行任务
loop.run-until_complete(coroutine)
#4、关闭
loop.close()
```



### javaScript中的实现

在es5之前javascript没有异步，函数的调度是通过回调函数来实现的，当时称为回调噩梦；

```javascript
function fn1(){
    console.log("hello");
}
// 将函数变成参数传入，当函数执行完，再执行参数函数（称回调函数）
function fn2(fun){
    console.log("world");
    fun()
}

// 执行
//在fn2之后执行fn1
fn2(fn1)

```

es5之后出现了promise对象

```javascript
var fn1 = function(){
    return new Promise((resolve,reject)=>{
        //...
        if !err{
          reject(err)  // 失败。将会调用 catch方法
        }
        resolve(res) // 成功。将会调用then方法
    })
}

fn1.then((res)=>{
    console.log(res);
}).catch((err)=>{
    console.log(err)
})
```

es7出现async/await，是promise的语法糖，await后面跟着promise函数

```javascript
function fn1(){
    return Promise((resolve,reject)=>{
        resolve(res)
    })
}

async function fn(){
    res = await fn1();
}
```

