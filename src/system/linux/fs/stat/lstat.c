#define _XOPEN_SOURCE 500

#include <sys/stat.h>
#include <stdio.h>

void sampleLstat() {
    struct stat statbuff;

    lstat("./lstat.c", &statbuff);

    printf("file size: %ld\n", statbuff.st_size);
    printf("last modify: %ld\n", statbuff.st_mtime);
    printf("last access: %ld\n", statbuff.st_atime);
}