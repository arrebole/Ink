
class FindDiagonalOrder {
    constructor(matrix) {
        this.matrix = matrix;
        this.result = new Array();
    }
    isOver(x, y) {

    }
    traversing(x, y) {
        this.result.push(this.matrix[y][x])
        if (!this.isOver(x - 1, y + 1)) this.traversing(x - 1, y + 1);
    }
    execult() {

    }
}

/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
function findDiagonalOrder(matrix) {
    return new FindDiagonalOrder(matrix).execult()
};