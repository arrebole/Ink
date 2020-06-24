// 重构：引入断言
namespace BadSmell {
    class Customer {
        private _discountRate: number
        set discountRate(aNumber: number) {
            this._discountRate = aNumber
        }
        applyDiscount(aNumber: number) {
            return (this._discountRate)
                ? aNumber - (this._discountRate * aNumber)
                : aNumber
        }
    }
}
namespace GoodSmell {
    class Customer {
        private _discountRate: number
        set discountRate(aNumber: number) {
            console.assert(aNumber == null || aNumber >= 0, "assert fail")
            this._discountRate = aNumber
        }
        applyDiscount(aNumber: number) {
            console.assert(this._discountRate >= 0, "assert fail")
            return aNumber - (this.discountRate * aNumber)

        }
    }
}