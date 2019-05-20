
/**
 * 
 * @param {Array<any>} arr 
 * @param {any} key 
 * @returns -1/index
 */
function SequentialSearch(arr, key) {
    
    arr.push(key);
    let j = 0;
    while (arr[j] != key) {
        j++;
    }
    if (j == arr.length - 1) {
        return -1;
    }
    return j;
}


console.log(SequentialSearch([1, 2, 3, 4, 5, 6, 7, 8], 9));