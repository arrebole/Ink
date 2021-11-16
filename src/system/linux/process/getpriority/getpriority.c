#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>

#define PRIO_PROCESS 0
#define PRIO_PGRP 1
#define PRIO_USER 2

extern long int syscall (long int __sysno, ...);

// 获取父进程的 `pid`
int getpriority(unsigned int which, int who) {
    return syscall(SYS_getpriority, which, who);
}

int main() {
    int PRIO_PROCESS_ID = 2288902;
    int result = getpriority(PRIO_PROCESS, PRIO_PROCESS_ID);
    if (result == -1) {
        perror("getpriority");
        return -1;
    }
    printf("getpriority [getpriority=%d, priority=%d, nice=%d]\n", result, 40 - result, 20 - result);
    return 0;
}