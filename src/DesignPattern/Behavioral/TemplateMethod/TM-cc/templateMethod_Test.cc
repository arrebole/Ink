#include "./templateMethod.h"

class ConcreteClass : public AbstractClass {
  virtual void step2() { printf("xxxx\n"); }
};

int main() {
  auto t = new ConcreteClass();
  t->TemplateMethod();
  delete t;
  return 0;
}