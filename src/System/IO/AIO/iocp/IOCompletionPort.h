#pragma once
#include <WinSock2.h>

#define MAX_BUFFER 1024
#define BACL_LOG 6

struct socketInfo {
  WSAOVERLAPPED overlapped;
  WSABUF dataBuf;
  SOCKET socket;
  char messageBuffer[MAX_BUFFER];
  int recvBytes;
};

class IOCompletionPort {
 public:
  IOCompletionPort();
  ~IOCompletionPort();

  bool init(u_short port);
  void startServer();
  bool createWorkerThread();
  void workerThread();

 private:
  socketInfo* pSocketInfo;
  SOCKET listenSocket;
  HANDLE hIocp;
  bool isAccept;
  bool isWorkerThread;
  HANDLE* pWorkerHandle;
};