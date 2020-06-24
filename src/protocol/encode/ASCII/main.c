/**
  * encode ascii
  * ascii string 是纯粹的byte数组，一个byte对应一个字符
  *
*/

#include "./save.h"

int main(){

    // 创建一个二进制数组，使用ascii编码， 每个字符宽度为 1byte
    // ascii表 h(0x68) e(0x65) l(0x6C) o(0x6F) CR(0x0D, '\r') + LF(0x0A,'\n')
    // 0x0 提示函数写入终止，防止末尾的垃圾数据被写入(c没有数组越界检测)
    char txt[] = {0x68, 0x65, 0x6C, 0x6C, 0x6F, 0x0};
    
    // 将二进制数据直接写入文件中
    // 在c语言中：数组是转递首地址
    save(txt, "a.txt");
    
    return 0;
}