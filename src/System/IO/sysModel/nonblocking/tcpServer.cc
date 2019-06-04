#include "./tcpServer.h"

char* createBuffer(int len) {
  char* result = new char[len];
  memset(result, 0, len);
  return result;
}

void fillStringEnd(char* str, int index) { str[index] = 0x00; }

DWORD handleFunc(PVOID pSocket) {
  SOCKET aSocket = (SOCKET)pSocket;

  char* buffer = createBuffer(1024);

  while (TRUE) {
    int ret = recv(aSocket, buffer, 255, 0);
    printf("******** recv polling ********\n");

    if (ret == SOCKET_ERROR) {
      int errcode = WSAGetLastError();
      if (errcode == WSAEWOULDBLOCK) {
        Sleep(100);
        continue;
      } else {
        printf("xxxxx recv error xxxxxxx\n");
        return -1;
      }
    }
    if (ret == 0) {
      printf("client socket closed\n");
      break;
    } else if (ret > 0) {
      fillStringEnd(buffer, ret);
      printf("%s\n", buffer);
    }
  }

  delete[] buffer;
  closesocket(aSocket);
  return 0;
}

int main() {
  Server server;
  server.setHandleFunc(handleFunc);
  server.bindAndListen(3000);
}