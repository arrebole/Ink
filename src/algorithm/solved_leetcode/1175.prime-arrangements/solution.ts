// 质数排列 @see https://leetcode.cn/problems/prime-arrangements/

function numPrimeArrangements(n: number): number {
    if (n === 1) {
        return 1;
    }
    const countNumPrime = eratosthenes(n);
    return Number(mod(arrangements(countNumPrime) * arrangements(n - countNumPrime)))
};

function arrangements(n: number) {
    let result = BigInt(n);
    while (--n > 0) {
        result = mod(result) * BigInt(n)
    }
    return mod(result);
}

function mod(n: bigint) {
    return n % BigInt(1000000000 + 7);
}

// 埃拉托斯特尼筛法
function eratosthenes(n: number) {
    const nums = new Array(n + 1).fill(1);
    for (let i = 2; i <= n / 2; i++) {
        if (nums[i] === 0) {
            continue;
        }
        for (let j = 2; i * j <= n; j++) {
            nums[i * j] = 0;
        }
    }
    return nums.reduce((p, c) => p + c, 0) - 2;
}