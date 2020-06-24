#include "sortColors.c"
#include <stdio.h>

int main(){
    int a[] = {1,2,1,1,0,0,2,1,2,0,1,1,2,0,0,1,2};
    sortColors((int *)&a, 17);
    for(int i = 0; i < 17; i++) printf("%d ",a[i]);
    return 0;
}