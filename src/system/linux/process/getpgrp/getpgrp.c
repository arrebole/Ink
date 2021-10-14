#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>

extern long int syscall (long int __sysno, ...);

// 获取某个进程的进程组ID (BSD)
int getpgrp() {
    return syscall(SYS_getpgrp);
}

int main() {
    printf("getpgrp [%d]\n", getpgrp());
}