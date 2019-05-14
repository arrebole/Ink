// 目标接口
export interface ITarget {
    getYear(): string
}

// 需要转换的接口
export interface IAdaptee {
    getTime(): Date
};

// 适配器
export class Adapter implements ITarget {
    private pIAdaptee: IAdaptee;
    constructor(adaptee: Adaptee) {
        this.pIAdaptee = adaptee;
    }
    public getYear(): string {
        let year = this.pIAdaptee.getTime().getFullYear().toString();
        return year;
    }
}


// 需要转化接口的具体类
export class Adaptee implements IAdaptee {
    public getTime(): Date {
        return new Date();
    }
}

