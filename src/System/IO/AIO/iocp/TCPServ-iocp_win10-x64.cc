#include "./IOCompletionPort.h"

int main() {
  IOCompletionPort iocpServer;

  if (iocpServer.init(8000)) {
    iocpServer.startServer();
  }

  return 0;
}