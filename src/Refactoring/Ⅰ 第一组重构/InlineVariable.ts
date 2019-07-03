#! /usr/bin/deno
// 重构：内联变量


class Order {
    basePrice: number
}

namespace BadSmell {
    export function isExpensive(anOrder: Order) {
        let basePrice = anOrder.basePrice;
        return (basePrice > 10000)
    }
}


namespace GoodSmell {
    // Skill: 先将变量改为不可修改然后测试，确保变量只被修改一次
    export function isExpensive(anOrder: Order) {
        return anOrder.basePrice > 10000
    }
}

function test() {
    let anOrder = new Order()
    anOrder.basePrice = 10001;

    console.assert(
        BadSmell.isExpensive(anOrder) == GoodSmell.isExpensive(anOrder),
        "\033[31m [error] 测试结果出现偏差"
    )
}
test()