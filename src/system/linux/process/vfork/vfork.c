#define _GNU_SOURCE
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

pid_t vfork(void) {
    return syscall(SYS_vfork);
}

int main(int argc, const char * argv[]) {
    pid_t pid;
    int result = 99;

    if ((pid = vfork()) < 0) perror("vfork");
    else if (pid == 0) {
        result++;
        _exit(0);
    }
    
    printf("get result from child process %d\n", result);
    exit(0);
    return 0;
}