#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

typedef struct servConfig{
    struct sockaddr_in addr;
    socklen_t socketLen;
} ServConfig;

ServConfig newServConfig();

int newServer();

void bindAndListen(int aSockFd, ServConfig* aConf);

void epollLoop(int aServ);