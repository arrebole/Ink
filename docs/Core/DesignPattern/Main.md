# 设计模式

> 口号： **高内聚，低耦合**



遵循原则：

Single Responsibility Principle    	单一职责原则

Liskov Substitution Principle             里氏代换原则

Dependence Inversion Principle 	 依赖倒转原则

Interface Segregation Principle 	  接口隔离原则

Demeter Principle 				    迪米特法则，又称最少知道原则

Open Close Principle 			     开闭原则



## Directory

### Creational

+ [Simple Factory 简单工厂](#@SimpleFactory)

+ [Abstract Factory 抽象工厂](#@AbstractFactory)
+ [Builder 生成器]()
+ [Factory Method 工厂方法]()
+ [Prototype 原型]()
+ [Singleton 单件]()

### Structural

+ [Adapter 适配器]()
+ [Bridge 桥接]()
+ [Composite 组成]()
+ [Decorator 装饰]()
+ [Facade 外观]()
+ [Flyweight 享元]()
+ [Proxy 代理]() 

### Behavioral

+ [Chain Of Responsibil Ity 责任链]()
+ [Command 命令]()
+ [Interpreter 解释器]()
+ [Iterator 迭代器]()
+ [Mediator 中介者]()
+ [Memento 备忘录]()
+ [Observer 观察者]()
+ [State 状态]()
+ [Strategy 策略]()
+ [Template Method 模板方法]()
+ [Visitor 访问者]()



## Creational

> 定义： 创建型模式**抽象了实例化过程**，帮助系统独立于如何创建对象、组合和表示那些对象。
>
> 特征： 1）它们将关于该系统使用那些**具体的类的信息封装起来**
>
> ​		2）它们**隐藏了这些类的实例是如何被创建和放在一起的**。	



### @SimpleFactory

#### 1）模式定义

简单工厂模式(Simple Factory Pattern)：又称为静态工厂方法(Static Factory Method)模式，它属于类创建型模式。

**在简单工厂模式中，可以根据参数的不同返回不同类的实例。**

简单工厂模式专门定义一个类来负责创建其他类的实例，被创建的实例通常都具有共同的父类。



#### 2）模式结构

- `Factory`：工厂角色负责实现创建所有实例的内部逻辑

- `Product`：抽象产品角色是所创建的所有对象的父类，负责描述所有实例所共有的公共接口

- `ConcreteProduct`：具体产品角色是创建目标，所有创建的对象都充当这个角色的某个具体类的实例。

    

![](../../assets/img/DesignPattern.Creational.SimpleFactory.png)



#### 3）[代码实现](/src/DesignPattern/Creational/SimpleFactory)

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
// 模式：简单工厂模式
// 算法：——
// 复杂度：——
class SimpleFactory {
 public:
  enum types {
    apple,
    ibm,
  };

  static Computer* createComputer(types t) {
    switch (t) {
      case types::apple:
        return new AppleComputer();
        break;

      case types::ibm:
        return new IBMComputer();
        break;
    }
  }
};
```

测试

```c++
int main() {
  Computer* p1 = SimpleFactory::createComputer(SimpleFactory::types::apple);
  Computer* p2 = SimpleFactory::createComputer(SimpleFactory::types::ibm);
  p1->use();
  p2->use();
  return 0;
}
```



[查看更多](/src/DesignPattern/Creational/SimpleFactory)



### @AbstractFactory

#### 1）模式定义

#### 2）模式结构

#### 3）代码实现

