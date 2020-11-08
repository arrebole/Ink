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