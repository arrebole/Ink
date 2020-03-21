# Design Patterns

## Introduction

> 口号： **隔离变化，高内聚，低耦合**
>
> 目的：为了**重用代码**、让代码更容易被他人理解、保证代码可靠性


## Table of Content
+ Creational
  + [Factory Method](./GoF/Creational.md/#FactoryMethod)
  + [Abstract Factory](./GoF/Creational.md/#AbstractFactory)
  + [Builder](./GoF/Creational.md/#Builder)
  + [Prototype](./GoF/Creational.md/#Prototype)
  + [Singleton](./GoF/Creational.md/#Singleton)
+ Structural
  + [Adapter](./GoF/Structural.md/#Adapter)
  + [Bridge](./GoF/Structural.md/#Bridge)
  + [Composite](./GoF/Structural.md/#Composite)
  + [Decorator](./GoF/Structural.md/#Decorator)
  + [Facade](./GoF/Structural.md/#Facade)
  + [Flyweight](./GoF/Structural.md/#Flyweight)
  + [Proxy](./GoF/Structural.md/#Proxy)
+ Behavioral
  + [Chain Of Responsibil Ity](./GoF/Behavioral.md/#ChainOfResponsibilIty)
  + [Command](./GoF/Behavioral.md/#Command)
  + [Interpreter](./GoF/Behavioral.md/#Interpreter)
  + [Iterator](./GoF/Behavioral.md/#Iterator)
  + [Mediator](./GoF/Behavioral.md/#Mediator)
  + [Memento](./GoF/Behavioral.md/#Memento)
  + [Observer](./GoF/Behavioral.md/#Observer)
  + [State](./GoF/Behavioral.md/#State)
  + [Strategy](./GoF/Behavioral.md/#Strategy)
  + [Template Method](./GoF/Behavioral.md/#TemplateMethod)
  + [Visitor](./GoF/Behavioral.md/#Visitor)
+ Extra
  + ORM design
    + active record
    + data mapper

## 设计风格原则

### OOP原则
> 封装、继承、多态

**①依赖倒置原则**（DIP）
- 高度模块（稳定）不应该依赖于低层模块（变化），二者都应该依赖于抽象（稳定）
- 抽象（稳定）不应该依赖于实现细节（变化），实现细节应该依赖于抽象（稳定）

**②开放封闭原则**（OCP）
- 对扩展开发，对更改关闭
- 类模块应该是可扩展的，但是不可修改。

**③单一职责原则**（SRP）
- 一个类应该仅有一个引起它变化的原因
- 变化的方向隐含着类的职责 

**④Liskov 替换原则**（LSP）
- 子类必须能够替换它们的基类（IS-A）
- 继承表达类型抽象

**⑤接口隔离原则**（ISP）
- 不应该强迫客户程序依赖它们不用的方法
- 接口应该小而完善

**⑥优先使用对象组合，而不是类继承**
- 继承在某种程度上破环了封装性，子类父类耦合度高
- 对象组合则只要求被组合的对象具有良好的接口，耦合度低

**⑦封装变化点**
- 使用封装来创建对象之间的分界线，让设计者可以在分界层的一侧进行修改，而对另一侧产生不良影响，

**⑧针对接口编程，而不是针对实现编程**
- 不降变量类声明为某个特定的具体类，而是声明为某个接口
- 客户程序无需获得知对象的类型，只需要知道对象所具有的接口
- 减少系统中各部分的依赖关系  

### FP原则
> 尽量写成一系列嵌套的函数调用， 关心数据的映射.

**①不可变数据**
- 默认上变量是不可变的，如果你要改变变量，你需要把变量copy出去修改。

**①使用纯函数**
- 函数要保持独立，所有功能就是返回一个新的值，没有其他行为，尤其是不得修改外部变量的值。