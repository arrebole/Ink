

#define X byLoadLibrary
/*------------------------------

    动态链接库两种加载方式
        1、通过编译器绑定到pe头，程序运行系统自动加载
        2、通过手动调用系统api，加载


-------------------------------*/


#include <stdio.h>
#include <Windows.h>
#ifndef X
#include "lib/Library.h"
#endif

typedef int (*FUNC)(int, int);

int main()
{

#ifndef X
    printf("%d", add(1, 3));
#else

    HINSTANCE hModule = LoadLibrary(TEXT("./lib/lib.dll"));
    FUNC ProcAdd = (FUNC)GetProcAddress(hModule, "add");
    printf("%d", ProcAdd(1, 2));
    FreeLibrary(hModule);

#endif
    return 0;
}