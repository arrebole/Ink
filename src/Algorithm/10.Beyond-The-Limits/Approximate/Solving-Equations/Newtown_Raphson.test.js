const NewtownRaphson = require("./Newtown_Raphson");
const assert = require("assert")

function TestNewtownRaphson() {
    // 计算 f(x) = x^3-x-1 = 0 的根 [1.3203,1.3281]
    const fn = (x) => x ** 3 - x - 1;
    const dfn = (x) => 3* (x ** 2) - 1;
    const r = NewtownRaphson(fn, dfn, { x: 2, epx: 0.001, N: 15 })
    console.log(r)
    // 核对误差 在0.004内
    assert.equal(
        Math.abs(fn(r)) < 0.004,
        true
    )
}

TestNewtownRaphson();