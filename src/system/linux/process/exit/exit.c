#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>

void exit(int status) { 
    syscall(SYS_exit, status); 
}

int main(int argc, const char* argv[]) {
    exit(100);
}