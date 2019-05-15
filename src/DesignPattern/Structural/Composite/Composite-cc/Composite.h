#include <stdio.h>
#include <vector>
//接口
class Component {
 public:
  int data;
  virtual void Add(Component*) = 0;
  virtual void PrintData() = 0;
  virtual ~Component(){};
};

// 组件
class Composite : public Component {
 private:
  std::vector<Component*> components;

 public:
  Composite(int n) { this->data = n; }
  virtual void Add(Component* component) { components.push_back(component); };

  virtual void PrintData() {
    printf("Composite %d\n", data);
    // 关键 利用递归技巧 操作
    auto it = components.begin();
    for (; it != components.end(); ++it) {
      (*it)->PrintData();
    }
  };
  virtual ~Composite() {};
};

// 叶子节点
class Leaf : public Component {
 public:
  Leaf(int n) { this->data = n; }
  // 叶子节点禁止添加子节点
  virtual void Add(Component* _) {};
  virtual void PrintData() { printf("Leaf %d\n", this->data); };
  virtual ~Leaf(){};
};