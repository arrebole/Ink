
function separate(n) {
    const result = new Array();
    while (n != 0) {
        result.push(n % 10);
        n = parseInt(n / 10, 10);
    }
    return result;
}

function merge(a) {
    return a.reduce((r, v) => r + v * v, 0)
}

function isHappy(n) {
    for (let i = 0; i < 20; i++) {
        if (n == 1) return true;
        n = merge(separate(n));
    }
    return false;
}