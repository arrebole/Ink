## GDI

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