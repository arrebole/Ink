#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int exampleTruncate(const char *path, off_t length) { 
    return truncate(path, length); 
}

int main(int argc, char const *argv[]) {
    exampleTruncate(argv[1], atol(argv[2]));
    return 0; 
}
