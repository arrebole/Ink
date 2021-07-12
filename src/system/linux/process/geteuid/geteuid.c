#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 获取调用进程的有效用户ID
unsigned int geteuid() { 
  return syscall(SYS_geteuid);
}

int main() {
  printf("geteuid: %d\n", geteuid());
  return 0;
}