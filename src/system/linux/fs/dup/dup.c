#include <unistd.h>

void sampleDup(){
    int fd = dup(STDOUT_FILENO);
    
    char buffer[] = "hello world";
    write(fd, buffer, sizeof(buffer));
}
