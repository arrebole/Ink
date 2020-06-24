// 重构：以查询取代派生变量

namespace BadSmell{
    class Production{
        private _discountedTotal:number
        private _discount:number
        get discountedTotal(){
            return this._discountedTotal;
        }
        set discountedTotal(aNumber:number){
            const old = this._discount;
            this._discount = aNumber;
            this._discountedTotal += old - aNumber;
        }
    }
}
namespace GoodSmell{
    class Production{
        private _discount:number
        private _baseTotal:number
        get discountedTotal(){
            return this._baseTotal - this._discount;
        }
        set discountedTotal(aNumber:number){
            this._discount = aNumber;
        }
    }
}