#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>

// ioctl io操作的杂项函数
// int ioctl(int fd, unsigned long __request, ...)

void sampleIoctl(){
    struct winsize ws;

    // 获取终端设备的大小
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);

    char buffer[1024];
    int nSize = sprintf(buffer, "col: %d\nrow: %d\n",ws.ws_col, ws.ws_row); 
    write(STDOUT_FILENO, buffer, nSize);
}