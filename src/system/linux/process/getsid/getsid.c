#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

extern long int syscall (long int __sysno, ...);

// getsid 获取pid进程的会话的 leader ID 即会话ID
int getsid(int pid) {
    return syscall(SYS_getsid, pid);
}

int main() {
    printf("getsid [%d]\n", getsid(0));
}