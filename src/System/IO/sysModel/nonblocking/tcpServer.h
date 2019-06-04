#include <WinSock2.h>
#include <stdio.h>
#pragma comment(lib, "ws2_32.lib")
class Server {
 private:
  typedef DWORD (*pFunc)(PVOID);

  WSADATA wsaData;
  SOCKET serverSocket;
  SOCKADDR_IN serverAddr;
  pFunc handleFunc;
  int iMode;

  SOCKADDR_IN createSocketConfig(u_short port) {
    SOCKADDR_IN result;
    result.sin_family = AF_INET;
    result.sin_port = htons(port);
    result.sin_addr.S_un.S_addr = INADDR_ANY;
    return result;
  }

  SOCKET createTcpSocket() { return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); }

  // 接受连接的循环
  void acceptLoop() {
    while (true) {
      struct sockaddr_in clientAddrBuffer;
      int addr_len = sizeof(clientAddrBuffer);

      // systemCall: accept()
      // 用于内核返回下一个已完成连接。如果已完成连接队列为空，则阻塞线程处于挂起状态。
      SOCKET clientSocket =
          accept(serverSocket, (PSOCKADDR)&clientAddrBuffer, &addr_len);
      printf("******* accept polling ********\n");

      // 轮询
      if (clientSocket == INVALID_SOCKET) {
        //表示没有客户端发起连接，继续循环
        if (WSAGetLastError() == WSAEWOULDBLOCK) {
          Sleep(1000);
          continue;
        } else {
          printf("accept failed!\n");
        }
      }

      handleFunc((PVOID)clientSocket);
    }
  }
  // 设置网络io为非阻塞模式
  void setIoNonBlock() {
    this->iMode = 1;
    ioctlsocket(serverSocket, FIONBIO, (u_long FAR*)&iMode);
  }

 public:
  Server() {
    printf("wsaStartup ...\n");
    WSAStartup(MAKEWORD(2, 2), &(this->wsaData));
    printf("create main socket\n");
    this->serverSocket = createTcpSocket();
  }

  void setHandleFunc(pFunc aHandleFunc) { this->handleFunc = aHandleFunc; }

  void bindAndListen(u_short port) {
    this->serverAddr = createSocketConfig(port);
    bind(serverSocket, (PSOCKADDR)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 1);
    this->setIoNonBlock();
    this->acceptLoop();
  }

  ~Server() {
    closesocket(serverSocket);
    WSACleanup();
  }
};