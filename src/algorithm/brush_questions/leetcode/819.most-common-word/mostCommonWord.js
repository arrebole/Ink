
function mostCommonWord(paragraph, banned) {
    const words = paragraph.replace(/\W/g, ' ').split(' ')
        .map(v => v.trim().toLowerCase())
        .filter(v => !!v);

    const hashmap = new Map();
    for (const word of words) {
        if (!hashmap.has(word)) hashmap.set(word, 0);
        hashmap.set(word, hashmap.get(word) + 1);
    }

    for (const bann of banned) {
        hashmap.delete(bann);
    }

    return findMaxValue(hashmap);
};

function findMaxValue(map) {
    let result = "";
    let resultCount = 0;
    for (const [k, v] of map) {
        if (v < resultCount) continue;
        result = k;
        resultCount = v;
    }
    return result;
}