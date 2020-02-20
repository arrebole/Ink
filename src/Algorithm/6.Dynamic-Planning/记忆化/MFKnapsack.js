// MFKnapsack 动态规划记忆化，的背包问题的解法（自顶向下）
function NapsackProblem({ weights, values }, payload) {
    const f = newDPMatrix(weights.length + 1, payload + 1)
    return MFKnapsack(weights.length, payload, { weights, values, f })
}

// MFKnapsack 记忆功能的动态规划 (自顶向下)
function MFKnapsack(i, j, { weights, values, f }) {
    // 如果子问题已经被求解则直接返回答案
    if (f[i][j] >= 0) return f[i][j]

    // 分解子问题
    if (j < weights[i]) f[i][j] = MFKnapsack(i - 1, j, { weights, values, f });
    else {
        f[i][j] = Math.max(
            MFKnapsack(i - 1, j, { weights, values, f }),
            values[i-1] + MFKnapsack(i - 1, j - weights[i-1], { weights, values, f })
        )
    }
    return f[i][j]
}

//matrix 创建一个二维数组
function newDPMatrix(row, col) {
    const result = new Array(row)
    for (let i = 0; i < row; i++) {
        result[i] = new Array(col).fill(0);
    }
    //除了第一行和第一列，其余填-1
    for (let i = 1; i < row; i++) {
        for (let j = 1; j < col; j++) result[i][j] = -1;
    }
    return result
}

module.exports = NapsackProblem