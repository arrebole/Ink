/**
  * encode unicode utf-8
  * utf-8 以1byte为单位变长编码
  *
*/

#include "./include/save.h"


// Unicode码 -> utf-8
int EncodeUTF8(int* in, char *out, int len){
    int outIndex = 0;
    for(int i=0; i < len; i++){
        int t = in[i];
 
        // Unicode符号范围0-0x7f 1个字节存储
        if ( t <= 0x7f ) {
            out[outIndex++] = (char)in[i];
        }
       
        // Unicode符号范围 0x80-0x7ff  2个字节存储
        if(t >= 0x80 && t <= 0x7ff){
           out[outIndex++] = (char)(0xc0 | (t >> 6)); //前5位
           out[outIndex++] = (char)(0x80 | (t & 0x3f)); //后6位
        }
        
        // Unicode符号范围 0x800 - 0xffff 3个字节存储
        if( t >= 0x800 && t <= 0xffff){
           out[outIndex++] = (char)(0xe0 | (t >> 12)); //前4位
           out[outIndex++] = (char)(0x80 | (t >> 6 & 0x3f)); //中6位
           out[outIndex++] = (char)(0x80 | (t & 0x3f)); //后6位
        }

        // Unicode符号范围 0x10000 - 0x10FFFF 4个字节存储
        if( t >= 0x10000 && t <= 0x10FFFF){
           out[outIndex++] = (char)(0xf0 | (t >> 18)); //前3bit
           out[outIndex++] = (char)(0x80 | (t >> 12 & 0x3f)); //6bit
           out[outIndex++] = (char)(0x80 | (t >> 6 & 0x3f)); // 6bit
           out[outIndex++] = (char)(0x80 | (t & 0x3f)); // 后6bit
        }
    }
    return outIndex;
}

int main(){
    // 存放unicode码的数组
    // 你好世界 \u4f60\u597d\u4e16\u754c\uff01

    int txt[] = { 0x4f60,0x597d, 0x4e16,0x754c, 0xff01};
    // 存放utf-8编码的byte数组
    char utf8[1024];
    int len = EncodeUTF8(txt, utf8, sizeof(txt)/4);
    
    save(utf8, len, "utf-8.txt");
    return 0;
}