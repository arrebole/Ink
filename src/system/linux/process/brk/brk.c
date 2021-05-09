#define _GNU_SOURCE
#include <stdio.h>
#include <syscall.h>
#define PAGE_SIZE 4096

extern long int syscall (long int __sysno, ...) __THROW;

void * brk(void *addr){
    return (void *) syscall(SYS_brk, addr);
}

int main(int argc, const char* arhv[]){
    char* heapTop;
    char* initHeapTop;

    // 获取当前进程堆的最大的地址
    initHeapTop = brk(NULL);
    heapTop = initHeapTop;
    printf("heap top = %p\n", heapTop);

    // 向操作系统申请堆内存
    heapTop = brk(heapTop + PAGE_SIZE);
    printf("heap top = %p(+brk)\n", heapTop);

    // 将堆内存还给操作系统
    // fix: 调用brk后出现x86_64 printf段错误, 不能将内存全部归还
    heapTop = brk(initHeapTop+1);
    printf("heap top = %p(-brk)\n", heapTop);

    return 0;
}