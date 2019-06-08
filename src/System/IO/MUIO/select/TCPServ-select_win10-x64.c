// tcp server multiplexing
// runtime: win10-x64;
// windows下利用select syscall，实现多路复用,单线程监听多个io

#include <WinSock2.h>
#include <stdio.h>

#define BUFFER_SIZE 255  // io缓冲区大小

// 文件描述符池
int sockNum = 0;
SOCKET GlobSocksPool[FD_SETSIZE];

// 服务器socket和addr打包一起
typedef struct SocketPack {
  SOCKET socket;
  SOCKADDR_IN addr;
} SOCKETPACK;

void cleanGlobSocksPool() {
  for (int i = 0; i < FD_SETSIZE; i++) {
    GlobSocksPool[i] = INVALID_SOCKET;
  }
}

// 处理错误
void errorHandler(const char* message) {
  printf("%s\n", message);
  exit(1);
}

void printBufferIO(char* buffer, int len) {
  buffer[len] = 0x00;
  printf("%s\n", buffer);
}

// 创建用于监听的socket
SOCKET createServTCPSocket() {
  SOCKET result = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (result == INVALID_SOCKET) errorHandler("socketServ error");
  return result;
}

// 创建用于监听的socket的地址
SOCKADDR_IN createServAddr(u_short port) {
  SOCKADDR_IN result;
  memset(&result, 0, sizeof(result));
  result.sin_family = AF_INET;
  result.sin_port = htons(port);
  result.sin_addr.S_un.S_addr = INADDR_ANY;
  return result;
}

// NewServer 创建服务器主socket和addr的结构体
// 使用createServerAddr和createServerTCPSocket
SOCKETPACK NewServer() {
  SOCKETPACK result;
  result.socket = createServTCPSocket();
  result.addr = createServAddr(3000);
  return result;
}

// 服务器主socket，绑定端口并开启监听
void bindAndListen(SOCKETPACK* serv) {
  int error;
  error = bind(serv->socket, (PSOCKADDR)&serv->addr, sizeof(serv->addr));
  if (error == SOCKET_ERROR) {
    errorHandler("bind error");
  }
  error = listen(serv->socket, 64);
  if (error == SOCKET_ERROR) {
    errorHandler("listen error");
  }
}

TIMEVAL createTimeval() {
  TIMEVAL result;
  result.tv_sec = 100000;
  result.tv_usec = 0;
  return result;
}

void removeDeathSocket(SOCKET* sockPool, int index, fd_set* pFds) {
  printf("client socket closed ...\n");
  closesocket(sockPool[index]);
  FD_CLR(sockPool[index], pFds);
  sockPool[index] = INVALID_SOCKET;
}

void recvMessage(char* buffer, fd_set* pFds, fd_set* pCopyRead) {
  for (int i = 1; i < FD_SETSIZE; i++) {
    if (GlobSocksPool[i] == INVALID_SOCKET) continue;

    if (FD_ISSET(GlobSocksPool[i], pCopyRead)) {
      int strLen = recv(GlobSocksPool[i], buffer, BUFFER_SIZE, 0);

      //客户端断开了连接
      if (strLen <= 0) {
        removeDeathSocket(&GlobSocksPool[0], i, pFds);
        sockNum--;
      }
      //客户端发送了数据
      else if (strLen > 0)
        printBufferIO(buffer, strLen);
    }
  }
}

// 多路复用io
void MultiplexingSocket(SOCKET servSock) {
  unsigned long ul = 1;
  // 请求的客户端
  int clntAddrSz;
  SOCKADDR_IN clntAddr;
  SOCKET clntSock;

  char buffer[BUFFER_SIZE];

  fd_set fds, copyRead;
  TIMEVAL tm = createTimeval();  // select 轮询时间

  //遍历socks，将所有的元素置于无效的socket
  cleanGlobSocksPool();

  // 把监听accept的socket放入池中
  GlobSocksPool[0] = servSock;
  sockNum += 1;

  FD_ZERO(&fds);
  FD_SET(servSock, &fds);

  while (TRUE) {
    copyRead = fds;

    int selResult = select(sockNum + 1, &copyRead, NULL, NULL, &tm);
    printf("select loop selResult %d\n", selResult);

    if (selResult == -1)
      printf("select error");

    else if (selResult == 0)
      printf("timeout!");

    else {
      // 判断是否是新的客户端连接
      if (FD_ISSET(GlobSocksPool[0], &copyRead)) {
        printf("new accept\n");

        clntAddrSz = sizeof(clntAddr);
        clntSock = accept(servSock, (PSOCKADDR)&clntAddr, &clntAddrSz);

        for (int i = 1; i < FD_SETSIZE; i++) {
          if (GlobSocksPool[i] == INVALID_SOCKET) {
            GlobSocksPool[i] = clntSock;
            FD_SET(clntSock, &fds);
            sockNum++;
            break;
          }
        }
        continue;
      }
      // 接收信息
      recvMessage(buffer, &fds, &copyRead);
    }
  }
}

int main() {
  WSADATA wsaData;
  if (WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR) {
    errorHandler("WSAStartUp Error");
  }

  SOCKETPACK socketServer = NewServer();
  bindAndListen(&socketServer);

  // 执行多路复用
  MultiplexingSocket(socketServer.socket);

  closesocket(socketServer.socket);
  WSACleanup();
  return 0;
}
