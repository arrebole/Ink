
interface IPrototype {
    clone(): IPrototype
    getDate(): Date
}


export class ConcretePrototype implements IPrototype {
    constructor() {
        this.date = new Date();
    };

    private date: Date;

    public getDate(): Date {
        return this.date;
    };

    public clone(): IPrototype {
        let that: IPrototype = JSON.parse(JSON.stringify(this));
        that.getDate = this.getDate;
        return that;
    };
}

// 原型管理器
export class PrototypeManager {
    private prototypes: Map<string, IPrototype>;
    constructor() {
        this.prototypes = new Map();
    }

    // 获取原型
    public retrieve(key: string): IPrototype {
        if (!this.isHas(key)) {
            return null;
        }
        return this.prototypes.get(key);
    }

    // 是否拥有
    public isHas(key: string): boolean {
        return this.prototypes.has(key);
    }

    // 注册原型
    public register(key: string, val: IPrototype): boolean {
        if (this.isHas(key)) {
            return false;
        }
        this.prototypes.set(key, val);
        return true;
    }

    // 卸载原型
    public Unregister(key: string): boolean {
        if (!this.isHas(key)) {
            return false;
        }
        this.prototypes.delete(key);
        return true;
    }
}
