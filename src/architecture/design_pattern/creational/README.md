# Creational 

> 定义： 创建型模式**抽象了实例化过程**（绕开new），帮助系统独立于如何创建对象、组合和表示那些对象。
>
> 特征： 1）它们将关于该系统使用那些**具体的类的信息封装起来**
>
> ​			2）它们**隐藏了这些类的实例是如何被创建和放在一起的**。	





## FactoryMethod

### Ⅰ模式意图

+ 定义一个用于创建对象的接口，让子类决定实例化哪一个类，factoryMethod使**一个类的实例化延迟到子类**。



### Ⅱ 模式适用

+ 当一个类不知道它所必须创建的对象的类的时候
+ 当一个类希望有它的子类来指定它所创建的对象的时候
+ 当类将创建对象的职责委托给多个帮助子类中的某一个，并且你希望将哪一个帮助子类是代理者这一信息局部化的时候



### Ⅲ 模式效果

+ Factory Method 模式解决**单个对象**的需求变化，缺点：**要求创建方法参数相同**
+ Factory Method 隔离类对象的使用者和具体类型之间的耦合关系，面对变化的具体类型，紧耦合关系（new）会让程序变脆弱。

+ 仅仅为了创建一个特定的ConcreteProduct对象，就不得不创建Creator的子类

+ 为子类提供挂钩

+ 连接平行的类层次



### Ⅳ 模式结构

+ `Product`：定义工厂方法所创建的对象的接口
+ `ConcreteProduct`： 实现Product的接口
+ `Creator`：工厂方法，返回一个Product类型的对象；可以调用工厂方法创建一个Product对象。
+ `ConcreteCreator`:  重定义工厂方法以返回一个ConcreteProduct实例。



![](../../../images/DesignPattern/DesignPattern.Creational.FactoryMethod.png)

> + Creator依赖于它的子类来定义工厂方法，所以它返回一个适当的ConcreteProduct实例



### Ⅴ 模式实现

+ 两种不同的情况

  + creator类是一个抽象类并且不提供它所声明的工厂方法的实现
  
  + creator是一个具体的类并且为工厂方法提供一个缺省的实现。
+ 参数化工厂方法
+ 特定语言的变化和问题

  + lazy initialization
+ 使用模板以避免创建子类



#### 不使用模式

```typescript
// 直接使用new来创建对象, 会带来紧耦合的关系。
// 😈Exploit：当要改用其他行星类时，就会出现问题。

class Earth {
    rotation() { // ... }
};

function sample() {
    const earth = new Earth();
}
```

#### 使用模式

**interface.ts**

```typescript
// 行星抽象接口
interface IPlanet {
    rotation(): void
}
// 行星工厂方法抽象接口
interface PlanetCreator{
    create(): IPlanet
}
```
**earth.ts**

```typescript
// 具体的产品：地球
class Earth implements IPlanet {
    rotation() { // ...  };
};

class EarthCreator implements PlanetCreator{
    create():IPlanet{
        return new Earth();
    }
}
```

**mars.ts**

```typescript
// 具体的产品：火星
class Mars implements IPlanet {
    rotation() { // ...  };
};

class MarsCreator implements PlanetCreator{
    create():IPlanet{
        return new Mars();
    }
}
```

**smple.ts**

```typescript
// 使得函数内或对象内不依赖具体类
function sample(factory: PlanetCreator) {
    const planet = factory.create();
    planet.rotation()
}
sample(new MarsCreator())
sample(new EarthCreator())
```



[查看更多](/src/DesignPattern/Creational/FactoryMethod)

### Ⅵ 相关模式

+ abstract factory 经常用工厂方法来实现。

+ 工厂方法经常在Template Method中被调用
+ Prototypes不需要创建creator子类，但是通常需要一个针对Product类的Initialize操作
+ Creator使用Initialize来初始化对象，而factory method不需要这样的操作。




## AbstractFactory

### Ⅰ 模式意图

+ 提供一个创建一系列相关或互相依赖对象的接口，而无需指定它们的具体的类



### Ⅱ 模式适用

+ **一个系统要由多个产品系列中的一个来配置时**
+ 一个系统要独立于它的产品的创建、组合和表示时
+ 当你要强调**一系列相关的产品对象**的设计以便进行**联合**适用时
+ 当你提供一个产品类库，而只想显示它们的接口而不是实现时



### Ⅲ 模式效果

+ 它分离了具体的类
+ 它使得易于交换产品系列
+ 它有利于产品的一致性，**保证产品的相关性**
+ **难以支持新种类的产品**



### Ⅳ 模式结构

+ `AbstractFactory`: 创建抽象产品的操作接口
+ `ConcreteFactory`: 实现具体产品对象的操作
+ `AbstractProduct`: 一类产品对象的接口
+ `ConcreteProduct`: 定义一个将被相应的具体工厂创建的产品对象
+ `Client`:  仅使用由**`AbstractFactory`**和**`AbstractProduct`**类声明的接口



![](../../../images/DesignPattern/DesignPattern.Creational.AbstractFactory.png)

