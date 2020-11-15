#define _GNU_SOURCE
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

pid_t fork(void) {
    return syscall(SYS_fork);
}

int main(int argc, const char * argv[]) {

    int pid = fork();    
    if (pid < 0) {
        perror("fork");
        return 0;
    }

    if (pid > 0) printf("i am parent. [fork return pid = %d]\n", pid);
    if (pid == 0) printf("i am child process. [fork return pid = %d]\n", pid);
    
    return 0;
}