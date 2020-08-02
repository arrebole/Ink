/**
 * @param {number} n
 * @return {string}
 */
function countAndSay(n) {
    let result = ["1"]
    for(let i = 0; i <= n; i++){
        result.push(parse(result[i]))
    }
    return result[n-1]
};

function parse(str){
    let result = ""
    let stack = []
    for(const s of str){
        if(stack.length == 0 || stack[stack.length-1] == s) stack.push(s);
        else if(stack[stack.length-1] != s){
            result+=`${stack.length}${stack[stack.length-1]}`
            stack = [s]
        }
    }
    result+=`${stack.length}${stack[stack.length-1]}`
    return result
}