#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

extern long int syscall (long int __sysno, ...);

// setsid 创建一个会话并设置进程组 ID
int setsid() {
    return syscall(SYS_setsid);
}

int main() {
    if (setsid() < 0) {
        perror("setsid");
    }
    printf("getsid [%d]\n", getsid(0));
}