// 重构：引入特例

namespace BadSmell {
    let site: Site
    class Site {
        customer: Customer
    }
    class Customer {
        _name: string
        get name() { return this._name }
    }

    let aCustomer = site.customer;
    if (aCustomer.name == "unknown") {

    }

}
namespace GoodSmell {
    let site: Site
    function isUnkown(arg: { isUnkown(): boolean }) {
        return arg.isUnkown()
    }
    class Site {
        customer: Customer
    }
    class Customer {
        _name: string
        get name() { return this._name }
        isUnkown() {
            return false;
        }
    }
    function createUnkownCustomer() {
        return {
            name: "isUnkown",
            isUnkown() {
                return true;
            }
        }
    }

    let aCustomer = site.customer;
    if (isUnkown(aCustomer)) {

    }
}