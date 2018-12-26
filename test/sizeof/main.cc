#include <stdio.h>
#include <Windows.h>

int glob = -1;

int main()
{
    MessageBoxA(0, 0, 0, 0);
    printf("%p\n %d\n", &glob, glob);
    return 0;
}