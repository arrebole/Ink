#define _GNU_SOURCE
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

int fork(void) {
    return syscall(SYS_fork);
}

int main(int argc, const char * argv[]) {
    int var = 88;

    pid_t pid = fork();    
    if (pid < 0) perror("fork");
    if (pid == 0) var++;
    if (pid > 0) sleep(2);
    
    printf("[pid = %ld] var = %d\n", getpid(), var);
    return 0;
}