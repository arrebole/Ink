#define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>

// read 从文件描述符中读取内容
// ssize_t read(int fd, void *buf, size_t count)

void sampleRead() {
    char buffer[1024];
    // 从标准输入读取数据到用户空间的 buffer 中， 并且限制大小为 1024 byte
    ssize_t byteRead = read(STDIN_FILENO, buffer, sizeof(buffer));
}
