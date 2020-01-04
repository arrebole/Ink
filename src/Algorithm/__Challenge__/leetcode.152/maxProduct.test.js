const assert = require("assert")
const maxProduct = require("./maxProduct")

assert.equal(
    maxProduct([2, 3, -2, 4]),
    6
)

assert.equal(
    maxProduct([-2,0,-1]),
    0
)