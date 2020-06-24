// 重构：构造函数本体上移

namespace BadSmell {
    abstract class Party {
        protected monthlyCost: number
    }
    class Employee extends Party {
        constructor(aCost: number) {
            super()
            this.monthlyCost = aCost;
        }
    }
    class Department extends Party {
        constructor(aCost: number) {
            super()
            this.monthlyCost = aCost;
        }
    }
}
namespace GoodSmell {
    abstract class Party {
        protected monthlyCost: number
        constructor(aCost: number) {
            this.monthlyCost = aCost;
        }
    }
    class Employee extends Party {}
    class Department extends Party {}
}