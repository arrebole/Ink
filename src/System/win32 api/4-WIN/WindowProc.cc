
#include "WindowProc.h"

// �ص��������ں˵���
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;        //�豸�������
    PAINTSTRUCT ps; //���ƽṹ
    RECT rect;      //���νṹ

    switch (uMsg) //����õ�����Ϣ
    {

    case WM_PAINT: //������������Чʱ��������Ϣ
        hdc = BeginPaint(hwnd, &ps);
        GetClientRect(hwnd, &rect);
        DrawText(hdc, TEXT("Hello, World"), -1, &rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        EndPaint(hwnd, &ps);
        return 0;

    case WM_LBUTTONDOWN: //���������������µ���Ϣ
        MessageBox(hwnd, TEXT("�����������¡�"), TEXT("����"), MB_OK | MB_ICONINFORMATION);
        return 0;

    case WM_DESTROY: //�����ڹر�ʱ����Ϣ
        MessageBox(hwnd, TEXT("�رճ���!"), TEXT("����"), MB_OK | MB_ICONINFORMATION);
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam); //DefWindowProc���������Զ������Ϣ������û�д�������Ϣ
}