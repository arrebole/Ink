#include <unistd.h>

// dup2 复制描述符 fildes 为 fildes2，如果 fildes2 已经被打开，则先关闭。
// int dup2(int fildes, int fildes2);

void sampleDup2(){
    int fd = dup2(STDOUT_FILENO, 10);
    
    char buffer[] = "hello world";
    write(10, buffer, sizeof(buffer));
}