// DPNapsackProblem 背包问题的动态规划算法
function DPNapsackProblem({ weights, values }, payload) {
    const itemNumb = weights.length;
    const dp = newMatrix(itemNumb + 1, payload + 1)

    // 构建第一行
    for (let j = 0; j <= payload; j++) {
        if (j >= weights[0]) dp[1][j] = values[0];
    }

    // 构建剩余
    for (let i = 1; i <= itemNumb; i++) {
        for (let j = 1; j <= payload; j++) {
            // 1、当背包已满时，dp为上个最优解
            if (j - weights[i-1] < 0) dp[i][j] = dp[i - 1][j];
            // 2、f(i,j) = max{f(i-1,j),Vi + f(i-1,j-Wi)}
            if (j - weights[i-1] >= 0) dp[i][j] = Math.max(dp[i - 1][j], values[i-1] + dp[i - 1][j - weights[i-1]]);
        }
    }
    return dp[dp.length - 1][dp[0].length - 1]
}

//matrix 创建一个二维数组
function newMatrix(row, col) {
    const result = new Array(row)
    for (let i = 0; i < row; i++) result[i] = new Array(col).fill(0);
    return result
}

module.exports.DPNapsackProblem = DPNapsackProblem