// findTheDifference 找两个字符串的不同
// exploit: 时空权衡-预构造 hash-table
function findTheDifference(s, t) {
    const dict1 = createDictFromStr(s);
    const dict2 = createDictFromStr(t);
    for(const pair of dict2){
        if (!dict1.has(pair[0]) || dict1.get(pair[0]) != pair[1]){
            return pair[0]
        }
    }
};


function createDictFromStr(str){
    const result = new Map()
    for (const s of str) {
        if (!result.has(s)) result.set(s, 1);
        else result.set(s, result.get(s) + 1);
    }
    return result;
}