namespace Bad {

    // 无局部变量
    function add(a: number, b: number): number {
        console.log("**************");
        console.log("****add*****");
        console.log("**************");
        return a + b;
    }

    // 有局部变量
    function addPro(n: { a: number, b: number }): number {
        console.log("**************");
        console.log(`add ${n.a} ${n.b}`);
        console.log("**************");
        return n.a + n.b;
    }

    // 局部变量再赋值
    function handle(lo: number, hi: number) {
        let result = 0;
        for (let i = lo; i < hi; i++) {
            result += i;
        }
        for (let i = lo ** lo; i < hi ** hi; i++) {
            result += i;
        }
        return result;
    }
}