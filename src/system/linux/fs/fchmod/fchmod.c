#define _POSIX_C_SOURCE 199309L
#include <sys/stat.h>
#include <fcntl.h>

// exampleFchmod 将 ./fchmod.c 文件权限改为只有所有者能够读写
int exampleFchmod() {
    int fd = open("./fchmod.c", O_RDWR);
    if (fd < 0) {
        return -1;
    }
    return fchmod(fd, S_IRUSR | S_IWUSR);
}