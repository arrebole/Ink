#include "./TCPServ-poll_linux.h"

#define BUF_SIZE 255
#define POLL_SIZE 20
#define PORT 3000

int main(){

    ServConfig config = newServConfig();
    int serverFd = newServer();

    bindAndListen(serverFd, &config);
    pollLoop(serverFd);

    return 0;
}


ServConfig newServConfig(){
    ServConfig result;
    //bzero(&result , sizeof(result));
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


void pollLoop(int aServ){
    char buffer[BUF_SIZE];
    struct pollfd socksPool[POLL_SIZE];
    
    for(int i = 1; i < POLL_SIZE; ++i)
	{
		socksPool[i].fd = -1;
	}
    socksPool[0].fd = aServ;
    socksPool[0].events = POLLIN;

    struct sockaddr_in cliaddr;
    int clilen = sizeof(cliaddr);
    int ndfs = 0;
    while (1){

       int nready = poll( socksPool, ndfs + 1 , -1 );
       if(socksPool[0].revents & POLLIN){

            int connfd = accept(aServ, (struct sockaddr *)&cliaddr, &clilen);
            printf("accpet a new client: %s:%d\n", inet_ntoa(cliaddr.sin_addr) , cliaddr.sin_port);

            for(int i = 1;i < POLL_SIZE; i++){
                if(socksPool[i].fd < 0){
                    socksPool[i].fd = connfd;
                    socksPool[i].events = POLLIN;
                    if(i > ndfs){
                        ndfs = i;
                        break;
                    } 
                }
            }
            if(--nready < 0) continue;
       }

        for(int i = 1;i <= ndfs ; ++i){
            if(socksPool[i].fd < 0) continue;
            if(socksPool[i].revents & POLLIN){
                int nRed = recv(socksPool[i].fd, buffer, BUF_SIZE, 0);
                if(nRed <= 0){
                    printf("close client socket\n");
                    close(socksPool[i].fd);
                    socksPool[i].fd = -1;
                }else
                {
                    buffer[nRed] = 0x00;
                    printf("recv %s\n",buffer);
                }
                if(--nready <= 0) break;
            }

        }
    }
    
}