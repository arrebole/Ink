#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// exampleFchown 设置文件的所有者uid、组gid
void exampleFchown(const char *pathname, uid_t owner, gid_t group) {
    int fd = open(pathname, O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    if (fchown(fd, owner, group) == -1) {
        perror("fchown");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    exampleFchown(argv[1], atol(argv[2]), atol(argv[3]));
    return 0;
}