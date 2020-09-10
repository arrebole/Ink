#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <fcntl.h>

// 从文件描述符偏移量处开始写数据数据
// ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);

void samplePwrite() {
    int fd = open("./pwrite.c", O_RDONLY);

    // 从 fd 偏移 202byte 开始，读取数据到 buffer 中
    char buffer[1024];
    ssize_t nReadByte =  read(fd, buffer, sizeof(buffer));

    // 从标准输出偏移 10byte 处开始写数据
    int outFd = creat("./out", 0644);
    pwrite(outFd, buffer, nReadByte, 66);
}