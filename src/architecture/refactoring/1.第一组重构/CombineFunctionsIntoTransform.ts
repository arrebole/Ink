#! /usr/bin/deno
// 重构：函数组合成变换


namespace BadSmell{
    const aReading = acquireReading()
    const base = baseRate(aReading.month, aReading.year) * aReading.quantity;
    const taxableCharge = Math.max(0, base - taxThreshold(aReading.year));
}

namespace GoodSmell{
    // 先拷贝一份，再将拷贝的对象赋予所有计算的派生数据，将数据收拢。   
    function enrichReading(origin:any){
        const result = Object.assign({}, origin);
        Object.defineProperty(
            result,
            "baseCharge",
            baseRate(result.month, result.year) * result.quantity    
        )
        Object.defineProperty(
            result,
            "taxableCharge",
            Math.max(0, result.baseCharge - taxThreshold(result.year)) 
        )
        return result;
    }

    const rawReading = acquireReading();
    const aReading = enrichReading(rawReading);
    const taxableCharge = aReading.taxableCharge;
}