#define _XOPEN_SOURCE 500

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void sampleFstat() {

    int fd = open("./fstat.c", O_RDWR);

    struct stat statbuff;
    fstat(fd, & statbuff);

    printf("file size: %ld\n", statbuff.st_size);
    printf("last modify: %ld\n", statbuff.st_mtime);
    printf("last access: %ld\n", statbuff.st_atime);
}