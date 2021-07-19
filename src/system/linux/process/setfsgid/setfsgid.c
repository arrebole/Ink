#define _GNU_SOURCE
#include <stdio.h>
#include <sys/syscall.h>
#include <unistd.h>

// 设置用于文件系统检查的用户组身份
// 文件系统用户 ID 是 用于访问文件系统对象时的权限检查，
// 实际上，
//       每当更改有效用户 ID 时，文件系统用户 ID 也将更改为
//       有效用户 ID 的新值。
int setfsgid(unsigned int fsuid) {
    return syscall(SYS_setfsgid, fsuid);
}

int main() {
    setfsgid(200);
    return 0;
}