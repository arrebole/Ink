## 计算机底层算法实现


### 加法
> a+b = a^b + (a&b)<<1

加法的递归实现
```rust
fn plus_recursive(a: i64, b: i64) -> i64 {
    if b == 0 {
        return a;
    }
    let xor = a ^ b;
    let carry = (a & b) << 1; 
    return plus_recursive(xor, carry)
}
```

尾递归优化版本
```rust
fn plus(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let xor = a ^ b;
        b = (a & b) << 1;
        a = xor;
    };
    return a;
}
```