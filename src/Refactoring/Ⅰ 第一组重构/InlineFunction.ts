// 内联函数
class Customer {
    name: string
    location: string
}

function reportLines(aCustomer: Customer): any[] {
    const lines = [];
    getherCustomerData(lines, aCustomer);
    return lines;
}

function getherCustomerData(out: any[], aCustomer: Customer) {
    out.push(["name", aCustomer.name])
    out.push(["location", aCustomer.location])
}

namespace Refactoring {
    export function reportLines(aCustomer: Customer): any[] {
        const lines = [];
        lines.push(["name", aCustomer.name])
        lines.push(["location", aCustomer.location])
        return lines;
    }

}
let t = new Customer()
t.name = "xxx";
t.location = "aaa";
console.log(Refactoring.reportLines(t))