
function main() {
    let a = [3, 5, 6, 7, 8, 2, 8, 34, 6, 23, 12, 24, 6, 37, 7];
    console.log(PresortElementUniqueness(a));
}

/**
 * @description 预排序检测数组唯一性
 * @param {array} a 
 * @returns {boolean}
 */
function PresortElementUniqueness(a) {
    let t = a.concat();
    mergeSort(t);
    for (let i = 0; i <= t.length - 2; i++) {
        if (t[i] == t[i + 1]) return false;
    }
    return true;
}

/**
 * @description 分治法-自下而上的归并排序
 * @param {array} a 
 */
function mergeSort(a) {
    let n = a.length;
    let aux = new Array(n);

    let min = (m, n) => m > n ? n : m;

    let merge = (a, lo, mid, hi) => {
        let i = lo, j = mid + 1;
        for (let k = lo; k <= hi; k++) {
            aux[k] = a[k];
        }
        for (let k = lo; k <= hi; k++) {
            if (i > mid)                a[k] = aux[j++];
            else if (j > hi)            a[k] = aux[i++];
            else if (aux[j] < aux[i])   a[k] = aux[j++];
            else                        a[k] = aux[i++];
        }
    }

    for (let sz = 1; sz < n; sz += sz) {
        for (let lo = 0; lo < n - sz; lo += sz + sz) {
            merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
        }
    }
}


main();