#include <fcntl.h>

// sampleOpenFile 打开一个可读可写的，文件描述符。
void sampleOpenFile() {
    int fd = open("file", O_RDWR);
}

// sampleCreateFile 通过 open 创建文件 
void sampleCreateFile() {
    int fd = open("file", O_CREAT, 0654);
}
