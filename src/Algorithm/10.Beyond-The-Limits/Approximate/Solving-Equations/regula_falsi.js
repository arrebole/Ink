#! /usr/env node
// 近似算法 试位法求 非线性方程的根


function regulaFalsi(fn, {a, b, epx, N}){
    while(N-- > 0){

        let x0 = (a*fn(b) - b*fn(a))/(fn(b)-fn(a))

        if(fn(x0) == 0 || (x0 - a) < epx) return x0;

        if(fn(x0) * fn(a) < 0)            b = x0;
        else                              a = x0;
    }
    return average(a, b);
}

function average(a, b) {
    return (a + b) / 2;
}

module.exports = regulaFalsi;