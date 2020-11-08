#define _GNU_SOURCE
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>
#include <unistdio.h>
#include <stdlib.h>

// clock_settime 获取时钟的时间
int clock_settime(clockid_t clockid, const struct timespec *tp) {
    return syscall(SYS_clock_settime, clockid, tp);
}

int main(int argc, const char* argv[]) {
    if (argc < 3) return 0;
    struct timespec res = {
        .tv_sec = atol(argv[1]),
        .tv_nsec = atol(argv[2]),
    };
    // CLOCK_REALTIME, CLOCK_MONOTONIC, CLOCK_PROCESS_CPUTIME_ID, CLOCK_THREAD_CPUTIME_ID
    if (clock_settime(CLOCK_REALTIME, &res) < 0) {
        perror("clock_settime");
        return 0;
    }
    printf("%ld %ld\n", res.tv_sec, res.tv_nsec);
    return 0;
}