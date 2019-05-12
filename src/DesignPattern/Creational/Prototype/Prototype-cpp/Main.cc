#include <stdio.h>
#include "./Prototype.h"

int main() {
  IImage* img = new ConcreteImage(17);
  IImage* imgClone = img->Clone();

  printf("%d\n", img->getData());
  printf("%d\n", imgClone->getData());
  return 0;
}