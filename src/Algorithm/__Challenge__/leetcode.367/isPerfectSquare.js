function isPerfectSquare(nums) {
    for (let i = 1; i <=  Math.ceil(nums/2); i++) {
        if (i * i == nums) return true;
    }
    return false;
}