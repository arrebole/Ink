#include "./TCPServ-epoll_linux.h"

#define PORT 3000
#define BUFF_SIZE 255
#define EPOLL_SIZE 64

int main(){

    ServConfig config = newServConfig();
    int serverFd = newServer();

    bindAndListen(serverFd, &config);
    epollLoop(serverFd);

    return 0;
}


ServConfig newServConfig(){
    ServConfig result;
    result.addr.sin_family = AF_INET;
    result.addr.sin_port = htons(PORT);
    result.addr.sin_addr.s_addr =  htonl(INADDR_ANY);
    result.socketLen = sizeof(result.addr);
    return result;
}

int newServer(){
    int result = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(result == -1) exit(1);
    return result;
}

void bindAndListen(int aSockFd, ServConfig* aConf){
    bind(aSockFd,(struct sockaddr *)&aConf->addr, aConf->socketLen);
    listen(aSockFd, 64);
}

void makeEpollEvent(struct epoll_event *ev,int fd){
    ev->data.fd = fd;
    ev->events = EPOLLIN;
}

void epollLoop(int listenSock){
    struct epoll_event events[EPOLL_SIZE], event;
    char buffer[BUFF_SIZE];

    int epollFd = epoll_create(EPOLL_SIZE);
    
    makeEpollEvent(&event, listenSock);
    epoll_ctl(epollFd, EPOLL_CTL_ADD, listenSock, &event);

    struct sockaddr_in ClientAddr;
    socklen_t CliLen = sizeof(ClientAddr);
    while (1)
    {
        int nfds = epoll_wait(epollFd, events, EPOLL_SIZE, -1);
        printf("fds: %d\n", nfds);
        for(int i=0; i< nfds; i++){

            if(events[i].data.fd == listenSock){
                int connSock = accept(listenSock,(struct sockaddr *)&ClientAddr, &CliLen);
                printf("new accept\n");
                makeEpollEvent(&event, connSock);
                epoll_ctl(epollFd, EPOLL_CTL_ADD, connSock, &event);
                continue;
            }

            int ret = recv(events[i].data.fd, buffer, BUFF_SIZE, 0);
            if(ret == 0){
                close(events[i].data.fd);
                epoll_ctl(epollFd, EPOLL_CTL_DEL, events[i].data.fd, NULL);
                printf("client close socket ...\n");
            }else
            {
                buffer[ret] = 0x00;
                printf("%s\n",buffer);
            }
            
        }
    }
    


}
