// 重构：将引用对象改为值对象

class Price{
    constructor(amount:number){
        this.amount = amount
    }
    amount:number
}

namespace BadSmell{
    class Product{
        _price:Price
        applyDiscount(arg:number){
            this._price.amount -= arg;
        }
    }
}
namespace GoodSmell{
    class Product{
        _price:Price
        applyDiscount(arg:number){
            this._price = new Price(this._price.amount - arg)
        }
    }
}