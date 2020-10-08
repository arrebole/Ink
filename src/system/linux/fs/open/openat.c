// 使用 openat() 需要定义功能测试宏
#define _ATFILE_SOURCE 
#include <fcntl.h>
#include <unistd.h>

// openat（path为相对路径时）打开以fd指向的文件的目录作为为基址加上path路径的文件
// int openat(int dirfd, const char *pathname, int flags, mode_t ...mode?);

// sampleOpenat -> ../../../file2
void sampleOpenat() {
    int baseFd = open("../../fs", O_RDONLY);
    int superFd = openat(baseFd, "../file2", O_CREAT | O_TRUNC | O_RDWR, 0654);
}
