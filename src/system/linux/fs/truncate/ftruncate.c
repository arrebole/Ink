#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int exampleFtruncate(const char *path, off_t length) {
    int fd = open(path, O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);     
    }
    return ftruncate(fd, length); 
}

int main(int argc, char const *argv[]) {
    exampleFtruncate(argv[1], atol(argv[2]));
    return 0; 
}