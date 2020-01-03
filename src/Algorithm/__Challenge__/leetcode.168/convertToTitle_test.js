const convertToTitle = require("./convertToTitle")
const assert = require("assert")


assert.equal(convertToTitle(1), "A",)
assert.equal(convertToTitle(27), "AA")
assert.equal(convertToTitle(28), "AB")
assert.equal(convertToTitle(701), "ZY")
assert.equal(convertToTitle(28), "AB")