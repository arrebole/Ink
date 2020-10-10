#include <unistd.h>
#include <stdio.h>

void sampleLink(const char *oldpath, const char *newpath) {
    if (link(oldpath, newpath) < 0) {
        perror("link");
    }
}

int main(int argc, char const *argv[]){
    sampleLink(argv[1], argv[2]);
    return 0;
}