#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/resource.h>
#include <bits/types/siginfo_t.h>
#include <linux/wait.h>
#include <unistd.h>
#include <stdio.h>

// waitid wait for process to change stat
// options: WEXITED | WSTOPPED | WNOWAIT | WNOHANG | WNOWAIT ...
pid_t waitid(int idtype, id_t id, siginfo_t *infop, int options, struct rusage *rusage) {
    return syscall(SYS_waitid, idtype, id, infop, options, rusage);
}

int main(int argc, const char* argv[]) {
    pid_t pid = fork();

    if (pid < 0) perror("fork");
    if (pid == 0) {
        sleep(1);
        printf("I am Child Process\n");
    }
    if (pid > 0) {
        siginfo_t infop;
        struct rusage usage;
        // 等待子进程退出、并收集子进程退出时的状态
        pid_t w = waitid(P_PID, pid, &infop, WEXITED, &usage);
        if (w < 0) {
           perror("waitid");
           return -1;
        }
        printf("errno: %d signo: %d code: %d \n", infop.si_errno, infop.si_signo, infop.si_code);
        printf("user CPU time used: %ld %ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
    }
    return 0;
}