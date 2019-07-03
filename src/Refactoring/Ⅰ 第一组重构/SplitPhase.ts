

namespace BadSmell {
    function priceOrder(product, quantity, shaippingMethod) {
        const basePrice = product.basePrice * quantity;
        const discount = Math.max(quantity - product.discountThreshold, 0) *
            product.basePrice * product.discountRate;
        const shaippingPerCase = (basePrice > shaippingMethod.discountThreshold) ?
            shaippingMethod.discountFee : shaippingMethod.feePerCase;
        const shaippingCost = quantity * shaippingPerCase;
        const price = basePrice - discount + shaippingCost;
        return price;
    }
}

namespace GoodSmell {
    function priceOrder(product, quantity, shaippingMethod) {
        const priceData = calculatePricingData(product, quantity)
        return applyShipping(priceData, shaippingMethod)
    }

    function calculatePricingData(product, quantity) {
        const basePrice = product.basePrice * quantity;
        const discount = Math.max(quantity - product.discountThreshold, 0) *
            product.basePrice * product.discountRate;
        return { basePrice, quantity, discount }
    }

    function applyShipping(priceData, shaippingMethod) {
        const shaippingPerCase = (priceData.basePrice > shaippingMethod.discountThreshold) ?
            shaippingMethod.discountFee : priceData.shaippingMethod.feePerCase;
        const shaippingCost = priceData.quantity * shaippingPerCase;
        return priceData.basePrice - priceData.discount + shaippingCost;

    }
}