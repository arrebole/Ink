#define _POSIX_C_SOURCE 200809L
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void sampleLinkat(const char *oldpath, const char *newpath) {
    int dirFd = open("./", __O_DIRECTORY);
    if (dirFd < 0) {
        perror("open");
        _exit(-1);
    }

    if (linkat(dirFd, oldpath, dirFd, newpath, 0) < 0) {
        perror("link");
        _exit(-1);
    }
}

int main(int argc, char const *argv[]){
    sampleLinkat(argv[1], argv[2]);
    return 0;
}