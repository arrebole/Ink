// 重构：以子类取代类型码

namespace BadSmell{
    class Employee{
        constructor(name, type){}
    }
    function createEmployee(name,type){
        return new Employee(name,type)
    }
}
namespace GoodSmell{
    class Employee{
        constructor(name){}
    }
    class Engineer extends Employee{}
    class SaleSman extends Employee{}
    
    function createEmployee(name,type):Employee{
        switch(type){
            case "Engineer": return new Engineer(name)
            case "SaleSman":return new SaleSman(name)
            default: throw new Error()
        }
    }
}