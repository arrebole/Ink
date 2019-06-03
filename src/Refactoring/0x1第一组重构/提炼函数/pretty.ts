// 无局部变量
function add(a: number, b: number): number {
    addLog();
    return a + b;
}

function addLog() {
    console.log("**************");
    console.log("****add*****");
    console.log("**************");
}

// 有局部变量
function addPro(n: { a: number, b: number }): number {
    addProLog(n);
    return n.a + n.b;
}

function addProLog(n: { a: number, b: number }) {
    console.log("**************");
    console.log(`add ${n.a} ${n.b}`);
    console.log("**************");
}

// 局部变量再赋值
function handle(lo: number, hi: number) {
    return addAll(lo, hi) + addAll(lo ** lo, hi ** hi);
}

function addAll(lo: number, hi: number): number {
    let result = 0;
    for (let i = lo; i < hi; i++) {
        result += i;
    }
    return result;
}