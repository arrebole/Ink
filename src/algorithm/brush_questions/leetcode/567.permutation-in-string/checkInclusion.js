
function isInclusion(str, map) {
    for (const char of str) {
        if (!map.has(char)) return false;
        const num = map.get(char);
        if (num - 1 == 0) map.delete(char);
        else map.set(char, num - 1);
    }
    return true;
}

function createCharMap(str) {
    const result = new Map();
    for (const char of str) {
        if (result.has(char)) result.set(char, result.get(char) + 1);
        else result.set(char, 1);
    }
    return result
}

function checkInclusion(s1, s2) {
    const len = s1.length;
    const inclusion = createCharMap(s1);
    // 滑块方法
    for (let i = 0; i + len <= s2.length; i++) {
        if (isInclusion(s2.slice(i, i + len), new Map(inclusion))) return true;
    }
    return false;
}