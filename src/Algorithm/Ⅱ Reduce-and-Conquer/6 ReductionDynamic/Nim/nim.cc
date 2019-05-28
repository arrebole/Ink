#include "nim.h"

// 输入：东西的总数和单次获取的限制数量
// 输出：先手的胜负，true 是胜利
bool nim(int total, int limit)
{
    int flag;
    int remain = total % limit;
    flag = limit ^ remain;

    if (flag == 0)
        return false;
    return true;
}