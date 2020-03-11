
function arrangeCoins(n) {
    let result = 1;
    for (result = 1; result < n; result++) {
        n -= result;
    }
    return result-1
}
console.log(arrangeCoins(5))