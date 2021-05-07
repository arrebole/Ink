#define _GNU_SOURCE
// #include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <syscall.h>
#include <unistd.h>
#include <sys/mman.h>

#define STACK_SIZE 8192
#define SIGCHLD 17

// both processes share the same signal handlers
#define CLONE_SIGHAND 0x00000800
// both get the same file system information
#define CLONE_FS 0x00000200
//  tells the kernel to let the original process and the clone in the same memory space
#define CLONE_VM 0x00000100
// share file descriptors
#define CLONE_FILES 0x00000400
// this tells the kernel, that both processes would belong to the same thread group (be threads within the same process)
#define CLONE_THREAD 0x00010000

int func(void* args) {
  for (int i = 0; i < 10; i++) {
    printf("[%d] func\n", getpid());
    sleep(1);
  }
  return 0;
}

// 创建一个进程，可以创建轻量级进程(线程)
// stack 为子进程的栈顶地址, 如果是创建线程则不能置为NULL
// flags CLONE_FILES、CLONE_FS、CLONE_IO .....
long clone(unsigned long flags, void *stack, int *parent_tid, int *child_tid, unsigned long tls) {
  return syscall(SYS_clone, flags, stack, parent_tid, child_tid, tls);
}

int main(int argc, char *argv[]) {
  char* stack = mmap(
    NULL, 
    STACK_SIZE, 
    PROT_READ | PROT_WRITE,
    MAP_PRIVATE | MAP_ANONYMOUS | MAP_STACK, 
    -1, 
    0
  );
  char* stackTop = stack + STACK_SIZE;

  pid_t pid = clone(CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_THREAD, stackTop, NULL, NULL, 0);

  if (pid == -1) {
    perror("clone");
    exit(EXIT_FAILURE);
  };

  if (pid > 0) {
    for (int i = 0; i < 10; i++) {
      printf("[%d] main\n", getpid());
      sleep(1);
    }
  }

  if (pid == 0) {
    for (int i = 0; i < 10; i++) {
      printf("[%d] func\n", getpid());
      sleep(1);
    }
  }

  return 0;
}
