# Refactoring

> 所谓重构，是在不改变代码外在行为的前提下，对代码进行修改，以改进程序的内部结构。
>
> 本质上，重构就是在代码写好之后改进它的设计。



# Ⅰ 第一组重构

## 提炼函数

+ 重构名：**提炼函数**
+ 反向重构：**内联函数**

> **将意图和实现分离**，如果你需要花时间浏览一段代码才能弄清楚在干什么，那么就应该将其提炼到函数中，并根据它所做的事为其命名。

### 应对

+ **无局部变量**	 
  + [直接抽离]();

+ **有局部变量**   
  + [作为参数传给目标函数]()；

+ **对局部变量再赋值**   
  + [返回修改后的值]()；
  + [连同临时变量一起提炼]()；

### 演示

```typescript
// typescript
function createArray(siez: number): number[] {
    let result = new Array<number>(siez);
    result.fill(-1, 0, result.length);
    return result;
}
```

```typescript
// 重构结果
function createArray(siez: number) {
    let result = new Array<number>(siez);
    result = fillArray<number>(result, -1);
    return result;
}
function fillArray<T>(aArray: Array<T>, value: T): Array<T> {
    aArray.fill(value, 0, aArray.length);
    return aArray;
}
```





## 内联函数

+ 重构名：**内联函数**
+ 反向重构：**提炼函数**

> 其内部代码和函数名称同样清晰易读。

### 应对

+ 函数具有多态性
  + [无法内联]()；

+ 函数不具有多态性
  + [可以内联]()；

### 演示

```typescript
// typescript
class Customer{
    name:string
    location:string
}

function reportLines(aCustomer: Customer):any[]{
    const lines = [];
    getherCustomerData(lines, aCustomer);
    return lines;
}
function getherCustomerData(out: any[], aCustomer:Customer){
    out.push(["name", aCustomer.name])
    out.push(["location", aCustomer.location])
}
```

```typescript
// 重构结果
function reportLines(aCustomer: Customer): any[] {
    const lines = [];
    lines.push(["name", aCustomer.name])
    lines.push(["location", aCustomer.location])
    return lines;
}
```



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

