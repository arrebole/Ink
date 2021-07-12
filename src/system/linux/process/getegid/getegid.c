#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 获取调用进程的有效用户组ID
unsigned int getegid() { 
  return syscall(SYS_getegid);
}

int main() {
  printf("getegid: %d\n", getegid());
  return 0;
}