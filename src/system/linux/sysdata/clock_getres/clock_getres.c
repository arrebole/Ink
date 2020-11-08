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
    if (clock_getres(CLOCK_REALTIME, &res) < 0){
        perror("clock_getres");
        return 0;
    }
    printf("%ld %ld\n", res.tv_sec, res.tv_nsec);
    return 0;
}