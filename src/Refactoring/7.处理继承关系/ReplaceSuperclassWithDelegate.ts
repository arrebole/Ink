// 重构：以委托取代超类

namespace BadSmell{
    class List{}
    class Stack extends List{}
}

namespace GoodSmell{
    class List{}
    class Stack {
        constructor(){
            this.storage = new List()
        }
        private storage:List
    }
}