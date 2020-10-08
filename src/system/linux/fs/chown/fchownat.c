#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// exampleFchown 设置文件的所有者uid、组gid
void exampleFchownAt(const char *dirname, const char *pathname, uid_t owner, gid_t group) {
    int dirFd = open(dirname, O_DIRECTORY);
    if (dirFd < 0) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }
    // 通过设置 flag 可以选择是否随文件链接跳转
    if (fchownat(dirFd, pathname, owner, group, 0) == -1) {
        perror("fchownat");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    exampleFchownAt(argv[1], argv[2], atol(argv[3]), atol(argv[4]));
    return 0;
}