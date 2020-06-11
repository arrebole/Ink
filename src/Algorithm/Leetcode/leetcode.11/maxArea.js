

// maxArea 盛最多水的容器
// expolit: 双指针; T(n) = O(n)
function maxArea(height) {
    let [lo, hi] = [0, height.length - 1]
    let result = 0
    while (lo != hi) {
        result = Math.max(
            result,
            Math.min(height[lo], height[hi]) * (hi - lo)
        )
        if (height[lo] > height[hi]) hi--;
        else lo++;
    }
    return result;
};