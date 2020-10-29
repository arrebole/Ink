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