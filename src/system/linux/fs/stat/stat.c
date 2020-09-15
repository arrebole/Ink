#include <sys/stat.h>
#include <stdio.h>

void sampleStat() {
    struct stat statbuff;

    stat("./stat.c", &statbuff);

    printf("file size: %ld\n", statbuff.st_size);
    printf("last modify: %ld\n", statbuff.st_mtime);
    printf("last access: %ld\n", statbuff.st_atime);
}