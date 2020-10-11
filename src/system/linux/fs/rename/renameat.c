#define _GNU_SOURCE
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistdio.h>

int renameat(int olddirfd, const char *oldpath, int newdirfd, const char *newpath) {
    return syscall(SYS_renameat, olddirfd, oldpath, newdirfd, newpath);
}

int exampleRenameat(const char *oldpath, const char *newpath) {
    int oldDirFd = open(".", O_DIRECTORY);
    if (oldDirFd < 0) {
        return -1;
    }
    if (rename(oldpath, newpath) < 0) {
        return -1;
    }
    return 0;
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        printf("args error\n");
        _exit(-1);
    }
    if (exampleRenameat(argv[1], argv[2]) < 0){
        perror("errors");
    }
    return 0;
}
