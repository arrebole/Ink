// 米饭接口
interface Rice {
    eat(): void;
}

// 汤接口
interface Soup {
    eat(): void;
}

// ---------具体的对象-------------------

// 蛋炒饭
class EggFriedRice implements Rice {
    public eat() {
        console.log("eat EggFriedRice")
    }
}

// 叉烧肉饭
class PorkRoastRice implements Rice {
    public eat() {
        console.log("eat PorkRoastRice")
    }
}

//紫菜汤
class SeaweedSoup implements Soup {
    public eat() {
        console.log("eat SeaweedSoup")
    }
}

//番茄汤
class TomatoSoup implements Soup {
    public eat() {
        console.log("eat TomatoSoup")
    }
}

//-------工厂------------------

// 抽象工厂
interface DinnerFactory {
    createRice(): Rice;
    createSoup(): Soup;
}

// 方案一
class DinnerPlanAFactory implements DinnerFactory {
    public createRice(): Rice {
        return new EggFriedRice();
    }
    public createSoup(): Soup {
        return new TomatoSoup();
    }
}

// 方案二
class DinnerPlanBFactory implements DinnerFactory {
    public createRice(): Rice {
        return new PorkRoastRice();
    }
    public createSoup(): Soup {
        return new SeaweedSoup();
    }
}

// 类型
export enum DinnerTypes{
    PlanA,
    PlanB,
}

//----------client-------------
// 设计模式：创建型—抽象工厂
// 算法：——
// 复杂度：——
export class Client {

    private rice: Rice;
    private soup: Soup;

    public constructor(t: DinnerTypes) {
        let factory:DinnerFactory = null;
        switch(t){
            case DinnerTypes.PlanA:
                factory = new DinnerPlanAFactory();
                break;
            case DinnerTypes.PlanB:
                factory = new DinnerPlanBFactory();
                break;
        }
        this.rice = factory.createRice();
        this.soup = factory.createSoup();
    }
    public eat() {
        this.rice.eat();
        this.soup.eat();
    }
}