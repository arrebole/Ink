#include <unistd.h>
#include <fcntl.h>

// sync 请求内核将所有的文件同步到硬盘。
// void sync(void);

void sampleSync(){
    int fd = open("./outfile", O_CREAT | O_WRONLY, 0644);

    // 将数据写入文件描述符
    write(fd, "hello world", 12);

    // 请求进程内的文件描述符数据同步到磁盘。
    sync();
}