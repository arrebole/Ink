#define _GNU_SOURCE
#include <stdio.h>
#include <syscall.h>
#include <unistd.h>
#include <string.h>

#define MMAP_SIZE 4096
#define PROT_READ 0x1  // Pages may be read
#define PROT_WRITE 0x2 // Pages may be written
#define MAP_PRIVATE 0x2 // Not visible to other processes
#define MAP_ANONYMOUS 0x20 // The mapping is not backed by any file

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offse) { 
    return (void *)syscall(SYS_mmap, addr, length, prot, flags, fd, offse); 
}

int main(int argc, const char* argv[]) {
    // 申请一块 MMAP_SIZE 大小的可读可写无文件映射内存
    char * array = mmap(
        NULL, 
        MMAP_SIZE, PROT_READ | PROT_WRITE, 
        MAP_PRIVATE | MAP_ANONYMOUS , 
        -1, 
        0
    );
    if (array == (char *) -1) {
        perror("mmap");
        return -1;
    }

    for(int i = 0; i < 10; i++) {
        strcpy(array + i*8, "abcdefg\n");
    }

    printf("%s", array);

    return 0;
}