#include <stdio.h>
#include "./flyweight.h"

int main(){
    auto f = new FlyweightFactory();
    auto item1 = f->GetFlyweight('a');
    auto item2 = f->GetFlyweight('a');
    auto item3 = f->GetFlyweight('b');
    printf("%d %p\n",item1->getValue(),item1);
    printf("%d %p\n",item2->getValue(),item2);
    printf("%d %p\n",item3->getValue(),item3);

    f->Clear();
    delete f;
}