#! /usr/bin/deno
// 重构：函数封装成类

function baseRate(a: number, b: number): number { return 1 }
function taxThreshold(a: number): number { return 1 }

function acquireReading() {
    return {
        customer: "ivan",
        quantity: 10,
        month: 5,
        year: 2017,
    }
}

namespace BadSmell {
    const aReading = acquireReading()
    const base = baseRate(aReading.month, aReading.year) * aReading.quantity;
    const taxableCharge = Math.max(0, base - taxThreshold(aReading.year));
}


namespace GoodSmell {
    class Reading {
        constructor(data) {
            this._customer = data.customer;
            this._quantity = data.quantity;
            this._month = data.month;
            this._year = data.year;
        }
        private _customer: string;
        private _quantity: number;
        private _month: number;
        private _year: number;

        get customer() { return this._customer; }
        get quantity() { return this._quantity; }
        get month() { return this._month; }
        get year() { return this._year; }

        get baseCharge(){
            return baseRate(this.month,this.year)*this.quantity
        }
        get taxableCharge(){
            return Math.max(0, this.baseCharge - taxThreshold(this.year));
        }
    }
    const rawReading = acquireReading()
    const aReading = new Reading(rawReading);
    const base = aReading.baseCharge;
    const taxableCharge = aReading.taxableCharge;
}