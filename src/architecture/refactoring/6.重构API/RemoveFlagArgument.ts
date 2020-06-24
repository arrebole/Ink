// 重构：移除标记参数

namespace BadSmell {
    function deliveryDate(anOrder, isRush: boolean) {
        if (isRush) {
            let deliveryTime;
            if (["MA", "CT"].includes(anOrder.deliveryState)) deliveryTime = 1;
            else if (["NY", "NH"].includes(anOrder.deliveryState)) deliveryTime = 2;
            else deliveryTime = 3;
            return anOrder.placedOn.plusDays(1 + deliveryTime);
        } else {
            let deliveryTime;
            if (["MA", "CT", "NY"].includes(anOrder.deliveryState)) deliveryTime = 2;
            else if (["ME", "NH"].includes(anOrder.deliveryState)) deliveryTime = 3;
            else deliveryTime = 4;
            return anOrder.placedOn.plusDays(2 + deliveryTime);
        }
    }
}
namespace GoodSmell { 
    function rushDeliveryDate(anOrder){
        let deliveryTime;
        if (["MA", "CT"].includes(anOrder.deliveryState)) deliveryTime = 1;
        else if (["NY", "NH"].includes(anOrder.deliveryState)) deliveryTime = 2;
        else deliveryTime = 3;
        return anOrder.placedOn.plusDays(1 + deliveryTime);
    }
    function regularDeliveryDate(anOrder){
        let deliveryTime;
        if (["MA", "CT", "NY"].includes(anOrder.deliveryState)) deliveryTime = 2;
        else if (["ME", "NH"].includes(anOrder.deliveryState)) deliveryTime = 3;
        else deliveryTime = 4;
        return anOrder.placedOn.plusDays(2 + deliveryTime);
    }
}