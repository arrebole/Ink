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