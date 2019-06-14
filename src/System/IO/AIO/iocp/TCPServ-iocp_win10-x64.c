#include <WinSock2.h>

#define THREADS 2

// 端口对应的线程
DWORD WINAPI IOCPThread(LPVOID lpParameter);

int main() {
  WSADATA wsadata;
  WSAStartup(MAKEWORD(2, 2), &wsadata);

  // 创建一个完成端口
  HANDLE hIocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, THREADS);

  //创建完成端口对应的线程对象
  HANDLE *pThreadArray =
      (HANDLE *)HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, 2 * THREADS);
  for (int i = 0; i < 2 * THREADS; i++) {
    pThreadArray[i] =
        (HANDLE)_beginthreadex(NULL, 0, IOCPThread, &hIocp, 0, NULL);
  }

  WSACleanup();
  return 0;
}