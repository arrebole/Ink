#include <fcntl.h>

// creat 按只写方式创建一个文件
// int creat(const char *path, mode_t mode)

void sampleCreat(){
    int fd = creat("./sample", 0644);
}

int main(){
    sampleCreat();
    return 0;
}