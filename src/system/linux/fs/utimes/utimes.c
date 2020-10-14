#define _GNU_SOURCE
#include <unistd.h>
#include <unistdio.h>
#include <sys/syscall.h>
#include <linux/time.h>

// utimes change file last access and modification times
// times[0]  specifies  the  new access time, and times[1] specifies the new modification time
int utimes(const char *filename, const struct timeval times[2]) {
    return syscall(SYS_utimes, filename, times);
}

int main(int argc, const char* argv[]) {
    if (argc < 2) return -1;

    // 修改文件的最后一次访问时间和最后一次修改时间 
    // 为确保精度，每个结构体表示一个时间，记录一个时间的秒和毫秒(s, ms)
    struct timeval times[2] = {{100, 100}, {100, 100}};
    if (utimes(argv[1], times) < 0) {
        perror("utimes");
    }

    return 0;
}