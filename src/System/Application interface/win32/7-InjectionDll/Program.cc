#include <windows.h>
#include <stdio.h>

int main()
{
    DWORD pid = GetCurrentProcessId();
    printf("Program pid: %d\n", pid);

    getchar();
    return 0;
}