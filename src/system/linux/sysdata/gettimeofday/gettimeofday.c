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