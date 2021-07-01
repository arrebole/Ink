#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

/**
 * munmap 卸载通过 mmap 映射的内容
 * @tags 系统调用函数
*/
int munmap(void *addr, unsigned long len) {
  return syscall(SYS_munmap, addr, len);
}

int main(int argc, const char* argv[]) {
  if (argc < 2) {
    fprintf(stderr, "Need at least one argument to write to the file\n");
    exit(EXIT_FAILURE);
  }
  size_t textsize = strlen(argv[1]) + 1; 

  // 以仅写权限打开一个文件, 如果不存在则创建
  const int fd = open("file", O_CREAT | O_RDWR, (mode_t)0600);
  if (fd == -1) {
    perror("Error opening file for writing");
    exit(EXIT_FAILURE);
  }

  // 为文件分配物理页 
  if (write(fd, "", textsize) == -1) {
    close(fd);
    perror("Error writing last byte of the file");
    exit(EXIT_FAILURE);
  }

  // 将文件通过 mmap 映射到仅写权限的内存中
  char* buffer = mmap(
    NULL, 
    textsize, 
    PROT_WRITE | PROT_READ,
    MAP_SHARED,
    fd, 
    0
  );
  if (buffer == (char*)-1) {
    perror("mmap");
    return -1;
  }

  strcpy(buffer, argv[1]);

  // 卸载映射的内存
  if (munmap(buffer, textsize) == -1) {
    close(fd);
    perror("Error un-mmapping the file");
    exit(EXIT_FAILURE);
  }

  return 0;
}