

// grayCode 格雷姆码
function grayCode(n) {
    result = [];
    for (let i = 0; i < 2 ** n; i++) {
        result.push(i ^ (i >> 1))
    }
    return result;
}

console.log(grayCode(2))