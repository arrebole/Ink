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