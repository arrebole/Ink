#include <stdio.h>
#include "largestRectangleArea.c"

int main(){
    int data[] = {2,1,5,6,2,3};
    printf("%d", largestRectangleArea((int*)&data, 6));
    return 0;
}