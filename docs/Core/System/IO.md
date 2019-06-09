# IO 模型

## Index

+ 同步模型

  + 阻塞 IO
  + 非阻塞 IO
  + 多路复用 IO
  + 信号驱动 IO

+ 异步模型

  + 异步 IO

  

## Block I/O

> **阻塞I/O模型**，进行系统调用后，内核只有准备完成后才返回，等待期间当前线程会被挂起，处于不可中断的挂起状态。直到操作系统通知完成，才继续执行。

![](../../../images/IO/IO.Blocking.png)

### BlockIO.TcpServer

+ 产生阻塞的系统调用 `accept()` `recv()` 

```c
// runtime: win10-x64;
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


void handleLoop(SOCKET aSocket) {

  char* buffer = malloc(sizeof(char) * BUFFER_SIZE);
  memset(buffer, 0, BUFFER_SIZE);
  while (TRUE) {
    printf("******** sys recv() ********\n");
    // 阻塞的系统调用，调用不返回时线程被挂起。
    int ret = recv(aSocket, buffer, 255, 0);
    
    if (ret > 0) {
      buffer[ret] = 0x00;
      printf("%s\n", buffer);
    }
    if (ret == 0) {
        closesocket(aSocket);
        break;
    }
  }
  free(buffer);
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
    printf("******* sys accept() ********\n");
    SOCKET clientSocket = accept(server, (PSOCKADDR)&clientAddrBuffer, &addr_len);
    
    handleLoop(clientSocket);
  }

  closesocket(server);
  WSACleanup();
  return 0;
}
```



## NonBlock I/O

> **由阻塞io模型的扩展，检测是否准备完成交给用户态。**在执行系统调用之后，内核直接返回一个错误码。由用户态进行轮询，不断的执行系统调用来查看 I/O 是否完成。
>
> 由于处理更多的系统调用，因此这种模型的 CPU 利用率比较低，**但是线程不会长时间挂起，可以在等待的同时处理其它的事件**。

![](../../../images/IO/IO.NonBlock.png)

### NonBlockIO.TcpServer

+ 重点轮询操作

```c++
// runtime: win10-x64;
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

  SOCKET createTcpSocket() { 
      return socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
  }

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

  void setHandleFunc(pFunc aHandleFunc) { 
      this->handleFunc = aHandleFunc; 
  }

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
```

```c++
char* createBuffer(int len) {
  char* result = new char[len];
  memset(result, 0, len);
  return result;
}

void fillStringEnd(char* str, int index) { 
    str[index] = 0x00; 
}

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
	if (ret > 0) {
      fillStringEnd(buffer, ret);
      printf("%s\n", buffer);
    } 
    else if (ret == 0) {
      printf("client socket closed\n");
      break;
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
```



## Multiplexing I/O

> **单线程具有处理多个 I/O 事件的能力。又被称为 Event Driven I/O，即事件驱动 I/O**。
>
> **非阻塞io模拟实现**：将io设置为非阻塞，将多个io封装成数组进行轮询，系统调用检测是否有数据。用户态轮询需要反复进行系统调用，内核态切换产生大量开销。
>
> **系统支持**：提供如select函数， **由内核接管轮询**（**此处会进行阻塞，线程挂起**）。有io描述符可读写时返回（返回数量），之后用户态遍历检测具体的的io，利用系统函数把对应的数据从内核空间复制到进程中。

![](../../../images/IO/IO.Multiplexing.png)

### MultIO.select.TcpServer

```c
// runtime: winx64
#define BUFFER_SIZE 255  // io缓冲区大小

// 文件描述符池
//int sockNum = 0;
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
        //sockNum--;
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

  //遍历socks，将所有的元素置于无效的socket
  cleanGlobSocksPool();

  // 把监听accept的socket放入池中
  GlobSocksPool[0] = servSock;
  //sockNum += 1;

  FD_ZERO(&fds);
  FD_SET(servSock, &fds);

  while (TRUE) {
    copyRead = fds;

    int selResult = select(0, &copyRead, NULL, NULL, NULL);
    printf("select loop selResult %d\n", selResult);

    // 判断是否是新的客户端连接
    if (FD_ISSET(GlobSocksPool[0], &copyRead)) {
      printf("new accept\n");

      clntAddrSz = sizeof(clntAddr);
      clntSock = accept(servSock, (PSOCKADDR)&clntAddr, &clntAddrSz);

      for (int i = 1; i < FD_SETSIZE; i++) {
        if (GlobSocksPool[i] == INVALID_SOCKET) {
          GlobSocksPool[i] = clntSock;
          FD_SET(clntSock, &fds);
          break;
        }
      }
      continue;
    }
    // 接收信息
    recvMessage(buffer, &fds, &copyRead);
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

```



### MultIO.poll.TcpServer