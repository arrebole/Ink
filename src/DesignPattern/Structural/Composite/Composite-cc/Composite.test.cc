#include "./Composite.h"

void TestComposite() {
  Component* leaf1 = new Leaf(6);
  Component* leaf2 = new Leaf(7);
  Component* leaf3 = new Leaf(8);
  Component* composite1 = new Composite(100);
  Component* root = new Composite(0);
  root->Add(leaf1);
  root->Add(leaf2);
  composite1->Add(leaf3);
  root->Add(composite1);
  // 测试
  root->PrintData();
  delete leaf1;
  delete leaf2;
  delete leaf3;
  delete composite1;
  delete root;
}

int main() { 
    TestComposite();
    return 0; 
}