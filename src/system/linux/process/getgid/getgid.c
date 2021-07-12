#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 返回调用进程的用户组ID
unsigned int getgid() { 
  return syscall(SYS_getgid); 
}

int main() {
  printf("getgid: %d\n", getgid());
  return 0;
}