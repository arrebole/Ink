#include <unistd.h>
#include <fcntl.h>

// 关闭一个打开的文件
// int close(int fd);

void sampleClose(){
    int fd = creat('./sample', 0644);
    close(fd);
}