// 重构：函数下移


namespace BadSmell {
    abstract class Party {
        protected monthlyCost: number
        get annualCost() {
            return this.monthlyCost;
        }
    }
    class Employee extends Party {}
    class Department extends Party {}
}
namespace GoodSmell { 
    abstract class Party {
        protected monthlyCost: number
    }
    class Employee extends Party {
        get annualCost() {
            return this.monthlyCost;
        }
    }
    class Department extends Party {}
}