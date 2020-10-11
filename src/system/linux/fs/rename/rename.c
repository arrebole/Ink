#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

// renameat change the name or location of a file
int rename(const char *oldpath, const char *newpath) {
    return syscall(SYS_rename, oldpath, newpath);
}

void exampleRename(const char *oldpath, const char *newpath) {
    if (rename(oldpath, newpath) < 0) {
        perror("rename");
    }
}

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        printf("args error\n");
        _exit(-1);
    }
    exampleRename(argv[1], argv[2]);
    return 0;
}
