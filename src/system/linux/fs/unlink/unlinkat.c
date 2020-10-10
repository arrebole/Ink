#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void exampleUnlinkat(const char* name) {
    int dirFd = open(".", O_DIRECTORY);
    // 基于根目录定位文件
    // flag 设置为 0 效果类似于 unlink
    // flag 设置为 AT_REMOVEDIR 效果类似于 rmdir, 允许删除目录
    if (unlinkat(dirFd, name, 0) < 0) {
        perror("unlinkat");
        _exit(-1);
    }
}

int main(int argc, char const* argv[]) {
    exampleUnlinkat(argv[1]);
    return 0;
}
