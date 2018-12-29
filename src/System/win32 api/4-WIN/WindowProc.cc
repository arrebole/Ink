
#include "WindowProc.h"

// 回调函数，内核调用
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;        //设备环境句柄
    PAINTSTRUCT ps; //绘制结构
    RECT rect;      //矩形结构

    switch (uMsg) //处理得到的消息
    {

    case WM_PAINT: //处理窗口区域无效时发来的消息
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(hdc, TEXT("Hello, World"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;

    case WM_LBUTTONDOWN: //处理鼠标左键被按下的消息
        MessageBox(hwnd, TEXT("鼠标左键被按下。"), TEXT("单击"), MB_OK | MB_ICONINFORMATION);
        return 0;

    case WM_DESTROY: //处理窗口关闭时的消息
        MessageBox(hwnd, TEXT("关闭程序!"), TEXT("结束"), MB_OK | MB_ICONINFORMATION);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam); //DefWindowProc处理我们自定义的消息处理函数没有处理到的消息
}