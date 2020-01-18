/**
 * @param {string} path
 * @return {string}
 */
function simplifyPath(path) {
    const queue = [];
    const paths = path.split("/").filter(v => v.length != 0);
    for(const s of paths){
        if(s == ".") continue;
        if(s == "..") queue.pop();
        else queue.push(s);
    }
    return "/" + queue.join("/");
};