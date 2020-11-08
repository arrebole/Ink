#define _GNU_SOURCE
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <unistdio.h>
#include <string.h>

// sethostname 
int sethostname(const char *name, size_t len){
    return syscall(SYS_sethostname, name, len);
}

int main(int argc, const char* argv[]){
    if (argc < 1) return 0;

    if (sethostname(argv[1], strlen(argv[1])) < 0){
        perror("sethostname");
    }
    return 0;
}