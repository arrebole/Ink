# linux系统数据

## uname
> 获取当前内核的信息

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

# define _UTSNAME_SYSNAME_LENGTH 65
# define _UTSNAME_NODENAME_LENGTH 65
# define _UTSNAME_RELEASE_LENGTH 65
# define _UTSNAME_RELEASE_LENGTH 65
# define _UTSNAME_MACHINE_LENGTH 65
# define _UTSNAME_DOMAIN_LENGTH 65

struct utsname {
  char sysname[_UTSNAME_SYSNAME_LENGTH];
  char nodename[_UTSNAME_NODENAME_LENGTH];
  char release[_UTSNAME_RELEASE_LENGTH];
  char version[_UTSNAME_RELEASE_LENGTH];
  char machine[_UTSNAME_MACHINE_LENGTH];
  char domainname[_UTSNAME_DOMAIN_LENGTH];
};

int uname(struct utsname *buf) { 
    return syscall(SYS_uname, buf); 
}

int main(int argc, const char *argv[]) {

    struct utsname result;
    if (uname(&result) < 0) {
        perror("uname");
        return 0;
    }

    printf("sysname: %s\n", result.sysname);
    printf("nodename: %s\n", result.nodename);
    printf("release: %s\n", result.release);
    printf("version: %s\n", result.version);
    printf("machine: %s\n", result.machine);
    printf("domainname: %s\n", result.domainname);

    return 0;
}
```

除了系统调用外，还可以通过直接读取内存映射。
```bash
cat /proc/sys/kernel/ostype
cat /proc/sys/kernel/hostname
cat /proc/sys/kernel/osrelease
cat /proc/sys/kernel/version
cat /proc/sys/kernel/domainname
```

## sysinfo
> 获取系统信息

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

struct sysinfo {
    long uptime;
    unsigned long loads[3];
    unsigned long totalram;
    unsigned long freeram;
    unsigned long sharedram;
    unsigned long bufferram;
    unsigned long totalswap;
    unsigned long freeswap;
    unsigned short procs;
    unsigned long totalhigh;
    unsigned long freehigh;
    unsigned int mem_unit;
    char _f[20-2*sizeof(long)-sizeof(int)];
};

int sysinfo(struct sysinfo *info) {
    return syscall(SYS_sysinfo, info);
}

int main(int argc, const char* argv[]) {
    struct sysinfo result;
    if (sysinfo(&result) < 0) {
        perror("sysinfo");
    }

    printf("uptime: %ld\n", result.uptime);
    printf("loads: %lu %lu %lu\n", result.loads);
    printf("totalram: %lu\n", result.totalram);
    printf("freeram: %lu\n", result.freeram);
    printf("sharedram: %lu\n", result.sharedram);
    printf("bufferram: %lu\n", result.bufferram);
    printf("totalswap: %lu\n", result.totalswap);
    printf("freeswap: %lu\n", result.freeswap);
    printf("procs: %hu\n", result.procs);
    printf("totalhigh: %lu\n", result.totalhigh);
    printf("freehigh: %lu\n", result.freehigh);
    printf("mem_unit: %u\n", result.mem_unit);
    return 0;
}
```

除了系统调用外，还可以通过直接读取内存映射。
```bash
cat /proc/meminfo
cat /proc/loadavg
```

## time
> 获取时间来自1970年1月1日00:00:00 +0000（UTC）以来的秒数 [精度秒]

```c
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/syscall.h>

#include <unistd.h>
#include <unistdio.h>

// time get time in seconds
// If tloc is non-NULL, the return value is also stored in the memory pointed to by tloc.
time_t time(time_t *tloc){
    return syscall(SYS_time, tloc);
}

int main() {
    printf("time: %ld", time(NULL));
    return 0;
}
```

## gettimeofday
> 获取系统时间（UTC形式）、`timezone`已废弃 [精度微秒、接口已过时]

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistdio.h>

struct timeval {
    time_t tv_sec;       /* seconds */
    suseconds_t tv_usec; /* microseconds */
};

