const assert = require("assert")
const singleNumber = require("./singleNumber")

assert.deepEqual(
    singleNumber([1,2,1,3,2,5]), 
    [3,5]
)