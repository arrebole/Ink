
fn plus(mut a: i64, mut b: i64)-> i64 {
    while b != 0 {
        let xor = a ^ b;
        let carry = (a & b) << 1;
        a = xor;
        b = carry;
    };
    return a;
}

// a - b = a + (-b) => a + (b的补码)
fn subtract(a: i64, b: i64) -> i64{
    return plus(a, plus(!b, 1));
}

fn main() {
    println!("{}", subtract(10, 9));
}