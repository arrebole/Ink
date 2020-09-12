#include <fcntl.h>
#include <unistd.h>

// fcntl 获取或改变已经打开文件的属性
// int fcntl(int __fd, int __cmd, ...)

void sampleFcntl() {
  // 打开一个文件，并设置文件描述符属性为只写
  int fd = open("./fcntl.c", O_WRONLY, 0644);

  // 获取文件状态标志
  int val = fcntl(fd, F_GETFL, O_RDWR);

  // 读取文件内容
  switch (val & O_ACCMODE) {
    case O_RDONLY:
      write(STDOUT_FILENO, "read only", 10);
      break;

    case O_WRONLY:
      write(STDOUT_FILENO, "write only", 11);
      break;

    case O_RDWR:
      write(STDOUT_FILENO, "read write", 11);
      break;

    default:
      write(STDOUT_FILENO, "unknown access mode", 20);
  }
}