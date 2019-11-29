#include "spiralOrder.c"
#include <stdio.h>

int main(){
    int m1[] = {1, 2, 3, 4};
    int m2[] = {5, 6, 7, 8};
    int m3[] = {9, 10, 11, 12};
    int* data[] = {m1, m2, m3};
    int size = 4;
    int returnvalue = 0; 
    
    int* r = spiralOrder(data, 3, &size, &returnvalue);
    for(int i = 0; i < returnvalue; i++) printf("%d ", r[i]);
    
    return 0;
}