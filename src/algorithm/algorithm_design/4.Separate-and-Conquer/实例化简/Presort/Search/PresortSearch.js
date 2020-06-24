
/**
 * @description 变治法-预排序查找
 * @param {array} a  
 * @param {int} key 
 */
function PresortSearch(a, key) {
    let t = a.concat();
    let l = 0, r = t.length - 1, m = 0;
    mergeSort(t);
    while (l <= r) {
        m = parseInt((l + r) / 2);
        if (t[m] == key)    return m;
        if (key < a[m])     r = m - 1;
        else                l = m + 1;
    }
    return -1;
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
            if (i > mid) a[k] = aux[j++];
            else if (j > hi) a[k] = aux[i++];
            else if (aux[j] < aux[i]) a[k] = aux[j++];
            else a[k] = aux[i++];
        }
    }

    for (let sz = 1; sz < n; sz += sz) {
        for (let lo = 0; lo < n - sz; lo += sz + sz) {
            merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
        }
    }
}

module.exports.PresortSearch = PresortSearch;