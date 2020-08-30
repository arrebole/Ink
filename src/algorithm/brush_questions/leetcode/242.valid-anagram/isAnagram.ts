
function createCharCountTable(str: string): Map<string, number> {
    const result = new Map<string, number>();
    for (const char of str) {
        if (!result.has(char)) result.set(char, 0);
        result.set(char, result.get(char) + 1);
    }
    return result;
}

function mapEq(a: Map<string, number>, b: Map<string, number>): boolean {
    if (a.size != b.size) return false;
    for (const [k, v] of a) {
        if (b.get(k) != v) return false;
    }
    return true;
}

function isAnagram(s: string, t: string): boolean {
    return mapEq(createCharCountTable(s), createCharCountTable(t));
};