
/**
 * 
 * @param {Array<Number>} a 
 * @returns {Array<Number>} sorted array
 */
function insertionSort(a) {
    
    for (let i = 1; i < a.length; i++){
        let v = a[i];
        let j = i - 1;
        while (j >= 0 && a[j] > v) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }

    return a;
}

var arr = [3,5,1,2,7,8,9,0]

console.log(insertionSort(arr))