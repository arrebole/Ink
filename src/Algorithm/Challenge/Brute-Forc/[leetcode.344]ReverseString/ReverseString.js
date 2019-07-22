// ideas: 暴力法—顺序查找
class Solution {
    constructor(aStringArray) {
        this._aStringArray = aStringArray
    }
    swap(i, j) {
        let temp = this._aStringArray[i];
        this._aStringArray[i] = this._aStringArray[j];
        this._aStringArray[j] = temp
    }

    // 双指针翻转字符串
    reverseString() {
        let lo = 0, hi = this._aStringArray.length - 1;
        while (lo < hi) {
            this.swap(lo++, hi--);
        }
        return this._aStringArray;
    }
}


/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
    return new Solution(s).reverseString()
};

console.log(reverseString(["h","e","l","l","o"]))