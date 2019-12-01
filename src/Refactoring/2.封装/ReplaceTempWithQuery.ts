// 重构：以查询取代临时变量

namespace BadSmell {
    class Order {
        constructor(quantity: number, item: { price: number }) {
            this.quantity = quantity;
            this.item = item;
        }
        private quantity: number
        private item: { price: number }

        get price() {
            let basePrice = this.quantity * this.item.price;
            let discountFactory = 0.98;
            if (basePrice > 1000) discountFactory -= 0.03;
            return basePrice * discountFactory;
        }
    }
}

namespace GoodSmell {
    class Order {
        constructor(quantity: number, item: { price: number }) {
            this.quantity = quantity;
            this.item = item;
        }
        private quantity: number
        private item: { price: number }

        get basePrice() {
            return this.quantity * this.item.price;
        }

        get discountFactory() {
            return (this.basePrice > 1000) ? 0.98 - 0.03 : 0.98;

        }
        get price() {
            return this.basePrice * this.discountFactory;
        }
    }
}