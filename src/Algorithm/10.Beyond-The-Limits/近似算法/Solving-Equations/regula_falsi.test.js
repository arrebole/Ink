const regulaFalsi = require("./regula_falsi");
const assert = require("assert");


function TestRegulaFalsi() {
    // 计算 f(x) = x^3-x-1 = 0 的根 [1.3203,1.3281]
    const fn = (x) => x ** 3 - x - 1
    const r = regulaFalsi(fn, { a: 0, b: 2, epx: 0.001, N: 15 })
    // 核对误差 在0.004内
    assert.equal(
        Math.abs(fn(r)) < 0.004,
        true
    )
}
TestRegulaFalsi()