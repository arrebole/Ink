# Design Patterns

> 口号： **高内聚，低耦合**
>
> 目的：为了**重用代码**、让代码更容易被他人理解、保证代码可靠性





## Creational

+ [Simple Factory ](#SimpleFactory)
+ [Abstract Factory](#AbstractFactory)
+ [Builder]()
+ [Factory Method]()
+ [Prototype]()
+ [Singleton]()



## Behavioral

+ [Bridge]()
+ [Composite]()
+ [Decorator]()
+ [Facade]()
+ [Flyweight]()
+ [Proxy]() 



## Structural

+ [Chain Of Responsibil Ity]()
+ [Command]()
+ [Interpreter]()
+ [Iterator]()
+ [Mediator]()
+ [Memento]()
+ [Observer]()
+ [State]()
+ [Strategy]()
+ [Template Method]()
+ [Visitor]()







# Creational design patterns

> 定义： 创建型模式**抽象了实例化过程**，帮助系统独立于如何创建对象、组合和表示那些对象。
>
> 特征： 1）它们将关于该系统使用那些**具体的类的信息封装起来**
>
> ​		2）它们**隐藏了这些类的实例是如何被创建和放在一起的**。	



## SimpleFactory

### 1）模式意图

+ **在简单工厂模式中，可以根据参数的不同返回不同类的实例。**



### 2）模式适用

+ 创建统一接口的对象



### 2） 模式效果

+ 简单工厂模式又称为静态工厂方法(Static Factory Method)模式，它属于类创建型模式。

+ 简单工厂模式专门定义一个类来负责创建其他类的实例，被创建的实例通常都具有共同的父类。



### 3）模式结构

- `Factory`：工厂角色负责实现创建所有实例的内部逻辑

- `Product`：抽象产品角色是所创建的所有对象的父类，负责描述所有实例所共有的公共接口

- `ConcreteProduct`：具体产品角色是创建目标，所有创建的对象都充当这个角色的某个具体类的实例。

  

    

![](../../assets/img/DesignPattern.Creational.SimpleFactory.png)



### 4）[代码实现](/src/DesignPattern/Creational/SimpleFactory)

```c++
// 抽象的产品(Product)接口
class Computer {
 public:
  virtual void use() = 0;
};
```



```c++
// 具体的产品(ConcreteProduct)
class AppleComputer : public Computer {
  virtual void use() { printf("use AppleComputer\n"); }
};

class IBMComputer : public Computer {
  virtual void use() { printf("use IBMComputer\n"); }
};
```



```c++
// 生产的类型
enum ComputerTypes {
  apple,
  ibm,
};

// 模式：SimpleFactory;
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
```

测试

```c++
// Computer.test.cc
int main() {
  Computer* appleComputer = ComputerFactory::createComputer(ComputerTypes::apple);
  Computer* ibmComputer = ComputerFactory::createComputer(ComputerTypes::ibm);
  
  appleComputer->use();
  ibmComputer->use();
  
  return 0;
}
```



[查看更多](/src/DesignPattern/Creational/SimpleFactory)







## AbstractFactory

### 1）模式意图

+ 提供一个创建一系列相关或互相依赖对象的接口，而无需指定它们的具体的类



### 2）模式适用

+ **一个系统要由多个产品系列中的一个来配置时**
+ 一个系统要独立于它的产品的创建、组合和表示时
+ 当你要强调**一系列相关的产品对象**的设计以便进行**联合**适用时
+ 当你提供一个产品类库，而只想显示它们的接口而不是实现时



### 3）模式效果

+ 它分离了具体的类
+ 它使得易于交换产品系列
+ 它有利于产品的一致性
+ 难以支持新种类的产品



### 4）模式结构

+ `AbstractFactory` 创建抽象产品的操作接口
+ `ConcreteFactory` 实现具体产品对象的操作
+ `AbstractProduct` 一类产品对象的接口
+ `ConcreteProduct` 定义一个将被相应的具体工厂创建的产品对象
+ `Client` 仅使用`AbstractFactory`和`AbstractProduct`类声明的接口



![](../../assets/img/DesignPattern.Creational.AbstractFactory.png)





### 5）[代码实现]((/src/DesignPattern/Creational/AbstractFactory))

```c++
// 按钮接口
class Button {
 public:
  virtual void drawButton() = 0;
  virtual ~Button(){};
};

// 菜单接口
class Menu {
 public:
  virtual void drawMenu() = 0;
  virtual ~Menu(){};
};
```



```c++
// 具体的产品系列 linux
class LinuxButton : public Button {
 public:
  virtual void drawButton() { printf("LinuxButton\n"); }
};

class LinuxMenu : public Menu {
 public:
  virtual void drawMenu() { printf("LinuxMenu"); }
};

// 具体的产品系列 windows
class WindowsButton : public Button {
 public:
  virtual void drawButton() { printf("WindowsButton\n"); }
};

class WindowsMenu : public Menu {
 public:
  virtual void drawMenu() { printf("WindowsMenu"); }
};
```



```c++
// 工厂接口
class Factory {
 public:
  virtual Button *createButton() = 0;
  virtual Menu *createMenu() = 0;
  virtual ~Factory(){};
};

// 具体的工厂1
class LinuxFactory : public Factory {
 public:
  Button *createButton() { return new LinuxButton(); }
  Menu *createMenu() { return new LinuxMenu(); }
};

// 具体的工厂2
class WindowsFactory : public Factory {
 public:
  Button *createButton() { return new WindowsButton(); }
  Menu *createMenu() { return new WindowsMenu(); }
};
```



```c++
// 设计模式：抽象工厂
// 算法：——
// 复杂度：——
class Client {
 private:
  Factory *factory = nullptr;
  Button *button = nullptr;
  Menu *menu = nullptr;

 public:
  Client(Factory *f) {
    factory = f;
    button = factory->createButton();
    menu = factory->createMenu();
  }

  void draw() {
    button->drawButton();
    menu->drawMenu();
  }

  ~Client() {
    if (factory != nullptr) delete factory;
    if (button != nullptr) delete button;
    if (menu != nullptr) delete menu;
  }
};
```

测试

```c++
int main() {
  Client *c = new Client(new LinuxFactory());
  c->draw();
  
  delete c;
  return 0;
}
```



#### [更多代码]((/src/DesignPattern/Creational/AbstractFactory))