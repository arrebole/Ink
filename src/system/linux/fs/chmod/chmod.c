#include <sys/stat.h>

// sampleChmod 将 ./chmod.c 文件权限改为只有所有者能够读写
int exampleChmod() {
    return chmod("./chmod.c", S_IRUSR | S_IWUSR);
}

int main(){
    exampleChmod();
    return 0;
}