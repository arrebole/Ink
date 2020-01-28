<h1 style="text-align:center"> Syscall </h1>
> 系统调用的研究 (只考虑最新x64版本)
>
> linux_x64(**与32位不相同**) 参考系统调用源码 [《linux/arch/x86/entry/syscalls/syscall_64.tbl》](https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl)
>
> win10_x64 参考第三方文档[《hfiref0x/SyscallTables》](https://github.com/hfiref0x/SyscallTables)

## table of contents
| 调用号 | 函数名 | 入口点         | 源代码                                                       | 版本/平台   | 研究成果                               |
| ------ | :----- | -------------- | ------------------------------------------------------------ | :---------- | :------------------------------------- |
| 0      | read   | __x64_sys_read | [fs/read_write.c](https://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/tree/fs/read_write.c) | all, x86_64 | [pass](./Ink/src/System/Syscall/Linux) |
|        |        |                |                                                              |             |                                        |
|        |        |                |                                                              |             |                                        |

