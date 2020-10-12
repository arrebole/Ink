#define _GNU_SOURCE
#include <sys/syscall.h>
#include <fcntl.h>
#include <unistd.h>
#include <unistdio.h>

// readlinkat read value of a symbolic link
ssize_t readlinkat(int dirfd, const char *pathname, char *buf, size_t bufsiz){
    return syscall(SYS_readlinkat, dirfd, pathname, buf, bufsiz);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) return -1;

    int dirfd = open(".", O_DIRECTORY);
    if (dirfd < 0) {
        perror("open");
        return -1;
    }

    char buffer[1024];
    ssize_t nbytes = readlinkat(dirfd, argv[1], buffer, sizeof(buffer));
    if (nbytes < 0){
        perror("readlink");
        return -1;
    }
    
    write(STDOUT_FILENO, buffer, nbytes);
    return 0;
}