#define _GNU_SOURCE
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistdio.h>

// symlinkat make a new name for a file
int symlinkat(const char *target, int newdirfd, const char *linkpath) {
    return syscall(SYS_symlinkat, target, newdirfd, linkpath);
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        printf("args error\n");
        _exit(-1);
    }

    int newdirfd = open(".", O_DIRECTORY);
    if (newdirfd < 0) {
        perror("open");
        _exit(-1);
    }

    if (symlinkat(argv[1], newdirfd, argv[2]) < 0) {
        perror("symlink");
    }
    return 0;
}