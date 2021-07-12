#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 返回调用进程的用户ID
unsigned int getuid() { 
  return syscall(SYS_getuid); 
}

int main() {
  printf("getuid: %d\n", getuid());
  return 0;
}