
// a+b = a^b + (a&b)<<1
// 加法的递归位运算算法
fn plus_recursive(a: i64, b: i64) -> i64 {
    if b == 0 {
        return a;
    }
    let xor = a ^ b;
    let carry = (a & b) << 1; 
    return plus_recursive(xor, carry)
}

// 尾递归
fn plus(mut a: i64, mut b: i64)-> i64 {
    while b != 0 {
        let xor = a ^ b;
        let carry = (a & b) << 1;
        a = xor;
        b = carry;
    };
    return a;
}

fn main(){
    println!("{}", plus(1, 2));
    assert_eq!(plus(2, 2), 4);
}