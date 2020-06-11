const assert = require("assert")
const isPalindrome = require("./isPalindrome")



assert.equal(isPalindrome("A man, a plan, a canal: Panama"), true)
assert.equal(isPalindrome("race a car"), false)
assert.equal(isPalindrome("A"), true)
assert.equal(isPalindrome("0P"), false)