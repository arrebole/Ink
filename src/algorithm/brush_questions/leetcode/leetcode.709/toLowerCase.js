
function toLowerCase(str) {
    let result = ""
    for(let i = 0; i<str.length;i++){
        if(str[i].charCodeAt() <= 0x5A && str[i].charCodeAt() >= 0x41){
            result+= String.fromCharCode(str[i].charCodeAt()+32)
            continue;
        }
        result+=str[i]
    }
    return result
};