> + 通常在运行时刻创建一个ConcreteFactory类的实例。这一具体的工厂创建具有特定实现的产品对象。为创建不同的产品对象，客户应使用不同的具体工厂。
> + AbstractFactory将产品对象的创建延迟到它的ConcreteFactory子类



### Ⅴ 模式实现

+ 1、工厂作为单件

  + 一个应用中一般每个产品系列只需一个ConcreteFactory的实例，因此工厂通常最好实现为一个Singleton

+ 2、创建产品

  +  abstractfactory仅申明一个创建产品的接口，真正创建产品是由ConcreteProduct子类实现的，最通常的一个方法是为每个产品定义一个工厂方法。
  
  +  如果有多个可能的产品系列，具体的工厂也可以使用Prototype模式来实现

+ 定义可扩展的工厂

  +  参数化



#### 不使用模式

```c++

```
#### 使用模式

**interface.ts**

```typescript
interface Button{ }
interface Menu{ }

interface Factory{
    createButton(): Button;
    createMenu(): Menu;
}
```

**linuxFactory.ts**

```c++
class LinuxButton implements Button{}
class LinuxMenu implements Menu{}
class LinuxFactory implements Factory{
    createButton():Button{
        return new LinuxButton();
    }
    createMenu():Menu{
        return new LinuxMenu();
    }
}
```

**winFactory.ts**

```typescript
class WinButton implements Button{}
class WinMenu implements Menu{}
class WinFactory implements Factory{
    createButton():Button{
        return new WinButton();
    }
    createMenu():Menu{
        return new WinMenu();
    }
}
```

**smaple.ts**

```typescript
function sample(factory: Factory){
    const button = factory.createButton()
    const menu = factory.createMenu()
}
sample(new WinFactory())
```



[更多代码](/src/DesignPattern/Creational/AbstractFactory)



### Ⅵ 相关模式

+ `AbstractFactory`类通常常用工厂方法实现，但它们也可以用`Prototype`实现



## Builder

### Ⅰ 模式意图

+ 将一个复杂对象的**构建与它的表示分离**，使得**同样的构建过程可以创建不同的表示**。



### Ⅱ 模式适用

+ 当创建复杂对象的算法应该**独立于该对象的组成部分**以及的装配方式时
+ 当构建过程必须允许被构造的对象有不同的表示时。



### Ⅲ 模式效果

+ 它使你可以改变一个产品的内部表示，需要**改变时只需要一个新的生成器**
+ 它将构造代码和表示代码分离
+ 它是你可对构造过程进行更精细的控制



### Ⅳ 模式结构

+ `Builder`: 为创建一个Product对象的各个部件指定抽象接口

+ `ConcreteBuilder`: 实现Builder的接口以构造和装配该产品的各个部件，提供一个检索产品的接口。

+ `Director`: 构建一个使用Builder接口的对象

+ `Product`: 表示被构造的复杂对象



![](../../../images/DesignPattern/DesignPattern.Creational.Builder.png)

> + 客户创建Director对象，并用它所想要的Builder对象进行配置
> + 一旦产品部件被生成，导向器就会通知生成器
> + 生成器处理导向器的请求，并将部件添加到该产品中
> + 客户从生成器中检索产品



### Ⅴ 模式实现

+ 装配和构造函数

  > 生成器逐步的构造它们的产品。因此builder类接口必须足够普遍，以便为各种类型的具体生成器构造产品。

+ **产品没有抽象类**
+ 在builder中缺省的方法为空。



#### 使用设计模式

```typescript
/* "Product" */
class Pizza {
    dough: string;
    sauce: string;
    topping: string;
};

/* "Abstract Builder" */
abstract class PizzaBuilder {
    protected pizza: Pizza;

    getResult(): Pizza {
        return this.pizza;
    }
    // 创建对象
    createNewPizzaProduct() {
        this.pizza = new Pizza();
    }
    abstract buildDough();
    abstract buildSauce();
    abstract buildTopping();
};
```




```c++
/* "ConcreteBuilder" */
class HawaiianPizzaBuilder extends PizzaBuilder {
    buildDough() {
        super.pizza.dough = "cross";
    }
    buildSauce() {
        super.pizza.sauce = "mild";
    }
    buildTopping() {
        super.pizza.topping = "ham+pineapple";
    }
};

class SpicyPizzaBuilder extends PizzaBuilder {
    buildDough() {
        super.pizza.dough = "pan baked";
    }
    buildSauce() {
        super.pizza.sauce = "hot";
    }
    buildTopping() {
        super.pizza.topping = "pepperoni+salami";
    }
};

/* "Director" */
class Director {
    private pizzaBuilder: PizzaBuilder;

    setPizzaBuilder(pb: PizzaBuilder) {
        this.pizzaBuilder = pb;
    }
    getPizza() {
        return this.pizzaBuilder.getResult();
    }
    constructPizza() {
        this.pizzaBuilder.createNewPizzaProduct();
        this.pizzaBuilder.buildDough();
        this.pizzaBuilder.buildSauce();
        this.pizzaBuilder.buildTopping();
    }
}
```



