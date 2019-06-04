// UDP service
// 基于io阻塞模型实现的 UDP服务器
// 平台：windows

#include <stdio.h>
#include <winsock2.h>

struct sockaddr_in createSocketConfig(u_short hostshort) {
  struct sockaddr_in result;
  result.sin_family = AF_INET;
  result.sin_port = htons(hostshort);
  result.sin_addr.S_un.S_addr = INADDR_ANY;
  return result;
}

SOCKET createUdpServer() {
  SOCKET result = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
  return result;
}


void handleLoop(SOCKET *server) {
  char buffer[255];
  SOCKADDR_IN socktaddr_remote;
  int maddrlen_remote = sizeof(socktaddr_remote);

  while (TRUE) {
    // flag = 0 为阻塞io
    // 执行recvfrom，线程会被挂起，等待系统通知后切回
    int ret = recvfrom(*server, buffer, 255, 0, (PSOCKADDR)&socktaddr_remote,
                       &maddrlen_remote);
    printf("loop....");
    if (ret > 0) {
      buffer[ret] = 0x00;
      printf("%s \n", buffer);
    }
  }
}

int main() {
  WSADATA wsaData;
  WSAStartup(MAKEWORD(2, 2), &wsaData);

  // 创建socket并监听端口
  SOCKET server = createUdpServer();
  SOCKADDR_IN serverAddr = createSocketConfig(3000);
  bind(server, (PSOCKADDR)&serverAddr, sizeof(serverAddr));

  // 处理事件
  handleLoop(&server);

  closesocket(server);
  WSACleanup();

  return 0;
}