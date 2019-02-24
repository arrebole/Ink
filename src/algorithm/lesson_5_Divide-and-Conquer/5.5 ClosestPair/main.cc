#include <vector>
#include "closestPair.h"

using namespace std;

int main() {
  // 求最近点的距离
  vector<point> P = {{1,3},{1,9},{1.5,5},{2,7},{5,7},{5.5,9},{6,6},{8,1}};
  vector<point> Q = {{8,1},{1,3},{1.5,5},{6,6},{2.7},{5,7},{1,9},{5.5,9}};
  
  double closestDistance = efficientClosestPair(P, Q);

  printf("this closestdistance is: %lf", closestDistance);
  return 0;
}