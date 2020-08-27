#include <stdbool.h>

// isRectangleOverlap 判断矩形是否重合
// 逆向思维判断不重合的情况 T(n) = O(1)
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (rec2[3] <= rec1[1] || rec2[0] >= rec1[2] || rec2[1] >= rec1[3] || rec2[2] <= rec1[0]) return false;
    return true;
}