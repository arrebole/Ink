
/**
 * @description 预排序检测数组频率出现最多的元素
 * @param {array} a 
 * @returns {boolean}
 */
function PresortMode(a) {
    let t = a.concat();
    mergeSort(t);
    let i = 0, modefrequency = 0, modevalue = null;
    while (i <= t.length - 1) {
        let runlength = 1, runvalue = t[i];
        while (i + runvalue <= t.length - 1 && t[i + runlength] == runvalue) {
            runlength++;
        }
        if (runlength > modefrequency) {
            modefrequency = runlength;
            modevalue = runvalue;
        }
        i += runlength;
    }
    return modevalue;
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
            if (i > mid)              a[k] = aux[j++];
            else if (j > hi)          a[k] = aux[i++];
            else if (aux[j] < aux[i]) a[k] = aux[j++];
            else                      a[k] = aux[i++];
        }
    }

    for (let sz = 1; sz < n; sz += sz) {
        for (let lo = 0; lo < n - sz; lo += sz + sz) {
            merge(a, lo, lo + sz - 1, min(lo + sz + sz - 1, n - 1));
        }
    }
}

module.exports.PresortMode = PresortMode;