/**
 * @param {string[]} strs
 * @return {string}
 */
function longestCommonPrefix(strs) {
    if(strs.length == 0) return ""

    let commonPrefix = strs[0];
    while( commonPrefix != ""){
        if(everyHasPrefix(strs, commonPrefix)) return commonPrefix;
        commonPrefix = commonPrefix.slice(0,-1);
    }
    return commonPrefix;
};


function everyHasPrefix(strs, commonPrefix){
    for( str of strs ){
        if(!hasPrefix(str, commonPrefix)) return false;
    }
    return true;
}

/**
 * 
 * @param {string} src 
 * @param {string} prefix 
 */
function hasPrefix(src, prefix){
    if(src.indexOf(prefix) != 0) return false;
    return true
}