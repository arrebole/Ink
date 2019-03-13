/*-----------------------------------------------------------
                windows 基本窗口模型
                update：2018-9-1

------------------------------------------------------------*/

/**
 * 在vs编译器中使用
 * #pragma comment(lib,"user32.lib")  
 * #pragma comment(lib,"gdi32.lib")
 * 链接win库
 * 
 * 在gcc中，编译期添加 -luser32 -lgdi32 链接库
 */
#include <windows.h>
#include "WindowProc.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    // 1、定义窗口
    WNDCLASS wc = {};
    TCHAR CLASS_NAME[] = TEXT("APP");
    wc.lpszClassName = CLASS_NAME; //窗口类名
    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    wc.lpfnWndProc = WindowProc; //窗口处理函数
    wc.hInstance = hInstance;    //窗口实例句柄

    if (!RegisterClass(&wc))
    { //注册窗口类, 如果注册失败弹出错误提示
        MessageBox(NULL, TEXT("Program run err!"), TEXT("err"), MB_OK | MB_ICONERROR);
        return 0;
    }

    HWND hwnd = CreateWindowEx( //创建窗口
        0,
        CLASS_NAME,          //窗口类名
        TEXT("Dark"),        //窗口标题
        WS_OVERLAPPEDWINDOW, //窗口的风格
        CW_USEDEFAULT,       //窗口初始显示位置x:使用缺省值
        CW_USEDEFAULT,       //窗口初始显示位置y:使用缺省值
        CW_USEDEFAULT,       //窗口的宽度:使用缺省值
        CW_USEDEFAULT,       //窗口的高度:使用缺省值
        NULL,                //父窗口:无
        NULL,                //子菜单:无
        hInstance,           //该窗口应用程序的实例句柄
        NULL                 //
    );

    ShowWindow(hwnd, iCmdShow); //显示窗口
    UpdateWindow(hwnd);
    /**
     * 事件驱动，信息循环
     */
    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) //从消息队列中获取消息
    {
        TranslateMessage(&msg); //将虚拟键消息转换为字符消息
        DispatchMessage(&msg);  //分发到回调函数(过程函数)
    }
    return 0;
}
