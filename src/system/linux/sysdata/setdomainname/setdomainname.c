#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>
#include <string.h>

int setdomainname(const char *name, size_t len){
    return syscall(SYS_setdomainname, name, len);
}

int main(int argc, const char* argv[]){
    if (argc < 1) return 0;
    if (setdomainname(argv[1], strlen(argv[1])) < 0){
        perror("setdomainname");
    }
    return 0;
}