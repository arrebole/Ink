#! /usr/bin/deno
// 重构：变量改名
// 好的命名是整洁编程的核心

let height: number;
let width: number;

namespace BadSmell{
    let a = height * width;
}

namespace GoodSmell{
    let area = height * width;
}