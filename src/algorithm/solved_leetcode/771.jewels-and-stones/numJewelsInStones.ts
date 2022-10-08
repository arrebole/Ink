
function numJewelsInStones(J: string, S: string): number {
    let result = 0;
    const jewels = new Set(J);
    for (const char of S) {
        if (jewels.has(char)) result++;
    }
    return result;
};