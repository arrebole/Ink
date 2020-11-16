#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

// wait4 wait for process to change state          
// options: WNOHANG | WUNTRACED | WCONTINUED ...
pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage) {
    return syscall(SYS_wait4, pid, wstatus, options, rusage);
}

int main(int argc, const char* argv[]) {
    pid_t pid = fork();

    if (pid < 0) perror("fork");
    if (pid == 0) {
        sleep(1);
        printf("I am Child Process\n");
        return 7;
    }
    if (pid > 0) {
        int status;
        struct rusage usage;
        if (wait4(pid, &status, 0, &usage) < 0) {
            perror("wait4");
            return -1;
        }
        if (WIFEXITED(status)) {
            printf("exit status = %d\n", WEXITSTATUS(status));
        }
        printf("Child Process CPU time used: %ld %ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);;
    }
    return 0;
}