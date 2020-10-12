#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

// symlink make a new name for a file
int symlink(const char *target, const char *linkpath) { 
    return syscall(SYS_symlink, target, linkpath);
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        printf("args error\n");
        _exit(-1);
    }

    if (symlink(argv[1], argv[2]) < 0) {
        perror("symlink");
    }
    return 0;
}