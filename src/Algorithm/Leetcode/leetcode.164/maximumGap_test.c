#include "maximumGap.c"
#include <assert.h>

int main() {
  int data[] = {3, 6, 9, 1};
  assert(maximumGap((int*)data, 4) == 3);
  return 0;
}