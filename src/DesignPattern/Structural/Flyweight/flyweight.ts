// 享元抽象类
abstract class Flyweight {
    protected value: string
    public abstract getValue(): string
};

// 享元具体类
class ConcreteFlyweight extends Flyweight {
    constructor(v: string) {
        super()
        this.value = v;
    }
    public getValue(): string {
        return this.value;
    }
};

// 享元工厂
class FlyweightFactory {
    private cache: Map<string, Flyweight>

    public GetFlyweight(sign: string): Flyweight {
        if (!this.cache.has(sign)) {
            this.cache.set(sign, new ConcreteFlyweight(sign));
        }
        return this.cache.get(sign);
    }
    public Clear() {
        this.cache.clear();
    }
};

function sample() {
    const f = new FlyweightFactory();
    const item1 = f.GetFlyweight('a');
    const item2 = f.GetFlyweight('a');
    const item3 = f.GetFlyweight('b');
    console.log("%d %p", item1.getValue(), item1);
    console.log("%d %p", item2.getValue(), item2);
    console.log("%d %p", item3.getValue(), item3);
    f.Clear();
}