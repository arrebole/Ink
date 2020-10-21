#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>
#include <fcntl.h>

// chdir change working directory
int fchdir(int fd) {
    return syscall(SYS_fchdir, fd);
}

int main(int argc, char const *argv[]) {

    if (argc < 1) return -1;

    int dirfd = open(argv[1], O_DIRECTORY);
    if (dirfd < 0){
        perror("open");
        return -1;
    }

    if (fchdir(dirfd) < 0) {
        perror("fchdir");
        return -1;
    }

    char buffer[1024];
    if (getcwd(buffer, sizeof(buffer)) == 0) {
        perror("getcwd");
        return -1;
    }
    printf("%s\n", buffer);
    return 0;
}