#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

extern long int syscall (long int __sysno, ...);

// getpgid 获取pid进程的进程组id, 如果参数pid为0, 则会取得目前进程的组识别码.
// 没有设置进程组ID时，默认进程组ID等于进程ID 
int getpgid(int pid) {
    return syscall(SYS_getpgid, pid);
}

int main() {
    printf("getpid [%d]\n", getpid());
    printf("getpgid [%d]\n", getpgid(getpid()));
}