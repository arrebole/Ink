#pragma one

#include <string>
#include <iostream>
using namespace std;

/* "Product" */
class Pizza {
 public:
  string dough = "";
  string sauce = "";
  string topping = "";
};

/* "Abstract Builder" */
class PizzaBuilder {
 protected:
  Pizza* pizza;

 public:
  // 返回对象
  Pizza* getResult() { return pizza; }
  // 创建对象
  void createNewPizzaProduct() { pizza = new Pizza(); }
  virtual void buildDough() = 0;
  virtual void buildSauce() = 0;
  virtual void buildTopping() = 0;
  virtual ~PizzaBuilder(){};
};

/* "ConcreteBuilder" */
class HawaiianPizzaBuilder : public PizzaBuilder {
 public:
  void buildDough() { pizza->dough = "cross"; }

  void buildSauce() { pizza->sauce = "mild"; }

  void buildTopping() { pizza->topping = "ham+pineapple"; }
};

class SpicyPizzaBuilder : public PizzaBuilder {
 public:
  void buildDough() { pizza->dough = "pan baked"; }

  void buildSauce() { pizza->sauce = "hot"; }

  void buildTopping() { pizza->topping = "pepperoni+salami"; }
};

/* "Director" */
class Director {
 private:
  PizzaBuilder* pizzaBuilder;

 public:
  void setPizzaBuilder(PizzaBuilder* pb) { pizzaBuilder = pb; }

  Pizza* getPizza() { return pizzaBuilder->getResult(); }

  void constructPizza() {
    pizzaBuilder->createNewPizzaProduct();
    pizzaBuilder->buildDough();
    pizzaBuilder->buildSauce();
    pizzaBuilder->buildTopping();
  }
};