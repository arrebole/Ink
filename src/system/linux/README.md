


## Table of contents
+ **UNIX标准**
    + [StdC](#Std-C)
    + [POSIX](#POSIX)
    + [UNSUAL](#UNSUAL)
+ **文件IO**
    + [open( )]()


## UNIX标准

### Std-C
> ANSI C、ISO C、Standard C是指美国国家标准协会（ANSI）和国际标准化组织（ISO）对C语言发布的标准。

| 头文件       | 说明 |
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

> **C POSIX library**是C语言的[POSIX](https://zh.wikipedia.org/wiki/POSIX)系统下的标准库。包含了一些在[C语言标准库](https://zh.wikipedia.org/wiki/C标准库)之外的函数。

| 头文件       | 说明 |
| ---------------- | ------------------------------------------------------------ |
| <aio.h>          | [异步I/O](https://zh.wikipedia.org/wiki/异步I/O)             |
| <cpio.h>         | 用于[cpio](https://zh.wikipedia.org/wiki/Cpio)的[文件格式#Magic number](https://zh.wikipedia.org/wiki/文件格式#Magic_number) |
| <dirent.h>       | 打开与列出[目录](https://zh.wikipedia.org/wiki/目录_(文件系统)). |
| <dlfcn.h>        | [动态链接](https://zh.wikipedia.org/w/index.php?title=动态链接&action=edit&redlink=1) |
| <fcntl.h>        | 文件打开、[加锁](https://zh.wikipedia.org/wiki/文件加锁)等操作 |
| <fmtmsg.h>       | Message显示结构                                              |
| <fnmatch.h>      | 文件名匹配                                                   |
| <ftw.h>          | 文件树遍历                                                   |
| <glob.h>         | 路径名模式匹配[Glob](https://zh.wikipedia.org/w/index.php?title=Glob&action=edit&redlink=1) |
| <grp.h>          | 用户[Group identifier (Unix)](https://zh.wikipedia.org/w/index.php?title=Group_identifier_(Unix)&action=edit&redlink=1)信息与控制。 |
| <iconv.h>        | [字符编码](https://zh.wikipedia.org/wiki/字符编码)转换       |
| <langinfo.h>     | 语言信息常量。建于[Locale.h](https://zh.wikipedia.org/wiki/Locale.h)之上。 |
| <libgen.h>       | 路径名操作                                                   |
| <monetary.h>     | 货币单位的字符串格式化                                       |
| <mqueue.h>       | [消息队列](https://zh.wikipedia.org/wiki/消息队列)           |
| <ndbm.h>         | [NDBM](https://zh.wikipedia.org/w/index.php?title=NDBM&action=edit&redlink=1)数据库操作 |
| <netdb.h>        | 把本地协议与主机名翻译为数值地址。是[Berkeley套接字](https://zh.wikipedia.org/wiki/Berkeley套接字)的一部分 |
| <nl_types.h>     | 本体化消息分类函数                                           |
| <poll.h>         | [异步多工文件描述符](https://zh.wikipedia.org/w/index.php?title=异步多工文件描述符&action=edit&redlink=1) |
| <pthread.h>      | [POSIX线程](https://zh.wikipedia.org/wiki/POSIX线程).        |
| <pwd.h>          | [passwd](https://zh.wikipedia.org/wiki/Passwd)文件访问与控制 |
| <regex.h>        | [正则表达式](https://zh.wikipedia.org/wiki/正则表达式)       |
| <sched.h>        | 执行调度                                                     |
| <search.h>       | 搜索表                                                       |
| <semaphore.h>    | POSIX [信号量](https://zh.wikipedia.org/wiki/信号量)         |
| <spawn.h>        | [spawning](https://zh.wikipedia.org/w/index.php?title=Spawn_(计算)&action=edit&redlink=1)子进程 |
| <strings.h>      | 大小写不敏感字符串比较                                       |
| <stropts.h>      | 流操作，包括[ioctl](https://zh.wikipedia.org/wiki/Ioctl)     |
| <syslog.h>       | [syslog](https://zh.wikipedia.org/wiki/Syslog)系统日志       |
| <tar.h>          | [tar](https://zh.wikipedia.org/wiki/Tar)文件格式的Magic number |
| <termios.h>      | 允许[串口](https://zh.wikipedia.org/wiki/串口)界面           |
| <trace.h>        | 运行时行为追踪（过时）                                       |
| <ulimit.h>       | 资源限制（被<sys/resource.h>代替）                           |
| <unistd.h>       | 多种必要的POSIX函数与常量                                    |
| <utime.h>        | [inode](https://zh.wikipedia.org/wiki/Inode)访问与修改时间   |
| <utmpx.h>        | 用户账号数据库函数                                           |
| <wordexp.h>      | 子扩展，类似于[shell](https://zh.wikipedia.org/wiki/Unix_shell)被执行 |

| 头文件       | 说明 |
| ---------------- | ------------------------------------------------------------ |
| <arpa/inet.h>    | 操纵数值[IP地址](https://zh.wikipedia.org/wiki/IP地址)的函数胡 (部分[Berkeley套接字](https://zh.wikipedia.org/wiki/Berkeley套接字)) |
| <net/if.h>     | 本地[网络接口](https://zh.wikipedia.org/wiki/网络接口)列表   |
| <netinet/in.h>   | 定义互联网协议与地址族。是[Berkeley套接字](https://zh.wikipedia.org/wiki/Berkeley套接字)的一部分 |
| <netinet/tcp.h>  | 额外的[TCP](https://zh.wikipedia.org/wiki/Transmission_Control_Protocol)的控制选项。是[Berkeley套接字](https://zh.wikipedia.org/wiki/Berkeley套接字)的一部分 |

| 头文件       | 说明 |
| ---------------- | ------------------------------------------------------------ |
| <sys/ipc.h>      | [进程间通信](https://zh.wikipedia.org/wiki/进程间通信) (IPC). |
| <sys/mman.h>     | 内存管理，包括POSIX [共享内存 (进程间通信)](https://zh.wikipedia.org/wiki/共享内存_(进程间通信))与[内存映射文件](https://zh.wikipedia.org/wiki/内存映射文件) |
| <sys/msg.h>      | POSIX [消息队列](https://zh.wikipedia.org/wiki/消息队列)。   |
| <sys/resource.h> | 资源使用，优先级与限制。                                     |
| <sys/select.h>   | [Select (Unix)](https://zh.wikipedia.org/wiki/Select_(Unix)) |
| <sys/sem.h>      | XSI ([SysV](https://zh.wikipedia.org/w/index.php?title=Unix_System_V&action=edit&redlink=1)风格的) [信号量](https://zh.wikipedia.org/wiki/信号量) |
| <sys/shm.h>      | XSI ([SysV](https://zh.wikipedia.org/w/index.php?title=Unix_System_V&action=edit&redlink=1)风格的)[共享内存 (进程间通信)](https://zh.wikipedia.org/wiki/共享内存_(进程间通信)) |
| <sys/socket.h>   | [Berkley套接字](https://zh.wikipedia.org/w/index.php?title=Berkley套接字&action=edit&redlink=1)主要头文件 |
| <sys/stat.h>     | 文件信息([stat (Unix)](https://zh.wikipedia.org/wiki/Stat_(Unix))等) |
| <sys/statvfs.h>  | 文件系统信息                                                 |
| <sys/time.h>     | 时间与日期函数与结构                                         |
| <sys/times.h>    | 文件访问与修改时间                                           |
| <sys/types.h>    | 不同的数据类型                                               |
| <sys/uio.h>      | [向量I/O](https://zh.wikipedia.org/w/index.php?title=向量I/O&action=edit&redlink=1)操作 |
| <sys/un.h>       | [Unix域套接字](https://zh.wikipedia.org/wiki/Unix域套接字)   |
| <sys/utsname.h>  | 操作系统信息，包括[uname](https://zh.wikipedia.org/wiki/Uname) |
| <sys/wait.h>     | 终止子进程的状态(见[wait (Unix)](https://zh.wikipedia.org/wiki/Wait_(Unix))) |

### UNSUAL

| 头文件           | 说明                                       |
| ---------------- | ------------------------------------------ |
| <sys/syscall.h>  | 系统调用表汇总                             |
| <asm/unistd.h>   | `NR_` 开头的系统调用函数表                 |
| <bits/syscall.h> | `SYS_` 开头的系统调用表 (从NR做了名称转换) |



## 文件IO

