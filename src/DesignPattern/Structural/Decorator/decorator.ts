interface Component {
    Count(): number
};

// 具体的执行对象
class ConcreteComponent implements Component {
    Count(): number {
        console.log("std 10")
        return 10;
    }
};

// 装饰器类
abstract class Decoretor implements Component {
    private component: Component
    constructor(component: Component) {
        this.component = component
    }
    Count(): number {
        return this.component.Count();
    }
};

// 具体的类
class ConcreteDecoratorA extends Decoretor {
    Count(): number {
        console.log("add price 5")
        return 5 + super.Count();
    };
};

// 具体的类
class ConcreteDecoratorB extends Decoretor {
    Count(): number {
        console.log("add price 8")
        return 8 + super.Count();
    };
};


function main(){
    const s1 = new ConcreteComponent();
    // 使用上层层包裹
    const dec1 = new ConcreteDecoratorA(s1);
    const dec2 = new ConcreteDecoratorB(dec1);
  
    console.log("final", dec2.Count())
}