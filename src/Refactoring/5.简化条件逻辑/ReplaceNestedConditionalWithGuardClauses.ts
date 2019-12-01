// 重构：以卫语句取代嵌套条件表达式
interface Instrument {
    capital: number
    interestRate: number
    duration: number
    income: number
    adjusementFactor: number
}

namespace BadSmell {
    function adjustedCapital(anInstrument: Instrument) {
        let result = 0;
        if (anInstrument.capital > 0) {
            if (anInstrument.interestRate > 0 && anInstrument.duration > 0) {
                result = (anInstrument.income / anInstrument.duration) * anInstrument.adjusementFactor;
            }
        }
        return result;
    }
}
namespace GoodSmell {
    function adjustedCapital(anInstrument: Instrument) {

        if ( anInstrument.capital          <= 0
            || anInstrument.interestRate   <= 0
            || anInstrument.duration       <= 0 ) return 0;

        return (anInstrument.income / anInstrument.duration) * anInstrument.adjusementFactor;
    }
}