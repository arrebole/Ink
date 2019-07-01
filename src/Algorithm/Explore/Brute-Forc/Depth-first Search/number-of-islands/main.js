/**
 * @param {character[][]} grid
 * @return {number}
 */
function numIslands(grid) {
    const MAX_ROW = grid.length
    if (!MAX_ROW) return 0;
    const MAX_COL = grid[0].length
    const ISLAND = "1"
    let count = 0;

    for (let i = 0; i < MAX_ROW; i++) {
        for (let j = 0; j < MAX_COL; j++) {
            if (grid[i][j] == ISLAND) {
                dfsTravelIsLands(grid, [i, j])
                count++;
            }
        }
    }
    return count;
};

/**
 * @param {character[][]} grid
 * @param {number[]} entrance
 */
function dfsTravelIsLands(grid, entrance) {
    const SEA = "0";
    let [i, j] = entrance;
    if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == "1") {
        grid[i][j] = SEA;
        dfsTravelIsLands(grid, [i + 1, j]);
        dfsTravelIsLands(grid, [i - 1, j]);
        dfsTravelIsLands(grid, [i, j + 1]);
        dfsTravelIsLands(grid, [i, j - 1]);
    }
    return;
}

function main() {
    let m = [
        ["1", "1", "1", "1", "1", "0", "1", "1", "1", "1",],
        ["0", "1", "1", "1", "1", "1", "1", "1", "1", "1",],
        ["1", "0", "1", "1", "1", "0", "0", "1", "1", "0",],
        ["1", "1", "1", "1", "0", "1", "1", "1", "1", "1"],
    ];
    console.time("label");
    console.log(numIslands(m));
    console.timeEnd("label");
}
main();