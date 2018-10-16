
/**
 * 
 * @param {Array<Number>} a 
*/
function shellSort(a) {
    let len = a.length;
    let gap = 1;
    while (gap < len / 3) {
        gap = 3 * gap + 1;
    }
    while (gap > 0) {
        for (let i = gap; i < len; i++) {
            let v = a[i];
            let j = i - gap;
            while (j >= 0 && a[j] > v) {
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = v;
        }
        gap = parseInt(gap / 3);
    }
    return a;
}

var arr = [3, 6, 1, 7, 9, 0, 3, 6, 5];
console.log(shellSort(arr))