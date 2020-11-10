# linux进程管理

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