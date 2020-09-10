#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <fcntl.h>

// 从文件描述符设置偏移量, 并读取数据
// ssize_t pread(int fd, void *buf, size_t count, off_t offset);

void samplePread() {
    int fd = open("./pread.c", O_RDONLY);

    // 从 fd 偏移 202byte 开始，读取数据到 buffer 中
    char buffer[1024];
    ssize_t nReadByte =  pread(fd, buffer, sizeof(buffer), 202);

    // 显示数据
    write(STDOUT_FILENO, buffer, nReadByte);
}