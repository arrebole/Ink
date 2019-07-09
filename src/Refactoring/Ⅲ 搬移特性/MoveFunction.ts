// 重构：搬移函数

namespace BadSmell {
    class AccountType { }
    class Account {
        private daysOverdrawn: number
        private type: { isPremium: boolean }
        get bankCharge() {
            let result = 4.5;
            if (this.daysOverdrawn > 0) result += this.overdraftCharge;
            return result;
        }
        get overdraftCharge() {
            if (this.type.isPremium) {
                const baseCharge = 10;
                if (this.daysOverdrawn <= 7) {
                    return baseCharge;
                } else {
                    return baseCharge + (this.daysOverdrawn - 7) * 0.85;
                }

            }
            else return this.daysOverdrawn * 1.75
        }
    }
}

namespace GoodSmell {
    class Account {
        daysOverdrawn: number;
        isPremium: boolean;
        type: AccountType;
        get bankCharge() {
            let result = 4.5;
            if (this.daysOverdrawn > 0) result += this.overdraftCharge;
            return result;
        }
        get overdraftCharge() {
            return this.type.overdraftCharge(this)
        }
    }
    class AccountType {
        overdraftCharge(aAccount: Account) {
            if (aAccount.isPremium) {
                const baseCharge = 10;
                if (aAccount.daysOverdrawn <= 7) {
                    return baseCharge;
                } else {
                    return baseCharge + (aAccount.daysOverdrawn - 7) * 0.85;
                }

            }
            else return aAccount.daysOverdrawn * 1.75
        }
    }
}