export class NQueen {

    constructor(n: number) {
        this.N = n;
        this.result = new Array<number[]>();
        this.checkerboard = new Array(n);
    }

    private N: number // 棋盘大小
    private result: number[][] //记录所有解
    private checkerboard: number[] //记录当前解

    // check 验证摆放是否合法
    private check(row: number, col: number): boolean {
        for (let i = 0; i < row; i++) {
            // 都不在同一行、同一列以及同一斜线
            if (this.checkerboard[i] == col
                || this.checkerboard[i] - col == i - row
                || this.checkerboard[i] - col == row - i
            ) return false;
            
        }
        return true
    }

    // backtracking 回溯法求n皇后的摆放解
    private backtracking(row: number) {
        // 递归出口：当搜索行数等于所有行数时
        // 将答案记录到结果中
        if (row == this.N) {
            this.result.push(this.checkerboard.concat())
            return;
        }

        for (let col = 0; col < this.N; col++) {
            if (this.check(row, col)) {
                this.checkerboard[row] = col
                this.backtracking(row + 1)
            }
        }
    }

    public exec(): number[][] {
        this.backtracking(0)
        return this.result
    }
}