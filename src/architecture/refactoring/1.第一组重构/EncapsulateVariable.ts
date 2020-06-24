#! /usr/bin/deno
// 重构：封装变量


namespace BadSmell {
    let defaultOwner = { firstName: "Martin", lastName: "Fowler" };
}

namespace GoodSmell {
    // 使用函数来管理，过长作用域数据的访问
    export namespace Owner {
        let defaultOwnerData = { firstName: "Martin", lastName: "Fowler" };
        export function defaultOwner(): {firstName: string; lastName: string;}{
            // 防止修改，进行一次数据拷贝
            return Object.assign({}, defaultOwnerData);
        }
        export function setDefaultOwner(arg: {firstName: string; lastName: string;}) {
            defaultOwnerData = arg;
        }
    }
}
