#include <stdio.h>
#include "./Singleton.h"

int main() {
  Singleton* sing = Singleton::Instance();
  printf("%s", sing->data());
  return 0;
}