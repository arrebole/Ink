#include "stack.hpp"
 
using namespace std;

int main(int argc, char const *argv[])
{
    stack s(10);
    for(int i=0;i<10;i++)
    {
        s.push(i);
    }
    for(int i = 0;i<10;i++)
    {
        cout << s.pop() <<endl;
    }
    return 0;
}
