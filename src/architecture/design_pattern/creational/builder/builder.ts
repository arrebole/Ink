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