// 重构：提炼类



namespace BadSmell {
    class Person {
        private _name: string;
        private _officeAreaCode: string;
        private _officeNumber: string;

        public get name(): string {
            return this._name;
        }
        public set name(v: string) {
            this._name = v;
        }
        public get officeAreaCode(): string {
            return this._officeAreaCode;
        }
        public set officeAreaCode(v: string) {
            this._officeAreaCode = v;
        }
        public get officeNumber(): string {
            return this._officeNumber;
        }
        public set officeNumber(v: string) {
            this._officeNumber = v;
        }
        public get telephoneNumber(): string {
            return `(${this.officeAreaCode}) ${this.officeNumber}`;
        }
    }
}

namespace GoodSmell {

    class TelephoneNumber{
        private _areaCode: string;
        private _number: string;

        public get areaCode(): string {
            return this._areaCode;
        }
        public set areaCode(v: string) {
            this._areaCode = v;
        }
        public get number(): string {
            return this._number;
        }
        public set number(v: string) {
            this._number = v;
        }
        public get toString(): string {
            return `(${this.areaCode}) ${this.number}`;
        }
    }

    class Person {

        constructor(){
            this._telephoneNumber = new TelephoneNumber();
        }

        private _name: string;
        private _telephoneNumber:TelephoneNumber;

        public get name(): string {
            return this._name;
        }
        public set name(v: string) {
            this._name = v;
        }
        public get officeAreaCode(): string {
            return this._telephoneNumber.areaCode;
        }
        public set officeAreaCode(v: string) {
            this._telephoneNumber.areaCode = v;
        }
        public get officeNumber(): string {
            return this._telephoneNumber.number;
        }
        public set officeNumber(v: string) {
            this._telephoneNumber.number = v;
        }
        public get telephoneNumber(): string {
            return this._telephoneNumber.toString
        }
    }
}