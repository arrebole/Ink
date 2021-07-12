#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 设置调用进程的用户ID
int setuid(unsigned int uid) { 
  return syscall(SYS_setuid, uid);
}

int main() {
  if (setuid(99) < 0) {
    perror("setuid");
  }
  printf("getuid: %d\n", getuid());
  return 0;
}