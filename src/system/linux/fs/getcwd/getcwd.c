#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

// getcwd get current working directory
char* getcwd(char * buf, size_t size) {
    return (char*) syscall(SYS_getcwd, buf, size);
}

int main(int argc, char const *argv[]) {

    char buffer[1024];
    if (getcwd(buffer, sizeof(buffer)) == 0) {
        perror("getcwd");
        return -1;
    }
    printf("%s\n", buffer);
    return 0;
}