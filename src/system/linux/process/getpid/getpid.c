#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>

extern long int syscall (long int __sysno, ...);

int getpid() {
    return syscall(SYS_getpid);
}

int main() {
    printf("getpid [%d]\n", getpid());
}