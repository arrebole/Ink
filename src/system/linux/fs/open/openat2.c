// openat2() is supported by Linux 5.6+
// int openat2(int dirfd, const char *pathname, struct open_how *how, size_t
// size); Glibc目前没有为该系统调用提供包装器，所以需要手动调用
// 此函数用于限制子权限，基于传入目录文件夹的描述符的路径权限，此函数与虚拟化容器等相关，

#define _GNU_SOURCE
#include <fcntl.h>
#include <linux/openat2.h>
#include <sys/syscall.h>
#include <unistd.h>

int openat2(int dirfd, const char *pathname, struct open_how *how, int size) {
  return (int)syscall(SYS_openat2, dirfd, pathname, how, size);
}

int sampleOpenat2() {
  // 打开一个目录文件描述符
  int dirFd = open("../../fs", O_RDONLY);

  // 为 openat2 设置访问权限
  struct open_how openHow = {
    .flags = O_CREAT | O_TRUNC | O_RDWR,
    .mode = 0655,
    // 达到类似 chroot 的效果
    .resolve = RESOLVE_IN_ROOT,
  };
  // 即使是绝对路径依然按照 dirFd 为根目录。
  return openat2(dirFd, "/openat2/file", &openHow, sizeof(openHow));
}
