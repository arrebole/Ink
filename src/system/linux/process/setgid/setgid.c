#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 设置调用进程的用户组ID
int setgid(unsigned int gid) { 
  return syscall(SYS_setgid, gid);
}

int main() {
  if (setgid(1) < 0) {
    perror("setgid");
  }
  printf("getgid: %d\n", getgid());
  return 0;
}