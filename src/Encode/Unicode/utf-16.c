/**
  * encode unicode utf-16
  * utf-16是以 至少2个byte作为一个字符，并且开头使用三个字节的bom指明大小端存储
  * javascript中的string是utf-16编码的
  *
*/

#include "./include/save.h"

// LE小尾序 BE大尾序
const char BOM_LE[] = {0xFF, 0xFE};
const char BOM_BE[] = {0xFE, 0xFF};

// 将ascii编码的char数组转换为utf-16LF编码的char数组
int EncodeUTF16LE(int *in, char * out, int len){
  // 写入bom编码
  out[0] = 0xFF;
  out[1] = 0xFE;

  // 将ascii转为utf-16编码, 1->2 byte
  // U+0000---U+FFFF
  int inIndex  = 0;
  int outIndex = 0 + 2;
  while(inIndex < len){
    int t = in[inIndex++];
    out[outIndex++] = (char)(t & 0xff);
    out[outIndex++] = (char)( t >> 8 );
  }

  return outIndex;
}

// 将ascii编码的char数组转换为utf-16LF编码的char数组
int EncodeUTF16BE(int *in, char * out, int len){
  // 写入bom编码
  out[0] = 0xFE;
  out[1] = 0xFF;

  // 将ascii转为utf-16编码, 1->2 byte
  // U+0000---U+FFFF
  int inIndex  = 0;
  int outIndex = 0 + 2;
  while(inIndex < len){
    int t = in[inIndex++];
    out[outIndex++] = (char)( t >> 8 );
    out[outIndex++] = (char)(t & 0xff);
  }

  return outIndex;
}

int main(){
  // 存放unicode码的数组
  // 由于这些字符unicode码点都是1个字节，所以在utf16只需使用2个字节来保存
  int txt[] = {'h','e','l','l','o',' ','w','o','r','l','d', ' ',0x4e16 ,0x754c, 0xff01};
  char utf16[1024];
  
  // 使用utf-16LF 小尾序编码
  int len = EncodeUTF16LE(txt, utf16, sizeof(txt)/4);
  save(utf16, len, "utf-16LE.txt");

  // 使用utf-16LF 小尾序编码
  len = EncodeUTF16BE(txt, utf16, sizeof(txt)/4);
  save(utf16, len, "utf-16BE.txt");

  return 0;
}