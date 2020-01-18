/**
 * minPathSum 最小路径和
 * expolit 动态规划
 * @param {number[][]} grid
 * @return {number}
 */
function minPathSum(grid) {

    for (let j = 1; j < grid[0].length; j++) {
        grid[0][j] = grid[0][j] + grid[0][j - 1];
    }
    for (let i = 1; i < grid.length; i++) {
        grid[i][0] = grid[i][0] + grid[i - 1][0];
    }

    for (let i = 1; i < grid.length; i++) {
        for (let j = 1; j < grid[0].length; j++) {
            grid[i][j] = Math.min(grid[i][j - 1], grid[i - 1][j]) + grid[i][j];
        }
    }
    return grid[grid.length - 1][grid[0].length - 1];
};