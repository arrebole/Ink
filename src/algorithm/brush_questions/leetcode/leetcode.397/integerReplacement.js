function integerReplacement(n) {
    const memory = new Map()
    memory.set(1, 0).set(2, 1).set(2147483647, 32)
    return replacement(n, memory);
}

// replacement 
// expolit: 记忆化动态规划
function replacement(n, f) {
    if (n == 1) return 0;

    if (!f.has(n)) {
        //  如果 n 是偶数
        if ((n & 1) == 0) f.set(n, 1 + replacement(n >> 1, f));
        // 如果 n 是奇数
        if ((n & 1) == 1) f.set(n, 1 + Math.min(replacement(n - 1, f), replacement(n + 1, f)))
    }
    return f.get(n);
}