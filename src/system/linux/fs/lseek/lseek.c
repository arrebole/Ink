#include <unistd.h>
#include <fcntl.h>

// 设置文件偏移量
// long lseek(int fd, int offset, int whence) 

int sampleLseek(){
    int fd = creat('sample', 0644);

    // 获取当前偏移量（当前偏移量+0）
    int offset = lseek(fd, 0 , SEEK_CUR);

    // 设置当前偏移量为 文件最大长度+10byte
    offset = lseek(fd, 10 , SEEK_END);

    // 设置当前偏移量为10byte
    offset = lseek(fd, 10 , SEEK_SET);

}