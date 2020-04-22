// 牛顿法解 非线性方程的根
// X<n-1> = X<n> - f(X<n>)/f'(X<n>)

function NewtownRaphson(fn, dfn,{x, epx, N}){
    while (N-- > 0) {
        if(fn(x) == 0 || fn(x) < epx) return x;
        else                          x = x- fn(x)/dfn(x);
    }
    return x;
}

module.exports = NewtownRaphson;