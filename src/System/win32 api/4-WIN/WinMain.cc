/*-----------------------------------------------------------
                windows ��������ģ��
                update��2018-9-1

------------------------------------------------------------*/

/**
 * ��vs��������ʹ��
 * #pragma comment(lib,"user32.lib")  
 * #pragma comment(lib,"gdi32.lib")
 * ����win��
 * 
 * ��gcc�У���������� -luser32 -lgdi32 ���ӿ�
 */
#include <windows.h>
#include "WindowProc.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
{
    // 1�����崰��
    WNDCLASS wc = { };
    TCHAR CLASS_NAME[] = TEXT("APP");
    wc.lpszClassName = CLASS_NAME;                           //��������                               
    wc.lpfnWndProc = WindowProc;                            //���ڴ�����
    wc.hInstance = hInstance;                               //����ʵ�����

    if (!RegisterClass(&wc))
    { //ע�ᴰ����, ���ע��ʧ�ܵ���������ʾ
        MessageBox(NULL, TEXT("Program run err!"), TEXT("err"), MB_OK | MB_ICONERROR);
        return 0;
    }

    HWND hwnd = CreateWindowEx( //��������
        0,
        CLASS_NAME,            //��������
        TEXT("Dark"),         //���ڱ���
        WS_OVERLAPPEDWINDOW,  //���ڵķ��
        CW_USEDEFAULT,        //���ڳ�ʼ��ʾλ��x:ʹ��ȱʡֵ
        CW_USEDEFAULT,        //���ڳ�ʼ��ʾλ��y:ʹ��ȱʡֵ
        CW_USEDEFAULT,        //���ڵĿ��:ʹ��ȱʡֵ
        CW_USEDEFAULT,        //���ڵĸ߶�:ʹ��ȱʡֵ
        NULL,                 //������:��
        NULL,                 //�Ӳ˵�:��
        hInstance,            //�ô���Ӧ�ó����ʵ�����
        NULL                  //
    );

    ShowWindow(hwnd, iCmdShow); //��ʾ����
    UpdateWindow(hwnd);
    /**
     * �¼���������Ϣѭ��
     */
    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0)) //����Ϣ�����л�ȡ��Ϣ
    {
        TranslateMessage(&msg); //���������Ϣת��Ϊ�ַ���Ϣ
        DispatchMessage(&msg);  //�ַ����ص�����(���̺���)
    }
    return 0;
}
