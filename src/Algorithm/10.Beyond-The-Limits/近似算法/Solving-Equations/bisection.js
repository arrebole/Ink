

// bisection 解非线性方程的平分算法
// fn: 求fn的一个根
// a,b: f(a)*f(b) < 0
// eps: 绝对误差的上界
// N： 迭代次数的上限
function bisection(fn, a, b, eps, N) {
    // 统计迭代次数
    let n = 0;
    while (n++ <= N) {
        // 寻找中点
        let x0 = average(a, b)

        // 如果误差精度足够 或者刚好为根 则返回结果 
        if ((x0 - a) < eps || fn(x0) == 0) return x0;

        // 往根处靠近
        if (fn(x0) * fn(a) < 0) b = x0;
        else                    a = x0;
    }
    return average(a, b);
}

function average(a, b) {
    return (a + b) / 2;
}

module.exports = bisection