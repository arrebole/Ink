// 重构：提炼超类

namespace BadSmell {
    class Department {
        private _annualCost;
        private _name;
        private _headCount;
        get totalAnnualCost() {
            return this.totalAnnualCost;
        }
        get name() {
            return this._name
        }
        get headCount() {
            return this._headCount
        }
    }
    class Employee {
        private _id;
        private _name;
        private _annualCost;
        get name() {
            return this._name;
        }
        get id() {
            return this._id
        }
        get annualCost() {
            return this._annualCost
        }
    }
}
namespace GoodSmell {
    abstract class Party {
        private _name;
        private _annualCost;
        get name() {
            return this._name;
        }
        get annualCost() {
            return this._annualCost
        }
    }
    class Department extends Party {
        private _headCount;
        get headCount() {
            return this._headCount
        }
    }
    class Employee extends Party {
        private _id;
        get id() {
            return this._id
        }
    }
}