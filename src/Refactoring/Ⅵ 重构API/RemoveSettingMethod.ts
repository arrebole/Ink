//重构：移除设值函数

namespace BadSmell{
    class Person{
        private _name: string
        get name(){
            return this._name;
        }
        set name(aName:string){
            this._name = aName;
        }
    }
}
namespace GoodSmell{
    class Person{
        private _name: string
        get name(){
            return this._name;
        }
    }
}