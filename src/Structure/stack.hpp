#include <iostream>

class stack
{
private:
  /* data */
  int *data;
  int top;
  int maxSize;

public:
  stack(int n)
  {
    maxSize = n;
    top = 0;
    data = new int[n];
  }
  ~stack()
  {
    delete[] data;
    data = NULL;
  }
  bool push(int n)
  {
    if (top > maxSize)
    {
      return false;
    }
    data[top] = n;
    top++;
    return true;
  }
  int pop()
  {
    if (top == 0)
    {
      return data[0];
    }
    top--;
    return data[top];
  }
};
