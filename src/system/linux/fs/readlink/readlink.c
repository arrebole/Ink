#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

// readlink read value of a symbolic link
ssize_t readlink(const char *pathname, char *buf, size_t bufsiz){
    return syscall(SYS_readlink, pathname, buf, bufsiz);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) return -1;

    char buffer[1024];
    ssize_t nbytes = readlink(argv[1], buffer, sizeof(buffer));
    if (nbytes < 0){
        perror("readlink");
        return -1;
    }
    
    write(STDOUT_FILENO, buffer, nbytes);
    return 0;
}