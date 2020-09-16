# Linux

## Table of contents
+ **UNIX标准**
    + [Stdc](#Stdc)
    + [POSIX](#POSIX)
    + [UNSUAL](#UNSUAL)
+ **文件系统**
    + [open](#open)
    + [openat](#openat)
    + [openat2](#openat2)
    + [creat](#creat)
    + [close](#close)
    + [lseek](#lseek)
    + [read](#read)
    + [write](#write)
    + [pread](#pread)
    + [pwrite](#pwrite)
    + [readv](#readv)
    + [writev](#writev)
    + [preadv](#preadv)
    + [pwritev](#pwritev)
    + [preadv2](#preadv2)
    + [pwritev2](#pwritev2)
    + [dup](#dup)
    + [dup2](#dup2)
    + [sync](#sync)
    + [syncfs](#syncfs)
    + [fsync](#fsync)
    + [fdatasync](#fdatasync)
    + [fcntl](#fcntl)
    + [ioctl](#ioctl)
    + [stat](#stat)
    + [lstat](#lstat)
    + [fstat](#fstat)
    + [fstatat](#fstatat)

## UNIX标准

### Stdc
> ANSI C、ISO C、Standard C是指美国国家标准协会（ANSI）和国际标准化组织（ISO）对C语言发布的标准。

| 头文件        | 说明 |
| ------------ | ---- |
| <assert.h>   | 验证程序断言 |
| <complex.h>  | 复数算数运算支持 |
| <ctype.h>    | 字符分类和映射支持 |
| <errno.h>    | 出错码 |
| <fenv.h>     | 浮点环境 |
| <float.h>    | 浮点常量及特征 |
| <inttypes.h> | 整形格式变换 |
| <iso646.h>   | 赋值、关系及一元操作符宏 |
| <limits.h>   | 实现常量 |
| <locale.h>   | 本地化类别及相关定义 |
| <math.h>     | 数学函数，类型声明及常量 |
| <setjmp.h>   | 非局部goto |
| <signal.h>   | 信号 |
| <stdarg.h>   | 可变长度参数表 |
| <stdbool.h>  | 布尔类型和值 |
| <stddef.h>   | 标准定义 |
| <stdint.h>   | 整形 |
| <stdio.h>    | 标准io库 |
| <stdlib.h>   | 实用函数 |
| <string.h>   | 字符串操作 |
| <tgmath.h>   | 通用类型数学宏 |
| <time.h>     | 时间和日期 |
| <wchar.h>    | 扩充的多字节和宽字符支持 |
| <wctype.h>   | 宽字符分类和映射支持 |

### POSIX

> **C POSIX library**是C语言的`POSIX`系统下的标准库。包含了一些在C语言标准库之外的函数。

| 头文件       | 说明 |
| ---------------- | ------------------------------------------------------------ |
| <aio.h>          | 异步`I/O` |
| <cpio.h>         | 用于`cpio` |
| <dirent.h>       | 打开与列出目录 |
| <dlfcn.h>        | 动态链接 |
| <fcntl.h>        | 文件打开、加锁等操作 |
| <fmtmsg.h>       | Message显示结构 |
| <fnmatch.h>      | 文件名匹配 |
| <ftw.h>          | 文件树遍历 |
| <glob.h>         | 路径名模式匹配 `Glob` |
| <grp.h>          | 用户`Group identifier (Unix)`信息与控制。 |
| <iconv.h>        | 字符编码转换 |
| <langinfo.h>     | 语言信息常量。建于`Locale.h`之上。 |
| <libgen.h>       | 路径名操作 |
| <monetary.h>     | 货币单位的字符串格式化 |
| <mqueue.h>       | 消息队列 |
| <ndbm.h>         | `NDBM` 数据库操作 |
| <netdb.h>        | 把本地协议与主机名翻译为数值地址。是Berkeley套接字的一部分 |
| <nl_types.h>     | 本体化消息分类函数 |
| <poll.h>         | 异步多工文件描述符 |
| <pthread.h>      | `POSIX` 线程 |
| <pwd.h>          | `passwd`文件访问与控制 |
| <regex.h>        | 正则表达式 |
| <sched.h>        | 执行调度 |
| <search.h>       | 搜索表 |
| <semaphore.h>    | `POSIX` 信号量 |
| <spawn.h>        | `spawning` |
| <strings.h>      | 大小写不敏感字符串比较 |
| <stropts.h>      | 流操作，包括`ioctl` |
| <syslog.h>       | `syslog`系统日志 |
| <tar.h>          | tar文件格式的Magic number |
| <termios.h>      | 允许串口界面 |
| <trace.h>        | 运行时行为追踪（过时） |
| <ulimit.h>       | 资源限制（被<sys/resource.h>代替） |
| <unistd.h>       | 多种必要的POSIX函数与常量 |
| <utime.h>        | `inode` 访问与修改时间 |
| <utmpx.h>        | 用户账号数据库函数 |
| <wordexp.h>      | 子扩展，类似于`shell`被执行 |

| 头文件       | 说明 |
| ---------------- | ------------------------------------------------------------ |
| <arpa/inet.h>    | 操纵数值IP地址的函数 (部分[Berkeley套接字) |
| <net/if.h>       | 本地网络接口列表 |
| <netinet/in.h>   | 定义互联网协议与地址族。是`Berkeley`套接字的一部分 |
| <netinet/tcp.h>  | 额外的`TCP`的控制选项。是`Berkeley`套接字的一部分 |

| 头文件       | 说明 |
| ---------------- | ------------------------------------------------------------ |
| <sys/ipc.h>      | 进程间通信 (IPC) |
| <sys/mman.h>     | 内存管理，包括POSIX 进程间通信与内存映射文件 |
| <sys/msg.h>      | `POSIX` 消息队列 |
| <sys/resource.h> | 资源使用，优先级与限制。 |
| <sys/select.h>   | `Select Unix` |
| <sys/sem.h>      | `XSI SysV`风格的信号量 |
| <sys/shm.h>      | `XSI` 风格的共享内存 (进程间通信) |
| <sys/socket.h>   | 套接字主要头文件 |
| <sys/stat.h>     | 文件信息 |
| <sys/statvfs.h>  | 文件系统信息 |
| <sys/time.h>     | 时间与日期函数与结构 |
| <sys/times.h>    | 文件访问与修改时间 |
| <sys/types.h>    | 不同的数据类型 |
| <sys/uio.h>      | 向量`I/O`操作 |
| <sys/un.h>       | `Unix`域套接字 |
| <sys/utsname.h>  | 操作系统信息，包括 `uname` |
| <sys/wait.h>     | 终止子进程的状态 |

### UNSUAL

| 头文件            | 说明 |
| ---------------- | ------------------------------------------ |
| <sys/syscall.h>  | 系统调用表汇总 |
| <asm/unistd.h>   | `NR_` 开头的系统调用函数表 |
| <bits/syscall.h> | `SYS_` 开头的系统调用表 (从NR做了名称转换) |


## 文件系统

### open
> 打开或创建一个文件, 打开的描述符一定是最小的未用描述符数值。

```c
// open 打开一个文件返回一个文件描述符
int open(const char *pathname, int flags, mode_t mode);
```

```c
#include <fcntl.h>

// sampleOpenFile 打开一个文件，返回它的可读可写的描述符。
void sampleOpenFile() {
    int fd = open('file', O_RDWR);
}

// sampleCreateFile 通过 open 创建文件 
void sampleCreateFile() {
    int fd = open('file', O_CREAT, 0654);
}
```
### openat
> （path为相对路径时）打开以fd指向的文件的目录作为为基址,加上path路径的相对路径

```c
// openat（path为相对路径时）打开以fd指向的文件的目录作为为基址加上path路径的文件
int openat(int dirfd, const char *pathname, int flags, mode_t ...mode?);
```

```c
// 使用 openat() 需要定义功能测试宏
#define _ATFILE_SOURCE 
#include <fcntl.h>

// sampleOpenat -> ../../../file2
void sampleOpenat() {
    int baseFd = open("../../fs", O_RDONLY);
    int superFd = openat(baseFd, "../file2", O_CREAT | O_TRUNC | O_RDWR, 0654);
}
```

### openat2
> openat() 的增强版本，此函数与虚拟化容器等相关。kernel 5.6+

```c
#define _GNU_SOURCE
#include <fcntl.h>
#include <linux/openat2.h>
#include <sys/syscall.h>
#include <unistd.h>

// openat2 Glibc目前没有为该系统调用提供包装器，所以需要手动调用
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
    // 将目录描述符作为root文件夹， 达到类似 chroot 的效果
    .resolve = RESOLVE_IN_ROOT,
  };
  // 即使是绝对路径依然按照 dirFd 为根目录。
  return openat2(dirFd, "/openat2/file", &openHow, sizeof(openHow));
}
```

### creat
> 创建一个文件，返回只写方式的文件描述符。

```c
// creat 按只写方式创建一个文件
int creat(const char *path, mode_t mode)
```

```c
#include <fcntl.h>

void sampleCreat(){
    int fd = creat("./sample", 0644);
}
```

### close
> 关闭一个打开的文件

```c
// close 关闭一个打开的文件
int close(int fd);
```

```c
#include <unistd.h>
#include <fcntl.h>

void sampleClose(){
    int fd = creat('./sample', 0644);
    close(fd);
}
```

### lseek
> 设置当前文件偏移量（影响读写的开始位置）

```c
// lessk 设置文件偏移量
long lessk(int fd, int offset, int whence) 
```

```c
#include <unistd.h>
#include <fcntl.h>

int sampleLseek() {
    int fd = creat('sample', 0644);

    // 获取当前偏移量（当前偏移量+0）
    int offset = lseek(fd, 0 , SEEK_CUR);

    // 设置当前偏移量为 文件最大长度+10byte
    offset = lseek(fd, 10 , SEEK_END);

    // 设置当前偏移量为10byte
    offset = lseek(fd, 10 , SEEK_SET);

}
```

### read
> 从文件描述符中读取内容

```c
// read 从文件描述符中读取内容
ssize_t read(int fd, void *buf, size_t count)
```

```c
#define _GNU_SOURCE
#include <unistd.h>
#include <sys/types.h>

void sampleRead() {
    char buffer[1024];
    // 从标准输入读取数据到用户空间的 buffer 中， 并且限制大小为 1024 byte
    ssize_t byteRead = read(STDIN_FILENO, buffer, sizeof(buffer));
}
```

### write
> 从文件描述符中写数据

```c
// write 从文件描述符中写数据
ssize_t write(int fd, const void *buf, size_t count);
```

```c
#include <unistd.h>
#include <sys/types.h>

void sampleWrite() {
    const char buffer[] = "hello world";
    write(STDOUT_FILENO, buffer, sizeof(buffer));
}
```

### pread
> 从文件描述符中读取内容, 并设置偏移量.(lseek + read)

```c
// 从文件描述符设置偏移量, 并读取数据
ssize_t pread(int fd, void *buf, size_t count, off_t offset);
```

```c
#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <fcntl.h>

void samplePread() {
    int fd = open("./pread.c", O_RDONLY);

    // 从 fd 偏移 202byte 开始，读取数据到 buffer 中
    char buffer[1024];
    ssize_t nReadByte =  pread(fd, buffer, sizeof(buffer), 202);

    // 显示数据
    write(STDOUT_FILENO, buffer, nReadByte);
}
```

### pwrite
> 从文件描述符偏移量处开始写数据数据 (lseek + write)

```c
// 从文件描述符偏移量处开始写数据数据
ssize_t pwrite(int fd, const void *buf, size_t count, off_t offset);
```

```c
#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <fcntl.h>

void samplePwrite() {
    int fd = open("./pwrite.c", O_RDONLY);

    // 从 fd 偏移 202byte 开始，读取数据到 buffer 中
    char buffer[1024];
    ssize_t nReadByte =  read(fd, buffer, sizeof(buffer));

    // 从标准输出偏移 10byte 处开始写数据
    int outFd = creat("./out", 0644);
    pwrite(outFd, buffer, nReadByte, 66);
}
```

### dup
> 复制一个现有的文件描述符, 新描述符为可用最小值。(使用同一份表项)

```c
// 复制一个现有的文件描述符,
int dup(int fildes);
```
```c
#include <unistd.h>

void sampleDup(){
    int fd = dup(STDOUT_FILENO);
    
    char buffer[] = "hello world";
    write(fd, buffer, sizeof(buffer));
}

```

### dup2
> 复制一个现有的文件描述符，并指定新的描述符编号。(使用同一份表项)

```c
// dup2 复制描述符 fildes 为 fildes2，如果 fildes2 已经被打开，则先关闭。
int dup2(int fildes, int fildes2);
```

```c
#include <unistd.h>

void sampleDup2(){
    int fd = dup2(STDOUT_FILENO, 10);
    
    char buffer[] = "hello world";
    write(10, buffer, sizeof(buffer));
}
```

### sync
> 请求操作系统，将所有数据写入磁盘

```c
// sync 请求内核将所有的文件同步到硬盘。
void sync(void);
```

```c
#include <unistd.h>
#include <fcntl.h>

void sampleSync(){
    int fd = open("./outfile", O_CREAT | O_WRONLY, 0644);

    // 将数据写入文件描述符
    write(fd, "hello world", 12);

    // 请求进程内的文件描述符数据同步到磁盘。
    sync();
}
```

### syncfs
> 请求操作系统, 将与此文件关联的文件系统的所有数据写入磁盘。(仅限Linux)

```c
// syncfs 请求内核将指定的文件描述符数据同步到硬盘。
int syncfs(int fd);
```

```c
#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>

void sampleSyncfs(){
    int fd = open("./outfile", O_CREAT | O_WRONLY, 0644);

    // 将数据写入文件描述符
    write(fd, "hello world", 12);

    // 请求指定的文件描述符数据同步到磁盘。
    syncfs(fd);
}
```

### fsync
> 将此文件的所有数据和元数据写入磁盘，完成后才返回

```c
// fsync 等待内核将指定文件描述符的内容和属性同步到硬盘。
int fsync(int fd);
```

```c
#include <unistd.h>
#include <fcntl.h>

void sampleFsync(){
    int fd = open("./outfile", O_CREAT | O_WRONLY, 0644);

    // 将数据写入文件描述符
    write(fd, "hello world", 12);

    // 阻塞等待内核将指定文件描述符的内容同步到硬盘。
    fsync(fd);
}
```

### fdatasync
> 将此文件的所有数据(不包括文件属性)写入磁盘，完成后才返回

```c
// fdatasync / 等待进程内的文件描述符数据(不等待属性同步)同步到磁盘。
int fdatasync(int fd);
```

```c
#define _GNU_SOURCE
#include <unistd.h>
#include <fcntl.h>

void sampleSync(){
    int fd = open("./outfile", O_CREAT | O_WRONLY, 0644);

    // 将数据写入文件描述符
    write(fd, "hello world", 12);

    fdatasync(fd);
}
```

### fcntl
> 获取或改变已经打开文件的属性

```c
// fcntl 获取或改变已经打开文件的属性
int fcntl(int __fd, int __cmd, ...)
```

```c
#include <fcntl.h>
#include <unistd.h>

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
```

### ioctl
> io操作的杂项函数

```c
// ioctl io操作的杂项函数
int ioctl(int fd, unsigned long __request, ...)
```

```c
#include <unistd.h>
#include <sys/ioctl.h>
#include <stdio.h>

// sampleIoctl 利用ioctl获取终端大小
void sampleIoctl() {
    struct winsize ws;

    // 获取终端设备的大小
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);

    char buffer[1024];
    int nSize = sprintf(buffer, "col: %d\nrow: %d\n",ws.ws_col, ws.ws_row); 
    write(STDOUT_FILENO, buffer, nSize);
}
```

### stat
> 获取文件信息

```c
// stat 获取pathname文件的信息，返回statbuf的结构体指针
int stat(const char *pathname, struct stat *statbuf);
```

```c
void sampleStat() {
    struct stat statbuff;

    stat("./stat.c", &statbuff);

    printf("file size: %ld\n", statbuff.st_size);
    printf("last modify: %ld\n", statbuff.st_mtime);
    printf("last access: %ld\n", statbuff.st_atime);
}
```

### lstat
> 获取文件信息 (不会跟随符号链接跳转)

```c
// lstat 获取 pathname 的文件信息 (不会跟随符号链接跳转)
int lstat(const char *pathname, struct stat *statbuf);
```

```c
void sampleLstat() {
    struct stat statbuff;

    lstat("./lstat.c", &statbuff);

    printf("file size: %ld\n", statbuff.st_size);
    printf("last modify: %ld\n", statbuff.st_mtime);
    printf("last access: %ld\n", statbuff.st_atime);
}
```

### fstat
> 通过文件描述符获取文件信息 (不会跟随符号链接跳转)

```c
// fstat 获取文件描述符 fd 的文件信息
int fstat(int fd, struct stat *statbuf);
```

```c
#define _XOPEN_SOURCE 500

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void sampleFstat() {

    int fd = open("./fstat.c", O_RDWR);

    struct stat statbuff;
    fstat(fd, & statbuff);

    printf("file size: %ld\n", statbuff.st_size);
    printf("last modify: %ld\n", statbuff.st_mtime);
    printf("last access: %ld\n", statbuff.st_atime);
}
```

### fstatat
> 获取相对于文件描述符所引用的目录的文件的信息

```c
// fstatat 获取文件信息（指向 dirfd + pathname 寻找到的文件）
int fstatat(int dirfd, const char *pathname, struct stat *statbuf, int flags);
```

```c
#define _ATFILE_SOURCE

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

void sampleFstatat() {
    int dirFd = open("../../fs", O_RDONLY);

    struct stat statbuff;
    fstatat(dirFd, "./fstatat/fstatat.c", &statbuff, 0);

    printf("file size: %ld\n", statbuff.st_size);
    printf("last modify: %ld\n", statbuff.st_mtime);
    printf("last access: %ld\n", statbuff.st_atime);
}
```