#include <stdio.h>
#include <unistd.h>

void exampleUnlink(const char* name) {
    if (unlink(name) < 0) {
        perror("unlink");
        _exit(-1);
    }
}

int main(int argc, char const* argv[]) {
    exampleUnlink(argv[1]);
    return 0;
}
