// 重构：移除中间人

namespace BadSmell {
    class Department {

        private _chargeCode: string;
        private _manager: string;

        public get chargeCode(): string {
            return this._chargeCode;
        }
        public set chargeCode(v: string) {
            this._chargeCode = v;
        }

        public get manager(): string {
            return this._manager;
        }
        public set manager(v: string) {
            this._manager = v;
        }

    }

    class Person {
        constructor() {
            this._department = new Department();
        }
        private _department: Department;
        public get department(): Department {
            return this._department;
        }
        public set department(v: Department) {
            this._department = v;
        }

        public get manager(){
            return this.department.manager
        }

    }

    const aPerson = new Person();
    let manger = aPerson.manager;
}

namespace GoodSmell {
    class Department {

        private _chargeCode: string;
        private _manager: string;

        public get chargeCode(): string {
            return this._chargeCode;
        }
        public set chargeCode(v: string) {
            this._chargeCode = v;
        }

        public get manager(): string {
            return this._manager;
        }
        public set manager(v: string) {
            this._manager = v;
        }

    }

    class Person {
        constructor() {
            this._department = new Department();
        }
        private _department: Department;
        public get department(): Department {
            return this._department;
        }
        public set department(v: Department) {
            this._department = v;
        }


    }

    const aPerson = new Person();
    let manger = aPerson.department.manager
}