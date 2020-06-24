#include <stdio.h>

FILE * createFile(char* fName){
    // FILE 在应用层带有缓冲区的文件描述符
    return fopen (fName, "w");
}

int writeToFile(FILE * f, char data[]){
    // 往文件中添加数据
    int err = fputs(data, f);
    if (err < 0){
        return err;
    }
    // 关闭文件句柄
    return fclose(f);
}

// save 将char数组的数据存储在硬盘上
int save(char data[], char * fileName){
    // 打开文件 
    FILE * f = createFile(fileName);
    // 将数据写入文件
    return writeToFile(f, data);
}