#define _GNU_SOURCE
#include <sys/syscall.h>
#include <unistd.h>
#include <unistdio.h>

// chdir change working directory
int chdir(const char *path) {
    return syscall(SYS_chdir, path);
}

int main(int argc, char const *argv[]) {

    if (argc < 1) return -1;

    if (chdir(argv[1]) < 0) {
        perror("chdir");
    }

    char buffer[1024];
    if (getcwd(buffer, sizeof(buffer)) == 0) {
        perror("getcwd");
    }
    printf("%s\n", buffer);
    return 0;
}