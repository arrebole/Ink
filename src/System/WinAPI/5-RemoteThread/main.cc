#include <stdio.h>
#include <Windows.h>

void ThreadProc()
{
    for (int i = 0; i < 5; i++)
    {
        printf("call()...\n");
    }
    return;
}
int main()
{
    printf("this ProcessId: %d\n", GetCurrentProcessId());
    printf("func address: %d\n", &ThreadProc);
    getchar();
    return 0;
}