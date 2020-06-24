// 重构：折叠继承关系


namespace BadSmell{
    abstract class Employee{}
    class Salesman extends Employee{}
}
namespace GoodSmell{
    class Employee{}
}