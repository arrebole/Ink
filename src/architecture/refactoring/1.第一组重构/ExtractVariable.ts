// 提炼变量

namespace inFunction {
    class Order {
        quantity: number
        itemPrice: number
    }
    // 待重构
    function price(order: Order): number {
        return order.quantity * order.itemPrice -
            Math.max(0, order.quantity - 500) * order.itemPrice * 0.05 +
            Math.min(order.quantity * order.itemPrice * 0.1, 100);
    }
    // 重构后
    function ref_price(order: Order): number {
        const basePrice = order.quantity * order.itemPrice;
        const quantityDiscount = Math.max(0, order.quantity - 500) * order.itemPrice * 0.05;
        const shipping = Math.min(order.quantity * order.itemPrice * 0.1, 100);
        return basePrice - quantityDiscount + shipping;
    }
}

namespace inClass {
    // 待重构：类内提炼变量
    class Order {
        quantity: number
        itemPrice: number
        price(): number {
            return this.quantity * this.itemPrice -
                Math.max(0, this.quantity - 500) * this.itemPrice * 0.05 +
                Math.min(this.quantity * this.itemPrice * 0.1, 100);
        }
    }
    // 重构后：类内提炼变量
    class Ref_Order {
        quantity: number
        itemPrice: number
        get quantityDiscount(): number {
            return Math.max(0, this.quantity - 500) * this.itemPrice * 0.05;
        }
        get basePrice(): number {
            return this.quantity * this.itemPrice;
        }
        get shipping(): number {
            return Math.min(this.quantity * this.itemPrice * 0.1, 100);
        }
        price(): number {
            return this.basePrice - this.quantityDiscount + this.shipping;
        }
    }
}