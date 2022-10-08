
function hasZero(n: number): boolean {
    for (const char of n.toString()) {
        if (char === '0') return true;
    }
    return false;
}

function getNoZeroIntegers(n: number): number[] {
    let a = n - 1, b = 1;
    while(hasZero(a) || hasZero(b)) {
        a--;
        b++;
    }
    return [a, b];
};