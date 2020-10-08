#define _POSIX_C_SOURCE 200809L
#include <fcntl.h>
#include <unistd.h>

void exampleFaccessat() {
    int fd = open("../../fs", O_DIRECTORY);

    if (fd < 0) return _exit(-1);

    // 使用实际的用户(登录用户)进行权限测试
    if (faccessat(fd, "./faccessat/faccessat.c", X_OK, 0) < 0) {
        write(STDERR_FILENO, "real exec access fail\n", 23);
    }

    // AT_EACCESS 使用有效的用户（该程序所有者）进行权限测试
    if (faccessat(fd, "./faccessat/faccessat.c", X_OK, AT_EACCESS) < 0) {
        write(STDERR_FILENO, "effective exec access fail\n", 28);
    }
}

int main(){
    exampleFaccessat();
    return 0;
}