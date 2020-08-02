/**
 * @param {number[]} candies
 * @return {number}
 */
function distributeCandies(candies) {
    return Math.min(setSize(candies), candies.length / 2);
};

function setSize(a) {
    const set = new Set();
    for(const i of a) set.add(i);
    return set.size;
}