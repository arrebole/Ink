#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 设置真实和/或有效的用户组ID
int setregid(unsigned int rgid, unsigned int egid) { 
  return syscall(SYS_setregid, rgid, egid);
}

int main() {
  if (setregid(101, 0) < 0) {
    perror("setregid");
  }

  printf("getgid: %d\n", getgid());
  printf("getegid: %d\n", getegid());
  return 0;
}