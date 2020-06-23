#include <stdlib.h>

struct Stack{
    int* data;
    int size;
    int capacity; 
};

// 创建栈
struct Stack make(int size){
    struct Stack result = {(int*)malloc(sizeof(int) * (size+1)), 0, size + 1};
    return result;
}

// 查看栈顶元素
int peek(struct Stack* stack){
    if(stack->size == 0) return -1;
    return stack->data[stack->size - 1];
}

// 元素入栈
void push(struct Stack* stack, int data){
    stack->data[stack->size++] = data;
}

// 弹出栈顶元素
int pop(struct Stack* stack){
    if(stack->size == 0) return -1;
    return stack->data[--stack->size];
}

// 计算矩形面积
int area(struct Stack* stack, int* heights,int i){
    // 高(最低高) * 长
    return heights[pop(stack)] * (i - peek(stack) - 1);
}

int Max(int a, int b){
    return a > b? a: b;
}

int largestRectangleArea(int* heights, int heightsSize){
    struct Stack stack = make(heightsSize);
    int result = 0;
    for(int i = 0; i < heightsSize; i++){
        // 递增结束则求面积
        // 每次以最高点出发，向低位置扩张求面积,并取最大面积
        // {2，5，6} => {6} {5, 6} {2, 5, 6}
        while (peek(&stack) != -1 && heights[peek(&stack)] > heights[i]){
            result = Max(result, area(&stack, heights, i));
        }
        push(&stack, i);
    }
    // 最右侧递增区间
    while(peek(&stack) != -1){
        result = Max(result, area(&stack, heights, heightsSize));
    }

    return result;
}