#define _GNU_SOURCE
#include <stdio.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/wait.h>

// execute program
int execve(const char *path, char *const *argv, char *const *env){
    return syscall(SYS_execve, path, argv, env);
}

int main(){
    pid_t pid = fork();

    if (pid < 0) perror("fork");
    if (pid == 0) {
        char *argv[] = { "/usr/bin/ls", "./", NULL };
        char *envv[] = { NULL };
        if (execve(argv[0], argv, envv) < 0) {
            perror("execve");
        }
    }
    waitid(P_ALL, 0, NULL, WEXITED);
    return 0;
}