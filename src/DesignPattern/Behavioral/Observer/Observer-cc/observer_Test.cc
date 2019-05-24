#include "./observer.h"

class Test {
 private:
  Subject* subject;
  int data;

 public:
  Test() {
    this->subject = new Subject();
    this->subject->Attact(new Monitor());
  }
  void setData(int a) {
    this->data = a;
    subject->Notify();
  }
};

int main() {
  Test* t = new Test();
  t->setData(12);
  return 0;
}