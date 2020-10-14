#define _GNU_SOURCE
#include <unistd.h>
#include <unistdio.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <linux/time.h>

// utimensat change file timestamps with nanosecond precision
// times[0]  specifies  the  new access time, and times[1] specifies the new modification time
int utimensat(int dirfd, const char *pathname, const struct timespec times[2], int flags) {
    return syscall(SYS_utimensat, dirfd, pathname, times);
}

int main(int argc, const char* argv[]) {
    if (argc < 2) return -1;

    int dirfd = open(".", O_DIRECTORY);
    if (dirfd < 0) {
        perror("open");
        return -1;
    }

    // 修改文件的最后一次访问时间和最后一次修改时间, flags: 可以指定时间相对与现在，或相对于原来，默认0
    // 为确保精度，每个结构体表示一个时间，记录一个时间的秒和毫秒(s, ms)
    struct timeval times[2] = {{100, 100}, {100, 100}};
    if (utimensat(dirfd, argv[1], times, 0) < 0) {
        perror("utimes");
    }

    return 0;
}