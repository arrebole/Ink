#define _GNU_SOURCE
#include <unistd.h>
#include <unistdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/syscall.h>

int mkdirat(int dirfd, const char *pathname, mode_t mode) {
    return syscall(SYS_mkdirat, dirfd, pathname, mode);
}

int main(int argc, const char* argv[]) {
    if (argc < 2) return -1;

    int dirfd = open(argv[1], O_DIRECTORY);
    if (dirfd < 0) {
        perror("mkdir");
        return -1;
    }

    if (mkdirat(dirfd, argv[2], S_IRWXU | S_IRGRP | S_IXGRP | S_IXOTH)) {
        perror("mkdir");
        return -1;
    }
    return 0;
}