
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

// 生产的类型
enum ComputerTypes {
  apple,
  ibm,
};

// 模式：简单工厂模式
// 算法：——
// 复杂度：——
class ComputerFactory {
 public:
  static Computer* createComputer(ComputerTypes T) {
    Computer* computer = nullptr;
    switch (T) {
      case ComputerTypes::apple:
        computer = new AppleComputer();
        break;

      case ComputerTypes::ibm:
        computer = new IBMComputer();
        break;
    }
    return computer;
  }
};
