// 重构：将值对象改为引用对象

namespace BadSmell{
    class Product{
        _price:Price
        applyDiscount(arg:number){
            this._price = new Price(this._price.amount - arg)
        }
    }
}
namespace GoodSmell{
    class Product{
        _price:Price
        applyDiscount(arg:number){
            this._price.amount -= arg;
        }
    }
}