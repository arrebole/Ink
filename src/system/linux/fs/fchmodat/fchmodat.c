# define _POSIX_C_SOURCE 200809L
#include <sys/stat.h>
#include <fcntl.h>

int exampleFchmodat() {
    int dirFd = open("../../fs", O_DIRECTORY);
    if (dirFd < 0) {
        return -1;
    }
    return fchmodat(dirFd, "./fchmodat/fchmodat.c", S_IRGRP | S_IRUSR | S_IWUSR, 0);
}