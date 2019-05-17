export interface Component {
    Count(): number;
}

export class Core implements Component {
    public Count(): number {
        console.log("基础价格 100")
        return 100;
    }
}

// 维持一个指向Component对象的指针，并定义一个与Component接口一致的接口
export class Decorator implements Component {
    protected core: Component;
    constructor(component: Component) {
        this.core = component;
    }
    public Count(): number {
        return this.core.Count();
    }
}

// 具体的包装类
export class Wrapper extends Decorator {
    constructor(component: Component) {
        super(component)
    }
    public Count(): number{
        console.log("加层包装 +50");
        return super.Count() + 50;
    }
}