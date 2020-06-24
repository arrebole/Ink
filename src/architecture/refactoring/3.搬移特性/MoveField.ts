// 重构：搬移字段

namespace BadSmell{
    class Customer{
        constructor(name:string,discountRate:number){
            this._name = name;
            this._discountRate = discountRate;
            this._contract = new CustomerContract(Date.now().toString())
        }
        private _name:string;
        private _discountRate:number
        private _contract:CustomerContract

    }
    class CustomerContract{
        private _startData:string
        constructor(startData:string){
            this._startData = startData
        }
    }
}

namespace GoodSmell{
    class Customer{
        constructor(name:string,discountRate:number){
            this._name = name;
            this._contract = new CustomerContract(Date.now().toString())
            this._setDiscountRate(discountRate);
        }
        private _name:string;
        private _contract:CustomerContract
        get discountRate(){return this._contract.discountRate}
        _setDiscountRate(arg:number){this._contract.discountRate = arg}

    }
    class CustomerContract{
        private _startData:string
        private _discountRate:number;
        constructor(startData:string){
            this._startData = startData
        }
        set discountRate(arg:number){this._discountRate = arg}
        get discountRate(){return this._discountRate}
    }
}