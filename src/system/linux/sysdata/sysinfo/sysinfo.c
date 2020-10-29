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
