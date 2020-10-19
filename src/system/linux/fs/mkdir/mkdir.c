#define _GNU_SOURCE
#include <unistd.h>
#include <unistdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/syscall.h>

int mkdir(const char* pathname, mode_t mode) {
    return syscall(SYS_mkdir, pathname, mode);
}

int main(int argc, const char* argv[]) {
    if (argc < 1) return -1;

    if (mkdir(argv[1], S_IRWXU | S_IRGRP | S_IXGRP | S_IXOTH)) {
        perror("mkdir");
        return -1;
    }
    return 0;
}