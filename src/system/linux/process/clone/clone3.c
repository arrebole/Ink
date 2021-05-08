#define _GNU_SOURCE
#include <malloc.h>
#include <sched.h>
#include <signal.h>
#include <sys/mman.h>
#include <syscall.h>
#include <unistd.h>

typedef unsigned long long u64;

struct clone_args {
  u64 flags;        /* Flags bit mask */
  u64 pidfd;        /* Where to store PID file descriptor (int *) */
  u64 child_tid;    /* Where to store child TID, in child's memory (pid_t *) */
  u64 parent_tid;   /* Where to store child TID, in parent's memory (pid_t *) */
  u64 exit_signal;  /* Signal to deliver to parent on child termination */
  u64 stack;        /* Pointer to lowest byte of stack */
  u64 stack_size;   /* Size of stack */
  u64 tls;          /* Location of new TLS */
  u64 set_tid;      /* Pointer to a pid_t array (since Linux 5.5) */
  u64 set_tid_size; /* Number of elements in set_tid (since Linux 5.5) */
  u64 cgroup; /* File descriptor for target cgroup of child (since Linux 5.7) */
};

#define STACK_SIZE (1024 * 1024)

long clone3(struct clone_args* cl_args, unsigned long size) {
  return syscall(SYS_clone3, cl_args, size);
}

int main(int argc, const char* argv[]) {
  char* stack = mmap(NULL, STACK_SIZE, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS | MAP_STACK, -1, 0);
  if (stack == MAP_FAILED) {
    perror("mmap");
    return 0;
  }

  struct clone_args cl_args = {
      .flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND |
               CLONE_SYSVSEM | CLONE_THREAD,
      .stack = (u64)stack + STACK_SIZE,
      .stack_size = STACK_SIZE,
      .exit_signal = SIGCHLD,
  };

  int pid = clone3(&cl_args, sizeof(cl_args));
  if (pid < 0) perror("clone3");

  if (pid == 0) {
    printf("I am the child, my PID is %d\n", getpid());
  }
  if (pid > 0) {
    printf("I am the parent (%d). My child's pid is %d\n", getpid(), pid);
    sleep(2);
  }

  return 0;
}