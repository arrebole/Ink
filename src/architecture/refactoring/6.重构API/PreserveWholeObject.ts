// 重构：保持对象完整
let aBoom;
let aplan;
namespace BadSmell{
    const low = aBoom.daysTempRange.low;
    const high = aBoom.daysTempRange.hight;
    if(aplan.withinRange(low,high)){
        console.log("room temperature went outside range\n");
    }
}
namespace GoodSmell{
    if(aplan.withinRange(aBoom.daysTempRange)){
        console.log("room temperature went outside range\n");
    }
}