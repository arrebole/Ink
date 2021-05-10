# linux进程管理

## fork
> 创建一个新的子进程。

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <stdio.h>
#include <unistd.h>

pid_t fork(void) {
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
```

## vfork
> 创建子进程(共用父进程内存空间)并阻止父进程, 直到子进程执行`execve`、`exit`。

```c
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
```

## clone
> 创建子进程,一般用于创建轻量级进程(线程), 与`fork`相比，可以更精确地控制在调用进程和子进程之间共享哪些执行上下文。

```c
#define _GNU_SOURCE
// #include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/mman.h>

#define STACK_SIZE 8192
#define SIGCHLD 17

// both processes share the same signal handlers
#define CLONE_SIGHAND 0x00000800
// both get the same file system information
#define CLONE_FS 0x00000200
//  tells the kernel to let the original process and the clone in the same memory space
#define CLONE_VM 0x00000100
// share file descriptors
#define CLONE_FILES 0x00000400
// this tells the kernel, that both processes would belong to the same thread group (be threads within the same process)
#define CLONE_THREAD 0x00010000

// 创建一个进程，可以创建轻量级进程(线程)
// stack 为子进程的栈顶地址, 如果是创建线程则不能置为NULL
// flags CLONE_FILES、CLONE_FS、CLONE_IO .....
long clone(unsigned long flags, void *stack, int *parent_tid, int *child_tid, unsigned long tls) {
  return syscall(SYS_clone, flags, stack, parent_tid, child_tid, tls);
}

int main(int argc, char *argv[]) {
  char* stack = mmap(
    NULL, 
    STACK_SIZE, 
    PROT_READ | PROT_WRITE,
    MAP_PRIVATE | MAP_ANONYMOUS | MAP_STACK, 
    -1, 
    0
  );
  char* stackTop = stack + STACK_SIZE;

  pid_t pid = clone(CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD, stackTop, NULL, NULL, 0);

  if (pid == -1) {
    perror("clone");
    exit(EXIT_FAILURE);
  };

  if (pid > 0) {
    for (int i = 0; i < 10; i++) {
      printf("[%d] main\n", getpid());
      sleep(1);
    }
  }

  if (pid == 0) {
    for (int i = 0; i < 10; i++) {
      printf("[%d] func\n", getpid());
      sleep(1);
    }
  }

  return 0;
}
```

## clone3
> 创建子进程, clone 的超集。

```c
#define _GNU_SOURCE
#include <syscall.h>
#include <malloc.h>
#include <unistd.h>
#include <sched.h>

typedef unsigned long long u64;

struct clone_args {
  u64 flags;        /* Flags bit mask */
  u64 pidfd;        /* Where to store PID file descriptor (int *) */
  u64 child_tid;    /* Where to store child TID, in child's memory (pid_t *) */
  u64 parent_tid;   /* Where to store child TID, in parent's memory (pid_t *) */
  u64 exit_signal;  /* Signal to deliver to parent on child termination */
  u64 stack;        /* Pointer to lowest byte of stack */
  u64 stack_size;   /* Size of stack */
  u64 tls;          /* Location of new TLS */
  u64 set_tid;      /* Pointer to a pid_t array (since Linux 5.5) */
  u64 set_tid_size; /* Number of elements in set_tid (since Linux 5.5) */
  u64 cgroup;       /* File descriptor for target cgroup of child (since Linux 5.7) */
};

long clone3(struct clone_args *cl_args, unsigned long size) {
    return syscall(SYS_clone3, cl_args, size);
}

int main(int argc, const char* argv[]) {
    int stack_size = 1024;
    char* stack = malloc(stack_size);

    struct clone_args cl_args = {
        .flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND,
        .pidfd = (u64)NULL,
        .child_tid = (u64)NULL,
        .parent_tid = (u64)NULL,
        .exit_signal = (u64)0,
        .stack = (u64)stack,
        .stack_size = (u64)stack_size,
        .tls = (u64)NULL,
        .set_tid = (u64)NULL,
        .set_tid_size = 0,
        .cgroup = 0,
    };

    int pid = clone3(&cl_args, sizeof(cl_args));
    if (pid < 0) perror("clone3");

    if (pid == 0) {
        printf("\nclone\n");
    }
    if (pid > 0) {
        printf("\nmain\n");
        sleep(2);
    }

    return 0;
}
```

## exit
> 进程主动退出。

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>

void exit(int status) { 
    syscall(SYS_exit, status); 
}

int main(int argc, const char* argv[]) {
    exit(100);
}
```

## waitid
> 等待子进程改变状态

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/resource.h>
#include <bits/types/siginfo_t.h>
#include <linux/wait.h>
#include <unistd.h>
#include <stdio.h>

// waitid wait for process to change stat
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
        // 等待子进程退出、并收集子进程退出时的状态
        pid_t w = waitid(P_PID, pid, &infop, WEXITED, NULL);
        if (w < 0) {
           perror("waitid");
           return -1;
        }
        printf("errno: %d signo: %d code: %d \n", infop.si_errno, infop.si_signo, infop.si_code);
    }
    return 0;
}
```

## wait4
> 等待子进程改变状态 (BSD style)

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

// wait4 wait for process to change stat
pid_t wait4(pid_t pid, int *wstatus, int options, struct rusage *rusage) {
    return syscall(SYS_wait4, pid, wstatus, options, rusage);
}

int main(int argc, const char* argv[]) {
    pid_t pid = fork();

    if (pid < 0) perror("fork");
    if (pid == 0) {
        sleep(1);
        printf("I am Child Process\n");
    }
    if (pid > 0) {
        int status;
        struct rusage usage;
        if (wait4(pid, &status, WEXITED, &usage) < 0) {
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
```

