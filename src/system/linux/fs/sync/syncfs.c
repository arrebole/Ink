#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>

// syncfs 请求内核将指定的文件描述符数据同步到硬盘。
// int syncfs(int fd);

void sampleSyncfs(){
    int fd = open("./outfile", O_CREAT | O_WRONLY, 0644);

    // 将数据写入文件描述符
    write(fd, "hello world", 12);

    // 请求指定的文件描述符数据同步到磁盘。
    syncfs(fd);
}