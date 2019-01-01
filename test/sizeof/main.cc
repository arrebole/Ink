#include <stdio.h>

char glob = -1;
int g2 = 12;

int main()
{
    int a = 0;
    
    int *b = new int[1200];
    
    printf("glob: %p\n", &g2);
    printf("b: %p\n", b);
    printf("a: %p\n", &a);
    
    return 0;
}