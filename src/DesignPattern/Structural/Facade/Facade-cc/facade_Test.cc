#include "./facade.h"

int main() {
  IFacade* f = new Facade();
  f->TurnOff();
  f->PlayMusic();
  delete f;
  return 0;
}