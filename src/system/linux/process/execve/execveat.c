#define _GNU_SOURCE
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/wait.h>

// execute program
//  flag: 
//    - AT_EMPTY_PATH 如果路径名是空字符串，请对该文件进行操作由dirfd引用（可能已使用的开放（2） O_PATH标志）。
//    - AT_SYMLINK_NOFOLLOW 如果由dirfd标识的文件和非空路径名是符号链接，则调用失败，错误为ELOOP
int execveat(int dirfd, const char *path, char *const *argv, char *const *env, int flag) {
    return syscall(SYS_execveat, dirfd, path, argv, env, flag);
}

int main(){
    pid_t pid = fork();

    if (pid < 0) perror("fork");
    if (pid == 0) {
        int dirfd = open("/usr/bin", O_PATH);
        if (dirfd < 0) {
            perror("open");
            return 0;
        }

        char *argv[] = { "ls", "./", NULL };
        char *envv[] = { NULL };
        if (execveat(dirfd, argv[0], argv, envv, 0) < 0) {
            perror("execve");
        }
    }
    waitid(P_ALL, 0, NULL, WEXITED);
    return 0;
}