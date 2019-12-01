#! /usr/bin/deno
// 重构：引入参数对象


const station = {
    name: "ZB1",
    readings: [
        { temp: 47, time: "2016-11-10 09:10" },
        { temp: 53, time: "2016-11-10 09:20" },
        { temp: 58, time: "2016-11-10 09:30" },
        { temp: 53, time: "2016-11-10 09:40" },
        { temp: 51, time: "2016-11-10 09:50" },
    ]
}

const operatingPlan = {
    temperatureFloor: 49,
    temperatureCeiling: 54,
}

namespace BadSmell {
    function readingsOutsideRange(station, min, max) {
        return station.readings.filter(r => r.temp < min || r.temp > max)
    }
    // 调用
    const alerts = readingsOutsideRange(
        station, operatingPlan.temperatureFloor,
        operatingPlan.temperatureCeiling
    );

}


namespace GoodSmell {
    class NumberRange {
        constructor(min, max) {
            this._data = { min: min, max: max }
        }
        _data: { min: number, max: number }
        contains(arg): boolean { 
            return (arg >= this.min && arg <= this.max) 
        }
        get min() { return this._data.min }
        get max() { return this._data.max }
    }

    function readingsOutsideRange(station, range: NumberRange) {
        return station.readings.filter(r => !range.contains(r.temp))
    }
    // 调用
    const range = new NumberRange(
        operatingPlan.temperatureFloor,
        operatingPlan.temperatureCeiling
    )
    const alerts = readingsOutsideRange(station, range);
}