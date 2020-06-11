


// singleNumber 返回两个只出现过一次的数
// exploit 时空权衡-预构造
function singleNumber(nums){
    const table = new Set()
    for(const i of nums){
        if(table.has(i)) table.delete(i)
        else             table.add(i)
    }
    
    return Array.from(table)
}

module.exports = singleNumber