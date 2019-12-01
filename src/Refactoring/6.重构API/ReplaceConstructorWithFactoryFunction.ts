// 以工厂函数取代构造函数

namespace BadSmell {
    class Employee {
        private _name: string
        private _typeCode: number
        constructor(name: string, typeCode: number) {
            this._name = name;
            this._typeCode = typeCode
        }
        get name(){
            return this._name;
        }
        get type(){
            return this._typeCode;
        }
    }
}
namespace GoodSmell {
    class Employee {
        private _name: string
        private _typeCode: string
        constructor(name: string, typeCode: string) {
            this._name = name;
            this._typeCode = typeCode
        }
        get name(){
            return this._name;
        }
        get type(){
            return this._typeCode;
        }
    }

    function createEngineer(name:string){
        return new Employee(name,'E')
    }
}