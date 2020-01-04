const assert = require("assert")
const findPeakElement = require("./findPeakElement")

assert.equal(
    [2].includes(findPeakElement([1,2,3,1])),
    true
)

assert.equal(
    [1,5].includes(findPeakElement([1,2,1,3,5,6,4])),
    true
)