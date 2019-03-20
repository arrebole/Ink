#include <stdio.h>

class MinStack {
 private:
  int* data;
  int capacity;
  int size;
  int topPointer;

  bool isEmpty() {
    if (size > 0) {
      return false;
    }
    return true;
  }

  bool isFull() {
    if (size >= capacity) {
      return true;
    }
    return false;
  }

  void expansion() {
    int newCapacity = (capacity + 1) * 2;
    int* newArray = new int[newCapacity]();
    for (int i = 0; i < size; i++) {
      newArray[i] = data[i];
    }
    if (data != nullptr) delete[] data;
    data = newArray;
    capacity = newCapacity;
  }

 public:
  /** initialize your data structure here. */
  MinStack() {
    data = nullptr;
    capacity = 0;
    size = 0;
    topPointer = -1;
  }
  ~MinStack() { delete[] data; }

  void push(int x) {
    if (isFull()) {
      expansion();
    }
    size++;
    data[++topPointer] = x;
  }

  bool pop() {
    if (!isEmpty()) {
      size--;
      topPointer--;
      return true;
    }
    return false;
  }

  int top() {
    if (isEmpty()) return 0;
    return data[topPointer];
  }

  int getMin() {
    if (isEmpty()) return 0;
    int min = data[0];
    for (int i = 1; i < size; i++) {
      if (data[i] < min) {
        min = data[i];
      }
    }
    return min;
  }
};

int main() {
  MinStack* obj = new MinStack();
  obj->push(-2);
  obj->push(0);
  obj->push(-3);

  int param_4 = obj->getMin();
  printf("%d", param_4);
  obj->pop();
  int param_3 = obj->top();
  printf("%d", param_3);
  int param_5 = obj->getMin();
  printf("%d", param_5);
  return 0;
}