
// 缓冲区溢出修改EIP
// 将接下来需要执行的函数地址溢出修改为其他函数

#include <stdio.h>

// 需要被注入的函数
void hack()
{
    while(true)
    {
        printf("成功改变函数调用顺序\n");
    }
    return;
}

// call start: push [rip + 8]
// 调用函数跳转代码之前，将下一个需要执行的地址压栈
void start()
{
    // push rbp
    // mov rbp, rsp
    // sub rsp, 40 位函数执行提供缓冲区
    // push rsp 保存寄存器旧值
    
    long long arr[8];
    // 
    arr[9] = (long long)(&hack);
    // mov [rbp - 8],&hack
    return;
}

int main()
{
    start();
    return 0;
}