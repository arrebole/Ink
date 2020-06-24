// 使用 /lib/x86_64-linux-gnu/libc.so 进行系统调用
#include <unistd.h>

const char* str = "hello world"; 

int main(){
    write(STDOUT_FILENO, str, sizeof(str));
    return 0;
}