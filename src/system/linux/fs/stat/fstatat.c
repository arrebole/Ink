#define _ATFILE_SOURCE

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void sampleFstatat() {

    int dirFd = open("../../fs", O_RDONLY);

    struct stat statbuff;
    fstatat(dirFd, "./fstatat/fstatat.c", &statbuff, 0);

    printf("file size: %ld\n", statbuff.st_size);
    printf("last modify: %ld\n", statbuff.st_mtime);
    printf("last access: %ld\n", statbuff.st_atime);
}
