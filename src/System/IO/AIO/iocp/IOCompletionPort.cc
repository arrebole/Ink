#include "./IOCompletionPort.h"
#include <process.h>
#include <stdio.h>

socketInfo* createSocketInfo(SOCKET aSocket) {
  socketInfo* result = new socketInfo();
  result->socket = aSocket;
  result->recvBytes = 0;
  result->dataBuf.len = MAX_BUFFER;
  result->dataBuf.buf = result->messageBuffer;
  return result;
}

unsigned int WINAPI CallWorkerThread(LPVOID p) {
  IOCompletionPort* pOverlappedEvent = (IOCompletionPort*)p;
  pOverlappedEvent->workerThread();
  return 0;
}

IOCompletionPort::IOCompletionPort() {
  isWorkerThread = true;
  isAccept = true;
}

IOCompletionPort::~IOCompletionPort() {
  WSACleanup();

  if (pSocketInfo != nullptr) {
    delete[] pWorkerHandle;
    pWorkerHandle = nullptr;
  }

  if (pWorkerHandle != nullptr) {
    delete[] pWorkerHandle;
    pWorkerHandle = nullptr;
  }
}

// 初始化监听socket
bool IOCompletionPort::init(u_short port) {
  WSADATA wsaData;
  int nResult;

  nResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
  if (nResult != 0) {
    return false;
  }

  // 创建服务器socket
  listenSocket =
      WSASocketW(AF_INET, SOCK_STREAM, 0, nullptr, 0, WSA_FLAG_OVERLAPPED);
  if (listenSocket == INVALID_SOCKET) {
    return false;
  }

  // 监听地址
  SOCKADDR_IN serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(port);
  serverAddr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);

  // 绑定端口
  nResult = bind(listenSocket, (PSOCKADDR)&serverAddr, sizeof(SOCKADDR_IN));
  if (nResult == SOCKET_ERROR) {
    closesocket(listenSocket);
    WSACleanup();
    return false;
  }

  //监听
  nResult = listen(listenSocket, BACL_LOG);
  if (nResult == SOCKET_ERROR) {
    closesocket(listenSocket);
    WSACleanup();
    return false;
  }
  return true;
}

// 启动服务器
void IOCompletionPort::startServer() {

  // 客户端信息
  SOCKADDR_IN clientAddr;
  int addrLen = sizeof(SOCKADDR_IN);
  SOCKET clientSocket;
  DWORD recvBytes;
  DWORD flags;

  // 创建完成端口
  hIocp = CreateIoCompletionPort(INVALID_HANDLE_VALUE, nullptr, 0, 0);

  // 创建工作线程
  if (!this->createWorkerThread()) return;

  // 开始接受客户端循环
  while (this->isAccept) {
    clientSocket = WSAAccept(listenSocket, (PSOCKADDR)&clientAddr, &addrLen,
                             nullptr, (DWORD_PTR) nullptr);

    if (clientSocket == INVALID_SOCKET) exit(0);

    // 创建连接信息
    pSocketInfo = createSocketInfo(clientSocket);

    // 将客户端连接的新socket 绑定到完成端口
    flags = 0;
    hIocp = CreateIoCompletionPort((HANDLE)clientSocket, hIocp,
                                   (ULONG_PTR)pSocketInfo, 0);
    
    printf("accept a client socket\n");
    // 阻塞调用 指定嵌套套接字和传递函数在完成时执行
    // 第一次接收为0
    int nResult = WSARecv(pSocketInfo->socket, &pSocketInfo->dataBuf, 1, &recvBytes,
                      &flags, &(pSocketInfo->overlapped), nullptr);
    if (nResult == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING) return;
  }
}

bool IOCompletionPort::createWorkerThread() {
  unsigned int threadId;
  
  // 获取操作系统信息
  SYSTEM_INFO sysInfo;
  GetSystemInfo(&sysInfo);
  printf("[INFO] CPU number : %lu\n", sysInfo.dwNumberOfProcessors);

  // 计算出需要创建的线程数量
  int nThreadCnt = sysInfo.dwNumberOfProcessors * 2;

  // 创建线程数组
  pWorkerHandle = new HANDLE[nThreadCnt];
  
  // 创建线程存放线程数组中
  for (int i = 0; i < nThreadCnt; i++) {
    pWorkerHandle[i] = (HANDLE*)_beginthreadex(NULL, 0, &CallWorkerThread, this,
                                               CREATE_SUSPENDED, &threadId);
    if (pWorkerHandle[i] == NULL) {
      printf("[ERROR] Worker Thread create error\n");
      return false;
    }
    ResumeThread(pWorkerHandle[i]);
  }
  printf("[INFO] create Worker Thread success ...\n");
  return true;
}

void IOCompletionPort::workerThread() {

  // 重叠I / O操作中传输的数据大小
  DWORD recvBytes;
  socketInfo* pCompletionKey;
  socketInfo* pSocketInfo;
  DWORD dwFlags = 0;

  while (isWorkerThread) {

    // 阻塞调用
    bool bResult = GetQueuedCompletionStatus(hIocp, &recvBytes,
                                        (PULONG_PTR)&pCompletionKey,
                                        (LPOVERLAPPED*)&pSocketInfo, INFINITE);
    pSocketInfo->dataBuf.len = recvBytes;

    if (recvBytes == 0) {
      printf("[INFO] client close socket\n");
      closesocket(pSocketInfo->socket);
      delete pSocketInfo;
      continue;

    } else {
      printf("resv- Bytes[%lu], Msg : %s\n", pSocketInfo->dataBuf.len,
             pSocketInfo->dataBuf.buf);

      // 清理内存
      ZeroMemory(&(pSocketInfo->overlapped), sizeof(OVERLAPPED));
      pSocketInfo->dataBuf.len = MAX_BUFFER;
      pSocketInfo->dataBuf.buf = pSocketInfo->messageBuffer;
      ZeroMemory(pSocketInfo->messageBuffer, MAX_BUFFER);
      pSocketInfo->recvBytes = 0;
      

      // // 阻塞调用 WSARecv以从客户端接收响应
      dwFlags = 0;
      int nResult = WSARecv(pSocketInfo->socket, &(pSocketInfo->dataBuf), 1,
                        &recvBytes, &dwFlags,
                        (LPWSAOVERLAPPED) & (pSocketInfo->overlapped), NULL);

      if (nResult == SOCKET_ERROR && WSAGetLastError() != WSA_IO_PENDING) {
        printf("[ERROR] WSARecv error");
      }
    }
  }
}