#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>

#define PRIO_PROCESS 0
#define PRIO_PGRP 1
#define PRIO_USER 2

extern long int syscall (long int __sysno, ...);

int setpriority(int which, unsigned int who, int prio) {
    return syscall(SYS_setpriority, which, who, prio);
}

int getpriority(int which, unsigned int who) {
    return syscall(SYS_getpriority, which, who);
}

int main() {
    int PRIO_PROCESS_ID = 2288902;
    int PRIO = 39;
    if (setpriority(PRIO_PROCESS, PRIO_PROCESS_ID, PRIO) < 0) {
        perror("setpriority");
        return -1;
    }
    int result = getpriority(PRIO_PROCESS, PRIO_PROCESS_ID);
    printf("getpriority [getpriority=%d, priority=%d, nice=%d]\n", result, 40 - result, 20 - result);
    return 0;
}