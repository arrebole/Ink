
class FindDiagonalOrder {
    constructor(matrix) {
        this.matrix = matrix;
        this.result = new Array();
    }
    isUpperRight(aNumber) {
        if (aNumber % 2 == 0) {
            return false;
        }
        return true
    }
    traversing() {
        for (let i = 0; i < this.matrix.length; i++) {
            if(this.isUpperRight(i)){
                
            }
        }
    }
}


/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
function findDiagonalOrder(matrix) {
    return new FindDiagonalOrder(matrix).traversing()
};