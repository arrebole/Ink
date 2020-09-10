#include <unistd.h>
#include <sys/types.h>

// write 从文件描述符中写数据
// ssize_t write(int fd, const void *buf, size_t count);

void sampleWrite() {
    const char buffer[] = "hello world";
    write(STDOUT_FILENO, buffer, sizeof(buffer));
}