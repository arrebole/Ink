// UDP service
// 基于io阻塞模型实现的 UDP服务器 多线程版本
// 平台：windows

#include <stdio.h>
#include <winsock2.h>
#define BUFFER_SIZE 1024

SOCKET createTcpSocket() {
  SOCKET result = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  return result;
}

struct sockaddr_in createSocketConfig(u_short hostshort) {
  struct sockaddr_in result;
  result.sin_family = AF_INET;
  result.sin_port = htons(hostshort);
  result.sin_addr.S_un.S_addr = INADDR_ANY;
  return result;
}


DWORD handleLoop(void *pSocket) {
  SOCKET aSocket = *(SOCKET *)pSocket;

  char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
  memset(buffer, 0, BUFFER_SIZE);
  
  while (TRUE) {
    int ret = recv(aSocket, buffer, 255, 0);
    printf("******** sys recv() ********\n");
    if (ret > 0) {
      buffer[ret] = 0x00;
      printf("%s\n", buffer);
    }
    if (ret == 0) break;
  }
  free(buffer);
  return 0;
}

int main() {
  // win下设置dll版本
  WSADATA wsaData;
  WSAStartup(MAKEWORD(2, 2), &wsaData);

  // 创建服务器 主socket
  SOCKET server = createTcpSocket();
  SOCKADDR_IN serverAddr = createSocketConfig(3000);

  // 绑定端口
  bind(server, (PSOCKADDR)&serverAddr, sizeof(serverAddr));

  // 系统调用函数 listen(), 
  //1. 将一个未连接的套接字转换为被动套接字，指示内核应该接收指向该套接字的连接请求。
  //2. 指定内核应该为相应的套接字队列的最大连接个数。
  listen(server, 1);

  while (TRUE) {
    // 用于储存客户端socket地址
    struct sockaddr_in clientAddrBuffer;
    int addr_len = sizeof(clientAddrBuffer);

    // systemCall: accept()
    // 用于内核返回下一个已完成连接。如果已完成连接队列为空，则阻塞线程处于挂起状态。
    SOCKET clientSocket =
        accept(server, (PSOCKADDR)&clientAddrBuffer, &addr_len);
    printf("******* sys accept() ********\n");

    DWORD threadId;
    HANDLE hthread = CreateThread(0,0,(LPTHREAD_START_ROUTINE)handleLoop,(void *)(&clientSocket),0,&threadId);
    if(threadId){
      CloseHandle(hthread);
    }
  
  }

  closesocket(server);
  WSACleanup();
  return 0;
}