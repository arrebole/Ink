#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>

extern long int syscall (long int __sysno, ...);

// 获取父进程的 `pid`
int getppid() {
    return syscall(SYS_getppid);
}

int main() {
    printf("getpid [%d]\n", getppid());
}