#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>

// fdatasync / 等待进程内的文件描述符数据(不等待属性同步)同步到磁盘。
// int fdatasync(int fd);

void sampleSync(){
    int fd = open("./outfile", O_CREAT | O_WRONLY, 0644);

    // 将数据写入文件描述符
    write(fd, "hello world", 12);

    fdatasync(fd);
}