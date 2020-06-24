// 提炼函数


function createArray(siez: number): number[] {
    let result = new Array<number>(siez);
    result.fill(-1, 0, result.length);
    return result;
}

namespace Refactoring {

    export function createArray(siez: number) {
        let result = new Array<number>(siez);
        result = fillArray<number>(result, -1);
        return result;
    }
    function fillArray<T>(aArray: Array<T>, value: T): Array<T> {
        aArray.fill(value, 0, aArray.length);
        return aArray;
    }
}
console.log(Refactoring.createArray(10))