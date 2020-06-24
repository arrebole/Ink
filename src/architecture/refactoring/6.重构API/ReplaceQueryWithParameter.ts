// 重构：以参数取代查询
let thermostat;

namespace BadSmell {
    class HeatingPlan {
        private _max: number
        private _min: number
        get targetTemperature() {
            if (thermostat.selectedTemperature > this._max) return this._max
            else if (thermostat.selectedTemperature < this._min) return this._min
            else return thermostat.selectedTemperature;
        }
    }
}
namespace GoodSmell {
    class HeatingPlan {
        private _max: number
        private _min: number
        targetTemperature(selectedTemperature:number) {
            if (selectedTemperature > this._max) return this._max
            else if (selectedTemperature < this._min) return this._min
            else return selectedTemperature;
        }
    }
}