// 重构：合并表达式

interface Employee {
    seniority: number
    monthsDisabled: number
    isPartTime: boolean
}

let anEmployee: Employee

namespace BadSmell {
    function disabilityAmount() {
        if (anEmployee.seniority < 2) return 0;
        if (anEmployee.monthsDisabled > 12) return 0;
        if (anEmployee.isPartTime) return 0;
        return 1;
    }
}
namespace GoodSmell {
    function disabilityAmount() {
        if (isNotEligibleForDisability()) return 0;
        return 1;
    }
    function isNotEligibleForDisability() {
        return (anEmployee.seniority < 2)
            || (anEmployee.monthsDisabled > 12)
            || (anEmployee.isPartTime);
    }
}