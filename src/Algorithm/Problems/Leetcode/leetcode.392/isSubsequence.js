
// isSubsequence 判断s是否为t的子序列
function isSubsequence(s, t) {
    let count = 0;
    for (let i = 0; i < t.length; i++) {
        if (t[i] == s[count]) count++;
    }
    return count == s.length
}

console.log(
    isSubsequence("abc","ahbgdc")
)