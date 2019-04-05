#include <stdio.h>

// 抽象的产品(Product)接口
class Computer {
 public:
  virtual void use() = 0;
};

// 具体的产品(ConcreteProduct)
class AppleComputer : public Computer {
  virtual void use() { printf("use AppleComputer\n"); }
};

class IBMComputer : public Computer {
  virtual void use() { printf("use IBMComputer\n"); }
};

enum ComputerTypes {
  apple,
  ibm,
};

// 模式：简单工厂模式
// 算法：——
// 复杂度：——
class SimpleFactory {
 public:
  static Computer* createComputer(ComputerTypes t) {
    switch (t) {
      case ComputerTypes::apple:
        return new AppleComputer();
        break;

      case ComputerTypes::ibm:
        return new IBMComputer();
        break;
    }
  }
};

int main() {
  Computer* p1 = SimpleFactory::createComputer(ComputerTypes::apple);
  Computer* p2 = SimpleFactory::createComputer(ComputerTypes::ibm);
  p1->use();
  p2->use();
  return 0;
}