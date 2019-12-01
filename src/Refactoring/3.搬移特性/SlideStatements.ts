// 重构： 移动语句
class PricingPlan{
    unit:any
}
function retrievePricingPlan():PricingPlan{return new PricingPlan()}
function retrieveOrder(){}

namespace BadSmell{
    const pricingPlan = retrievePricingPlan()
    const order = retrieveOrder()
    let charge;
    const chargePerUnit = pricingPlan.unit;
}

namespace GoodSmell{
    const pricingPlan = retrievePricingPlan()
    const chargePerUnit = pricingPlan.unit;
    const order = retrieveOrder()
    let charge;
}