## execve
> 执行新程序, 替换旧进程的数据为新进程

```c
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
```

## execveat
> 执行新程序, 替换旧进程的数据为新进程 (相对dirfd)

```c
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
```
## brk
> 更改数据段(堆)大小

```
#define _GNU_SOURCE
#include <stdio.h>
#include <syscall.h>
#define PAGE_SIZE 4096

extern long int syscall (long int __sysno, ...) __THROW;

void * brk(void *addr){
    return (void *) syscall(SYS_brk, addr);
}

int main(int argc, const char* arhv[]){
    char* heapTop;
    char* initHeapTop;

    // 获取当前进程堆的最大的地址
    initHeapTop = brk(NULL);
    heapTop = initHeapTop;
    printf("heap top = %p\n", heapTop);

    // 向操作系统申请堆内存
    heapTop = brk(heapTop + PAGE_SIZE);
    printf("heap top = %p(+brk)\n", heapTop);

    // 将堆内存还给操作系统
    // fix: 调用brk后出现x86_64 printf段错误, 不能将内存全部归还
    heapTop = brk(initHeapTop+1);
    printf("heap top = %p(-brk)\n", heapTop);

    return 0;
}
```

## mmap
> 将文件或设备映射到内存

```c
#define _GNU_SOURCE
#include <stdio.h>
#include <syscall.h>
#include <unistd.h>
#include <string.h>

#define MMAP_SIZE 4096
#define PROT_READ 0x1  // Pages may be read
#define PROT_WRITE 0x2 // Pages may be written
#define MAP_PRIVATE 0x2 // Not visible to other processes
#define MAP_ANONYMOUS 0x20 // The mapping is not backed by any file

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offse) { 
    return (void *)syscall(SYS_mmap, addr, length, prot, flags, fd, offse); 
}

int main(int argc, const char* argv[]) {
    // 申请一块 MMAP_SIZE 大小的可读可写无文件映射内存
    char * array = mmap(
        NULL, 
        MMAP_SIZE, PROT_READ | PROT_WRITE, 
        MAP_PRIVATE | MAP_ANONYMOUS , 
        -1, 
        0
    );
    if (array == (char *) -1) {
        perror("mmap");
        return -1;
    }

    for(int i = 0; i < 10; i++) {
        strcpy(array + i*8, "abcdefg\n");
    }

    printf("%s", array);

    return 0;
}
```

## getrlimit
> 查看当前经常资源限制

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>

// getrlimit get resource limits
int getrlimit(__rlimit_resource_t resource, struct rlimit *rlim) {
    return syscall(SYS_getrlimit, resource, rlim);
}

int main(int argc, const char* argv[]) {
    struct rlimit rlim;

    // RLIMIT_AS, RLIMIT_CORE, RLIMIT_CPU, RLIMIT_DATA ....
    if (getrlimit(RLIMIT_DATA, &rlim) < 0){
        perror("getrlimit");
        return 0;
    }
    printf("%ld/%ld\n", rlim.rlim_cur, rlim.rlim_max);
    return 0;
}
```

## setrlimit
> 限制进程的资源，默认只能减小不能增加(仅root允许增加)，特性会随子进程继承。

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>

// setrlimit set resource limits
int setrlimit(__rlimit_resource_t resource, const struct rlimit *rlim) {
    return syscall(SYS_setrlimit, resource, rlim);
}

int main(int argc, const char* argv[]){
    struct rlimit rlim = {
        .rlim_cur = 1000,
        .rlim_max = 1000,
    };
    if (setrlimit(RLIMIT_NOFILE, &rlim) < 0) {
        perror("setrlimit");
        return 0;
    }
    printf("%ld/%ld\n", rlim.rlim_cur, rlim.rlim_max);
    return 0;
}
```

## getrusage
> 查看已使用的资源占用

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/resource.h>
#include <stdio.h>
#include <unistd.h>

// getrusage get resource usage
// who:
//  RUSAGE_SELF: 该进程下所有线程的资源用量之和
//  RUSAGE_CHILDREN: 所有已终止且被回收子进程的资源用量统计
//  RUSAGE_THREAD: 调用该函数线程的资源用量统计
int getrusage(int who, struct rusage *usage) {
    return syscall(SYS_getrusage, who, usage);
}

int main(int argc, const char* argv[]) {
   struct rusage usage;
   if (getrusage(RUSAGE_SELF, &usage) < 0){
       perror("getrusage");
       return 0;
   }
   printf("user CPU time used: %ld %ld\n", usage.ru_utime.tv_sec, usage.ru_utime.tv_usec);
   printf("block output operations: %ld\n", usage.ru_oublock);
   printf("maximum resident set size: %ld\n", usage.ru_maxrss);
   return 0;
}
```