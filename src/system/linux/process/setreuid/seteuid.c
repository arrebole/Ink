#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 设置真实和/或有效的用户ID
int setreuid(unsigned int ruid, unsigned int euid) { 
  return syscall(SYS_setreuid, ruid, euid);
}

int main() {
  if (setreuid(101, 0) < 0) {
    perror("setreuid");
  }

  printf("getuid: %d\n", getuid());
  printf("geteuid: %d\n", geteuid());
  return 0;
}