// 重构：字段下移

namespace BadSmell{
    abstract class Employee{
        private quota: string
    }
    class Engineer extends Employee{}
    class Salesman extends Employee{}

}
namespace GoodSmell{
    abstract class Employee{}
    class Engineer extends Employee{}
    class Salesman extends Employee{
        private quota: string
    }
}