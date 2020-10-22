# UNIX标准头文件

## STDC
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

## POSIX

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

## UNSUAL

| 头文件            | 说明 |
| ---------------- | ------------------------------------------ |
| <sys/syscall.h>  | 系统调用表汇总 |
| <asm/unistd.h>   | `NR_` 开头的系统调用函数表 |
| <bits/syscall.h> | `SYS_` 开头的系统调用表 (从NR做了名称转换) |
