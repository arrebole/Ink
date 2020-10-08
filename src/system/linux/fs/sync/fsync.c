#include <unistd.h>
#include <fcntl.h>

// fsync 等待内核将指定文件描述符的内容和属性同步到硬盘。
// int fsync(int fd);

void sampleFsync(){
    int fd = open("./outfile", O_CREAT | O_WRONLY, 0644);

    // 将数据写入文件描述符
    write(fd, "hello world", 12);

    // 阻塞等待内核将指定文件描述符的内容同步到硬盘。
    fsync(fd);
}