```c++
function main() {
    // 1、创建Director对象
    const waiter = new Director();

    // 2、创建具体的builder
    const hawaiianPizzabuilder = new HawaiianPizzaBuilder();
    const spicyPizzaBuilder = new SpicyPizzaBuilder();

    // 3、生成pizza对象
    waiter.setPizzaBuilder(hawaiianPizzabuilder);
    waiter.constructPizza();
    const pizza = waiter.getPizza();

    console.log(pizza.dough, pizza.sauce, pizza.topping);
}
```



[更多代码](/src/DesignPattern/Creational/Builder)

### Ⅵ 相关模式

+ 与 `Abstract Factory`目的相同，用于创建复杂对象
+ `Builder`模式着重构造**一个复杂对象**；`Abstract Factory`模式着重于创建**多个系列的产品对象**.
+ `Builder`模式着重于**一步步**构建对象，并在**最后一步返回**；`Abstract Factory`模式里对象是**立即返回**的。



## Prototype

### Ⅰ 模式意图

+ 用原型实例指定创建对象的种类，并且通过拷贝这些原型创建新的对象。



### 2) 模式适用

+ 当要实例化的类是在运行时刻指定时，例如，通过动态加载。
+ 为了**避免创建一个与产品类层次平行的工厂类层**次时。

+ 当一个类的实例只能有几个不同状态组合中的一种时。创建相应数目的原型并克隆它们可能比每次用合适的状态手工实例化该类更方便一些。



### 3) 模式效果

+ 它对客户隐藏了具体的产品类，因此减少了客户知道的名字的数量。
+ 使客户无需改变即可使用与特定应用相关的类
+ 运行时刻增加和删除产品
+ 改变值以指定新对象
+ 改变结构以指定新对象
+ 减少子类的构造
+ 用类动态配置应用



### Ⅳ 模式结构

+ `Prototype`: 声明一个克隆自身的接口
+ `ConcretePrototype`: 实现一个克隆自身的操作
+  `Client`: 让一个原型克隆自身从而创建一个新的对象



![](../../../images/DesignPattern/DesignPattern.Creational.Prototype.png)

> + 客户请求一个原型克隆自身。

### Ⅴ 模式实现

+ 使用一个原型管理器
+ 实现克隆操作
+ 初始化克隆对象



#### 使用设计模式

```typescript
// Prototype 接口
interface Image {
    getData(): number;
    Clone(): Image;
};
```

```typescript
// 具体的原型类
class ConcreteImage implements Image {
    private data: number

    constructor(data: number) {
        this.data = data;
    }
    Clone() {
        return new ConcreteImage(this.data);
    }
    getData(): number {
        return this.data;
    }
};
```

```c++
function main() {
    const img = new ConcreteImage(17);
    const imgClone = img.Clone();

    console.log(img.getData());
    console.log(imgClone.getData());
}
```



[更多代码](/src/DesignPattern/Creational/Prototype)



### 6) 相关模式

+ Prototype和Abstract Factory模式在某种方面是相互竞争
+ Abstract Factoryk可以储存一个被克隆的原型的集合，并且返回产品对象
+ 大量使用Composite和Decorator模式的设计通常也可从Prototype模式处获益。





<br/>

## Singleton

### Ⅰ 模式意图

+ 保证一个类仅有一个实例，并提供一个访问它的全局访问点。



### Ⅱ 模式适用

+ 当类只能有一个实例而且客户可以从一个众所周知的访问点访问它时。
+ 当这个唯一实例应该是通过子类化可扩展的，并且客户应该无需更改代码就能使用一个扩展的实例时。



### Ⅲ 模式效果

+ 对唯一实例的受控访问
+ 缩小命名空间
+ 允许对操作和表示的精化
+ 允许可变数目的实例
+ 比类操作更灵活



### Ⅳ 模式结构

+ `Singleton`: 定义一个Instance操作，允许客户访问它的唯一实例。

  

![](../../../images/DesignPattern/DesignPattern.Creational.Singleton.png)

> + 客户只能通过Singleton的Instance操作访问一个Singleton的实例。

### Ⅴ 模式实现

+ 保证一个唯一的实例

+ 创建Singleton类的子类 

  + 组件注册表



#### 使用设计模式

**懒汉式-线程不安全(c++)**

```typescript
class Singleton {
    private _data: string;
    data(): string {
        return this._data;
    }
    private constructor() {
        this._data = "hello world";
    }
    // 线程不安全的单例模式
    private static uniqueInstance: Singleton;
    static Instance(): Singleton {
        if (Singleton.uniqueInstance == null) {
            Singleton.uniqueInstance = new Singleton();
        }
        return this.uniqueInstance;
    }
};
```

```c++
function main(){
    console.log(Singleton.Instance().data())
}
```

[更多代码](/src/DesignPattern/Creational/Singleton)



### Ⅵ 相关模式

+ 很多模式可以使用Singleton模式实现，Abstract Factory，Builder、Prototype。

