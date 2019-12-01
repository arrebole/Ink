// 重构：分解条件表达式


interface IDate {
    isBefore(any): boolean
    isAfter(any): boolean
}
interface Play {
    summerStart(): number
    summerEnd(): number
    summerRate: number
    regularRate: number
    regularServiceChargr: number
}

let charge: any
let aDate: IDate
let plan: Play
let quantity: number

namespace BadSmell {

    if (!aDate.isBefore(plan.summerStart) && aDate.isAfter(plan.summerEnd))
        charge = quantity * plan.summerRate;
    else
        charge = quantity * plan.regularRate + plan.regularServiceChargr;
}
namespace GoodSmell {

    charge = summer() ? summerCharge() : regularCharge()

    function summer() {
        return !aDate.isBefore(plan.summerStart) && aDate.isAfter(plan.summerEnd);
    }
    function summerCharge() {
        return quantity * plan.summerRate;
    }
    function regularCharge() {
        return quantity * plan.regularRate + plan.regularServiceChargr;
    }
}