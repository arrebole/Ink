/**
 * @param {string} s
 * @return {boolean}
 */
function checkRecord(s) {
    const slice = s.split("");
    if (absent(slice) > 1) return false;
    if (isContinuLate(slice)) return false;
    return true;
}

/**
 * 统计缺勤数量
 * @param {Array<string>} s
 * @returns {number}
 */
function absent(slice) {
    return slice.reduce((total, v) => v == "A" ? total + 1 : total, 0);
}

/**
 * 判断是否连续迟到
 * @param {Array<string>} slice 
 */
function isContinuLate(slice) {
    let i = 0, j = 1, k = 2;
    while(k < slice.length) {
        if (slice[i] == slice[j] && slice[i] == slice[k]  && slice[i] == "L") return true;
        i++; j++; k++;
    }
    return false;
}

function testCheckRecord() {
    console.log(checkRecord("PPALLL"))
}
