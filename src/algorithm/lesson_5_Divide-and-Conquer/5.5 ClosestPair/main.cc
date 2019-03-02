#include "closestPair.h"

int main() {
  int n = 20;

  CloestPair* cp = new CloestPair();
  Point a[] = {{1, 3}, {2, 7}, {1, 8}, {6, 0}};
  double dis = cp->solveCloestPair(a, 4);
  delete cp;
  printf("min dist: %lf\n", dis);
  return 0;
}
