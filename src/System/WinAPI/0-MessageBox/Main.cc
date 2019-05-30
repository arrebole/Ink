#include <Windows.h>

int main()
{
    // MessageBox 显示标题
    TCHAR title[] = TEXT("hack");
    // MessageBox 显示内容
    TCHAR messageContent[] = TEXT("call windows API");

    // 调用win api 创建窗口 弹出
    MessageBox(0, messageContent, title, MB_OK);

    return 0;
}