#define _GNU_SOURCE
#include <unistd.h>
#include <unistdio.h>
#include <sys/syscall.h>

// rmdir deletes a directory, which must be empty
int rmdir(const char *pathname) {
    return syscall(SYS_rmdir, pathname);
}

int main(int argc, const char* argv[]) {
    if (argc < 1) return -1;

    if (rmdir(argv[1])) {
        perror("mkdir");
        return -1;
    }
    return 0;
}