function canConstruct(ransomNote, magazine) {
    const dict = createDictFromStr(magazine)
    for(const s of ransomNote){
        if( !dict.has(s) || dict.get(s) == 0) return false;
        dict.set(s, dict.get(s) - 1);
    }
    return true
};

function createDictFromStr(str){
    const result = new Map()
    for (const s of str) {
        if (!result.has(s)) result.set(s, 1);
        else result.set(s, result.get(s) + 1);
    }
    return result
}