#define _GNU_SOURCE
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int vfork(void) {
    return syscall(SYS_vfork);
}

int main(int argc, const char * argv[]) {
    int var = 10;

    printf("before vfork\n");

    pid_t pid = vfork();
    if (pid < 0) {
        perror("vfork");
    }
    if (pid == 0) {
        var++;
        _exit(EXIT_SUCCESS);
    }

    printf("pid = %ld, var = %d\n", getpid(), var);
    _exit(EXIT_SUCCESS);
    return 0;
}