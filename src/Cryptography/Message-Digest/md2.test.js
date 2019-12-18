const md2 = require("./md2.js")

/**
 * 
 * @param {Uint8Array} data 
 */
function formate(data){
    let result = ""
    for (const code of data) {
        let s = code.toString(16);
        if ( s.length == 1 ) s = '0' + s
        result+=s
    }
    return result
}

function TestMD2(){
    // 求字符串 "abc" md2 值
    // "abc" = [97, 98, 99]
    const test1 = md2(Uint8Array.from([97, 98, 99]))
    console.log(formate(test1))
}

TestMD2()