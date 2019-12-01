// 重构：以查询取代参数

namespace BadSmell {
    class Order {
        quantity: number
        itemPrice: number
        get finalPrice() {
            const basePrice = this.quantity * this.itemPrice;
            let discountLevel;
            if (this.quantity > 100) discountLevel = 2;
            else discountLevel = 1;
            return this.discountedPrice(basePrice, discountLevel)
        }
        discountedPrice(basePrice: number, discountLevel: number) {
            switch (discountLevel) {
                case 1: return basePrice * 0.95;
                case 2: return basePrice * 0.9;
            }
        }
    }
}
namespace GoodSmell {
    class Order {
        quantity: number
        itemPrice: number
        get finalPrice() {
            const basePrice = this.quantity * this.itemPrice;
            return this.discountedPrice(basePrice)
        }
        get discountLevel() {
            return this.quantity > 100 ? 2 : 1;
        }
        discountedPrice(basePrice: number) {
            switch (this.discountLevel) {
                case 1: return basePrice * 0.95;
                case 2: return basePrice * 0.9;
            }
        }

    }
}