
// 重构：以对象取代基本类型
namespace BadSmell {
    class Order {
        constructor(data: { priority: string }) {
            this.priority = data.priority
        }
        public priority: string
    }

    const orders = new Array<Order>();
    const highPriorityCount = orders.filter(
        o => "high" === o.priority || "rush" == o.priority
    ).length;
}

namespace GoodSmell {
    class Priority{
        constructor(value:string){
            this._value = value
        }
        private _value:string
        toString(){
            return this._value;
        }
        static legalValues(){return ["low","normal","high","rush"]}
        get _index() {return Priority.legalValues().findIndex(s=>s===this._value)}
        // 🔨骚操作：利用legalValues索引比较
        higherThan(other:Priority){return this._index > other._index}
        lowerThan(other:Priority){return this._index < other._index}
        equals(other:Priority){return this._index ==  other._index}
    }
    class Order {
        constructor(data: { priority: string }) {
            this._priority = new Priority(data.priority)
        }
        // priority被封装成了对象 
        private _priority: Priority
        get priority():Priority {return this._priority}
        get priorityString(){return this._priority.toString()}
        set setPriority(aString:string){this._priority = new Priority(aString)}
    }

    const orders = new Array<Order>();
    const highPriorityCount = orders.filter(o=>o.priority.higherThan(new Priority("normal")))
}