struct timezone {
    int tz_minuteswest; /* minutes west of Greenwich */
    int tz_dsttime;     /* type of DST correction */
};

// gettimeofday get time
// The use of the timezone structure is obsolete; the tz argument should normally be specified as NULL.
int gettimeofday(struct timeval *tv, struct timezone *tz) {
    return syscall(SYS_gettimeofday, tv, tz);
}

int main() {
    struct timeval tv;

    if (gettimeofday(&tv, NULL) < 0) {
        perror("gettimeofday");
        return 0;
    }
    printf("gettimeofday: %ld %ld", tv.tv_sec, tv.tv_usec);
    return 0;
}
```

## settimeofday
> 设置系统的时间, 设置的时间必须大于当前时间 [精度微秒、接口已过时]

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistdio.h>
#include <stdlib.h>

struct timezone {
    int tz_minuteswest; /* minutes west of Greenwich */
    int tz_dsttime;     /* type of DST correction */
};

// settimeofday set system time
// The use of the timezone structure is obsolete; the tz argument should normally be specified as NULL.
// can't set the CLOCK_REALTIME time prior to (1970 + system uptime). [commit/e1d7ba8735551ed79c7a0463a042353574b96da3]
int settimeofday(struct timeval *tv, struct timezone *tz) {
    return syscall(SYS_settimeofday, tv, tz);
}

int main(int argc, const char* argv[]) {
    if (argc < 3) return 0;
    struct timeval tv = {
        .tv_sec = atol(argv[1]),
        .tv_usec = atol(argv[2]),
    };
    if (settimeofday(&tv, NULL) < 0) {
        perror("settimeofday");
        return 0;
    }
    printf("settimeofday: %ld %ld\n", tv.tv_sec, tv.tv_usec);
    return 0;
}
```

## setdomainname
> 设置NIS域名

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>
#include <string.h>

int setdomainname(const char *name, size_t len){
    return syscall(SYS_setdomainname, name, len);
}

int main(int argc, const char* argv[]){
    if (argc < 1) return 0;
    if (setdomainname(argv[1], strlen(argv[1])) < 0){
        perror("setdomainname");
    }
    return 0;
}
```

## sethostname
> 将主机名设置为字符中给定的值，`x64`平台没有`gethostname`

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistdio.h>
#include <string.h>

// sethostname 
int sethostname(const char *name, size_t len){
    return syscall(SYS_sethostname, name, len);
}

int main(int argc, const char* argv[]){
    if (argc < 1) return 0;

    if (sethostname(argv[1], strlen(argv[1])) < 0){
        perror("sethostname");
    }
    return 0;
}
```

## clock_getres
> 获取时钟的分辨率(精度)

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>
#include <unistdio.h>

// colock_getres 获取时钟的分辨率
int clock_getres(clockid_t clockid, struct timespec *res) {
    return syscall(SYS_clock_getres, clockid, res);
}

int main() {
    struct timespec res;
    // CLOCK_REALTIME, CLOCK_MONOTONIC, CLOCK_PROCESS_CPUTIME_ID, CLOCK_THREAD_CPUTIME_ID
    if (clock_getres(CLOCK_REALTIME, &res) < 0){
        perror("clock_getres");
        return 0;
    }
    printf("%ld %ld\n", res.tv_sec, res.tv_nsec);
    return 0;
}
```

## clock_gettime
> 获取时钟的时间

```c
#define _GNU_SOURCE
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>
#include <unistdio.h>

// clock_gettime 获取时钟的时间
int clock_gettime(clockid_t clockid, struct timespec *tp) {
    return syscall(SYS_clock_gettime, clockid, tp);
}

int main(){
    struct timespec res;
    // CLOCK_REALTIME, CLOCK_MONOTONIC, CLOCK_PROCESS_CPUTIME_ID, CLOCK_THREAD_CPUTIME_ID
    if (clock_gettime(CLOCK_REALTIME, &res) < 0) {
        perror("clock_gettime");
        return 0;
    }
    printf("%ld %ld\n", res.tv_sec, res.tv_nsec);
    return 0;
}
```