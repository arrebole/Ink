#! /usr/bin/deno
// 重构：修改函数声明

namespace BadSmell {
    export function circum(redius:number):number{
        return 2*Math.PI * redius;
    }
}

namespace GoodSmell {

    // function circum(redius:number):number{
    //     return circumference(redius);
    // }
    export function circumference(redius:number):number{
        return 2*Math.PI * redius;
    }
}

(()=>{
    console.assert(
        BadSmell.circum(12) == GoodSmell.circumference(12),
        "测试结果出现偏差"
    )
})()