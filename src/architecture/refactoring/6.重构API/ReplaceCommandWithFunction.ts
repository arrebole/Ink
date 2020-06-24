// 重构：以函数取代命令

namespace BadSmell {
    class ChargeCalculator {
        constructor(customer, usage) {
            this.customer = customer;
            this.usage = usage
        }
        private customer;
        private usage;
        execute() {
            return this.customer.rate * this.usage;
        }
    }
}
namespace GoodSmell { 
    function chargeCalculator(customer, usage){
        return customer.rate * usage;
    }
}