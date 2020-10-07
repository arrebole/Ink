#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// exampleChown 设置文件的所有者uid、组gid
void exampleLchown(const char *pathname, uid_t owner, gid_t group) {
    if (lchown(pathname, owner, group) == -1) {
        perror("lchown");
    }
}

int main(int argc, char *argv[]) {
    exampleLchown(argv[1], atol(argv[2]), atol(argv[3]));
    return 0;
}