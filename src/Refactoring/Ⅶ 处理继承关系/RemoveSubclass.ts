// 重构：移除子类

namespace BadSmell {
    abstract class Person {
        abstract get genderCode(): string
    }
    class Male extends Person {
        get genderCode(): string {
            return "M"
        }
    }
    class Female extends Person {
        get genderCode(): string {
            return "F"
        }
    }
}
namespace GoodSmell {
    class Person {
        private _genderCode: string
        get genderCode(): string {
            return this._genderCode
        }
    }
}