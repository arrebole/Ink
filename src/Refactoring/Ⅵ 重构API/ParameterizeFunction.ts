// 重构：函数参数化

namespace BadSmell {
    function baseCharge(usage: number) {
        if (usage < 0) return -1
        const amount =
            bottomBand(usage) * 0.03
            + middleBand(usage) * 0.05
            + topBand(usage) * 0.07;
        return amount;
    }

    function bottomBand(usage: number) {
        return Math.min(usage, 100);
    }
    function middleBand(usage: number) {
        return usage > 100 ? Math.min(usage, 200) - 100 : 0;
    }
    function topBand(usage: number) {
        return usage > 200 ? usage - 200 : 0;
    }
}
namespace GoodSmell {
    function baseCharge(usage: number) {
        if (usage < 0) return -1
        const amount =
            withinBand(usage, 100) * 0.03
            + withinBand(usage, 100, 200) * 0.05
            + withinBand(usage, 200, Infinity) * 0.07;
        return amount;
    }
    
    function withinBand(usage: number, bottom?: number, top?: number) {
        return usage > bottom ? Math.min(usage, top) - bottom : 0;
    }
}