#include "widget/Widget.h"

int main() {
  Client *c = new Client(new LinuxFactory());
  c->draw();
  
  delete c;
  return 0;
}