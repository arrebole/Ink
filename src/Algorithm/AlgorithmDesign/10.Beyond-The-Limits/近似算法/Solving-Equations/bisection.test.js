const bisection = require("./bisection")
const assert = require("assert")

function TestBisection() {
    // 计算 f(x) = x^3-x-1 = 0 的根 [1.3203,1.3281]
    const fn = (x) => x ** 3 - x - 1
    const r = bisection(fn, 0, 2, 0.001, 30)
    // 核对误差 在0.004内
    assert.equal(
        Math.abs(fn(r)) < 0.004,
        true
    )
}

TestBisection()