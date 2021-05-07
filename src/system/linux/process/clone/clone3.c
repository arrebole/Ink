#define _GNU_SOURCE
#include <syscall.h>
#include <malloc.h>
#include <unistd.h>
#include <sched.h>

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
  u64 cgroup;       /* File descriptor for target cgroup of child (since Linux 5.7) */
};

long clone3(struct clone_args *cl_args, unsigned long size) {
    return syscall(SYS_clone3, cl_args, size);
}

int main(int argc, const char* argv[]) {
    int stack_size = 1024;
    char* stack = malloc(stack_size);

    struct clone_args cl_args = {
        .flags = CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SIGHAND,
        .pidfd = (u64)NULL,
        .child_tid = (u64)NULL,
        .parent_tid = (u64)NULL,
        .exit_signal = (u64)0,
        .stack = (u64)stack,
        .stack_size = (u64)stack_size,
        .tls = (u64)NULL,
        .set_tid = (u64)NULL,
        .set_tid_size = 0,
        .cgroup = 0,
    };

    int pid = clone3(&cl_args, sizeof(cl_args));
    if (pid < 0) perror("clone3");

    if (pid == 0) {
        printf("\nclone\n");
    }
    if (pid > 0) {
        printf("\nmain\n");
        sleep(2);
    }

    return 0;
}