# Refactoring

> 所谓重构，是在不改变代码外在行为的前提下，对代码进行修改，以改进程序的内部结构。
>
> 本质上，重构就是在代码写好之后改进它的设计。



# Ⅰ 第一组重构

## 提炼函数

+ 重构名：**提炼函数**
+ 反向重构：**内联函数**

> 将意图和实现分离，如果你需要花时间浏览一段代码才能弄清楚在干什么，那么就应该将其提炼到函数中，并根据它所做的事为其命名。

### 无局部变量(ts)

```typescript
function add(a: number, b: number): number {
    console.log("**************");
    console.log("****add*****");
    console.log("**************");
    return a + b;
}
```

```typescript
// ==> 重构结果
function add(a: number, b: number): number {
    addLog();
    return a + b;
}

function addLog() {
    console.log("**************");
    console.log("*****add******");
    console.log("**************");
}
```



### 有局部变量(ts)

```typescript
function addPro(n: { a: number, b: number }): number {
    console.log("**************");
    console.log(`add ${n.a} ${n.b}`);
    console.log("**************");
    return n.a + n.b;
}
```

```typescript
// ==> 重构结果
function addPro(n: { a: number, b: number }): number {
    addProLog(n);
    return n.a + n.b;
}

function addProLog(n: { a: number, b: number }) {
    console.log("**************");
    console.log(`add ${n.a} ${n.b}`);
    console.log("**************");
}
```



### 对局部变量再赋值(ts)

```typescript
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
```

```typescript
// ==> 重构结果
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
```





## 内联函数

+ 重构名：**内联函数**
+ 反向重构：**提炼函数**

> 其内部代码和函数名称同样清晰易读。







## 提炼变量



## 内联变量



## 改变函数声明



## 封装变量



## 变量改名



## 引入参数对象



## 函数组合成类



## 函数组合成变换



## 拆分阶段













# Ⅱ 封装

# Ⅲ 搬移特性

# Ⅳ 重新组织数据

# Ⅴ 简化条件逻辑

# Ⅵ 重构API

# Ⅶ 处理继承关系

