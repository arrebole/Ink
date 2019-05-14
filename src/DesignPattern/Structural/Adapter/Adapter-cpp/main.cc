#include "./adapter.h"
#include <stdio.h>

int main(){
    // 创建对象
    IAdaptee * adaptee = new Asaptee();
    
    // 利用适配器将对象接口转换为ITarget接口
    ITarget * target = new Adapter(adaptee);

    // 启动Target接口
    printf("%d\n",target->request());

    delete target;
    delete adaptee;
}