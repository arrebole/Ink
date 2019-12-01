// 重构：字段上移

namespace BadSmell{
    abstract class Party {}
    class Employee extends Party {
        protected monthlyCost: number
    }
    class Department extends Party {
        protected monthlyCost: number
    }
}
namespace GoodSmell{
    abstract class Party {
        protected monthlyCost: number
    }
    class Employee extends Party {}
    class Department extends Party {}
}