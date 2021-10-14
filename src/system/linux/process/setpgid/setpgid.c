#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

extern long int syscall (long int __sysno, ...);

// setpgid 设置进程的进程组ID, 如果参数pid 为0,则会用来设置目前进程
// 如果 setpgid () 用于将一个进程从一个进程组移动到另一个进程组（如创建管道时的一些外壳），两个进程组都必须是同一会话的一部分
int setpgid(int pid, int pgid) {
    return syscall(SYS_setpgid, pid, pgid);
}

int main() {
    printf("getpgid [%d]\n", getpgid(0));
    if (setpgid(0, getpid()) < 0) {
        perror("setpgid");
    }
    printf("getpgid [%d]\n", getpgid(0));
}