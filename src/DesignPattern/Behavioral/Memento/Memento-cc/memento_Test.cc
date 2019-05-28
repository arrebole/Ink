#include "./memento.h"

int main(){
    Originator originator;
    auto m = originator.CreateMemento();

    originator.setMemento(m);

    delete m;

    return 0;
}