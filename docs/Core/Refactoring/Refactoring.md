# Refactoring

## Introduction

> 所谓重构，是在不改变代码外在行为的前提下，对代码进行修改，以改进程序的内部结构。
>
> 本质上，重构就是在代码写好之后改进它的设计。



## Table of Contents

+ 第一组重构
  + [提炼函数](#提炼函数)
  + [内联函数](#内联函数)
  + [提炼变量](#提炼变量)
  + [内联变量](#内联变量)
  + [改变函数声明](#改变函数声明)
  + [封装变量](#封装变量)
  + [变量改名](#变量改名)
  + [引入参数对象](#引入参数对象)
  + [函数组合成类](#函数组合成类)
  + [函数组合成变换](#函数组合成变换)
  + [拆分阶段](#拆分阶段)
+ 封装
+ 搬移特性
+ 重新组织数据
+ 简化条件逻辑
+ 重构API
+ 处理继承关系





# Ⅰ第一组重构

## 提炼函数

> **将意图和实现分离**，如果你需要花时间浏览一段代码才能弄清楚在干什么，那么就应该将其提炼到函数中，并根据它所做的事其命名。

+ 重构名：**提炼函数**（Extract Function）
+ 反向重构：[**内联函数** （Inline Function）](#内联函数)

### 演变

+ 无局部变量	 
  + [直接抽离]();

+ 有局部变量   
  + [作为参数传给目标函数]()；

+ 对局部变量再赋值   
  + [返回修改后的值]()；
  + [连同临时变量一起提炼]()；

### 操作

**普遍操作**

```typescript
// 待重构: 提炼函数
function createArray(siez: number): number[] {
    let result = new Array<number>(siez);
    result.fill(-1, 0, result.length);
    return result;
}
```

```typescript
// 重构后: 提炼函数
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

> 当其内部代码和函数名称同样**清晰易读时**，进行内联函数。

+ 重构名：**内联函数**（Inline Function）
+ 反向重构：[**提炼函数**（Extract Function）](#提炼函数)

### 演变

+ 函数具有多态性
  + [无法内联]()；

+ 函数不具有多态性
  + [可以内联]()；

### 操作

**普遍内联函数**

```typescript
class Customer{
    name:string
    location:string
}
// 待重构: 内联函数
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
// 重构后： 内联函数
function reportLines(aCustomer: Customer): any[] {
    const lines = [];
    lines.push(["name", aCustomer.name])
    lines.push(["location", aCustomer.location])
    return lines;
}
```



## 提炼变量

> 局部变量可以帮助我们将表达式分解为比较容易管理的形似。
>
> 内联的变量过于淤积难以理解，使用分离思想。

+ 重构名：提炼变量（Extract Variable）、引入解释性变量
+ 反向重构：[内联变量（Inline Variable）](#内联变量)

### 演变

+ 函数普通操作
  + [添加临时操作]()
+ 函数位于一个类中
  + [变量提炼成方法]()

### 操作

**普通操作**

```typescript
class Order {
    quantity: number
    itemPrice: number
}

// 待重构: 函数内提炼变量
function price(order: Order): number {
    return order.quantity * order.itemPrice -
        Math.max(0, order.quantity - 500) * order.itemPrice * 0.05 +
        Math.min(order.quantity * order.itemPrice * 0.1, 100);
}
```

```typescript
// 重构后： 函数内提炼变量
function price(order: Order): number {
    const basePrice = order.quantity * order.itemPrice;
    const quantityDiscount = Math.max(0, order.quantity - 500) * order.itemPrice * 0.05;
    const shipping = Math.min(order.quantity * order.itemPrice * 0.1, 100);
    return basePrice - quantityDiscount + shipping;
}
```



**提炼变量的函数位于一个类中**

```typescript
// 待重构：类内提炼变量
class Order {
    quantity: number
    itemPrice: number
    price(): number {
        return this.quantity * this.itemPrice -
            Math.max(0, this.quantity - 500) * this.itemPrice * 0.05 +
            Math.min(this.quantity * this.itemPrice * 0.1, 100);
    }
}
```

```typescript
// 重构后：类内提炼变量
class Ref_Order {
    quantity: number
    itemPrice: number
    get quantityDiscount(): number {
        return Math.max(0, this.quantity - 500) * this.itemPrice * 0.05;
    }
    get basePrice(): number {
        return this.quantity * this.itemPrice;
    }
    get shipping(): number {
        return Math.min(this.quantity * this.itemPrice * 0.1, 100);
    }
    price(): number {
        return this.basePrice - this.quantityDiscount + this.shipping;
    }
}
```



## 内联变量

> 变量名并不比表达式本身更具表现力；
>
> 妨碍重构附近的代码；

+ 重构名：**内联变量**（line Variable）
+ 反向重构：[**提炼变量**(Extract Variable)](#提炼变量)

### 演变

+ 正常操作

### 操作

**广泛操作**

```typescript
#! /usr/bin/deno
class Order {
    basePrice: number
}

function isExpensive(anOrder: Order) {
    let basePrice = anOrder.basePrice;
    return (basePrice > 10000)
}

```

```typescript
// ⭐Skill: 先将变量改为不可修改然后测试，确保变量只被修改一次
function isExpensive(anOrder: Order) {
    return anOrder.basePrice > 10000
}
```





## 改变函数声明

> 好的函数的名和参数，能提供清晰的用意；
>
> 函数声明会随需求适应而改变。

+ 重构名：**改变函数声明**(Change Function Declaration)、函数改名、修改签名

### 演变

+ 迁移式改名
+ 添加参数
+ 把参数改为属性

### 操作

**迁移式添加参数**

```typescript
#! /usr/bin/deno
function circum(redius:number):number{
    return 2*Math.PI * redius;
}
```

```typescript
// ⭐skill: 利用间接调用进行迁移式修改
// function circum(redius:number):number{
//     return circumference(redius);
// }
function circumference(redius:number):number{
    return 2*Math.PI * redius;
}
```





## 封装变量

> 以函数的形式封装对该数据的访问，可以容易的迁移重构和管理。
>
> **不可变性**是强大的代码防腐剂，对于所有可变的数据，**作用域越大封装就越重要**。

+ 重构名：封装变量(Encapsulate Variable)、封装字段

### 演变

+ 返回拷贝副本防止修改

### 操作

```typescript
let defaultOwner = { firstName: "Martin", lastName: "Fowler" };
```

```typescript
// 🍭重构后:
// 使用函数来管理，过长作用域数据的访问
export namespace Owner {
    let defaultOwnerData = { firstName: "Martin", lastName: "Fowler" };
    export function defaultOwner(): {firstName: string; lastName: string;} {
        // 防止修改，进行一次数据拷贝
        return Object.assign({}, defaultOwnerData);
    }
    export function setDefaultOwner(arg: {firstName: string; lastName: string;}) {
        defaultOwnerData = arg;
    }
}
```





## 变量改名

> 好的命名是整洁编程的核心

+ 重构名：变量改名(Rename Variable)

### 演变

+ 迁移式修改
+ 封装变量

### 操作

一个好的变量名很重要

```typescript
 let a = height * width;
```

```typescript
let area = height * width;
```





## 引入参数对象

> 一组数据总是结伴而行，出没于一个又一个函数，这样一组数据就是所谓的数据你团。
>
> 将数据组织成结构是一件有价值的事，它会催生代码中更深层次的改变。

+ 重构名：引入参数对象(Introduce Parameter Object)

### 演变

+ 构造参数对象

### 操作

```typescript
const station = {
    name: "ZB1",
    readings: [
        { temp: 47, time: "2016-11-10 09:10" },
        { temp: 53, time: "2016-11-10 09:20" },
        { temp: 58, time: "2016-11-10 09:30" },
        { temp: 53, time: "2016-11-10 09:40" },
        { temp: 51, time: "2016-11-10 09:50" },
    ]
}

const operatingPlan = {
    temperatureFloor: 49,
    temperatureCeiling: 54,
}
```

```typescript
// 待重构
function readingsOutsideRange(station, min, max) {
    return station.readings.filter(r => r.temp < min || r.temp > max)
}
// 调用
const alerts = readingsOutsideRange(
    station, operatingPlan.temperatureFloor,
    operatingPlan.temperatureCeiling
);
```

```typescript
// 重构后：
// 引入的参数对象
class NumberRange {
    constructor(min, max) {
        this._data = { min: min, max: max }
    }
    _data: { min: number, max: number }
    // 🌹
    contains(arg): boolean { 
        return (arg >= this.min && arg <= this.max) 
    }
    get min() { return this._data.min }
    get max() { return this._data.max }
}

function readingsOutsideRange(station, range: NumberRange) {
    return station.readings.filter(r => !range.contains(r.temp))
}
// 调用
const range = new NumberRange(
    operatingPlan.temperatureFloor,
    operatingPlan.temperatureCeiling
)
const alerts = readingsOutsideRange(station, range);
```





## 函数组合成类

> 如果发现**一组函数**形影不离地**操作同一块数据**，那么是时候组建一个类了。

+ 重构名：函数组合成类(Combin Functions into Class)
+ 替代方案：函数组合成变换

### 演变

+ 运用封装记录

### 操作

```typescript
function acquireReading() {
    return {
        customer: "ivan",
        quantity: 10,
        month: 5,
        year: 2017,
    }
}
```

```typescript
// 待重构
const aReading = acquireReading()
const base = baseRate(aReading.month, aReading.year) * aReading.quantity;
const taxableChaege = Math.max(0, base - taxThreshold(aReading.year));
```

```typescript
// 重构后：函数组合成类
class Reading {
    constructor(data) {
        this._customer = data.customer;
        this._quantity = data.quantity;
        this._month = data.month;
        this._year = data.year;
    }
    private _customer: string;
    private _quantity: number;
    private _month: number;
    private _year: number;

    get customer() { return this._customer; }
    get quantity() { return this._quantity; }
    get month() { return this._month; }
    get year() { return this._year; }

    get baseCharge(){
        return baseRate(this.month,this.year)*this.quantity
    }
    get taxableCharge(){
        return Math.max(0, this.baseCharge - taxThreshold(this.year));
    }
}
const rawReading = acquireReading()
const aReading = new Reading(rawReading);
const base = aReading.baseCharge;
const taxableChaege = aReading.taxableCharge;
```





## 函数组合成变换

> 将所有计算派生数据的逻辑收拢到一处
>
> 如果对源数据做更新，那么使用组合成类要好一些

+ 重构名：函数组合成变换(Combine Functions into Transform)
+ 替代方案：函数组合成类

### 演变

+ 数据深拷贝

### 操作

```typescript
const aReading = acquireReading()
const base = baseRate(aReading.month, aReading.year) * aReading.quantity;
const taxableCharge = Math.max(0, base - taxThreshold(aReading.year));
```

```typescript
// 先拷贝一份，再将拷贝的对象赋予所有计算的派生数据，将数据收拢。   
function enrichReading(origin:any){
    const result = Object.assign({}, origin);
    Object.defineProperty(
        result,
        "baseCharge",
        baseRate(result.month, result.year) * result.quantity    
    )
    Object.defineProperty(
        result,
        "taxableCharge",
        Math.max(0, result.baseCharge - taxThreshold(result.year)) 
    )
    return result;
}

const rawReading = acquireReading();
const aReading = enrichReading(rawReading);
const taxableCharge = aReading.taxableCharge;
```



## 拆分阶段

> 当一段代码在同时处理两件不同的事，把它拆成各自独立的模块

+ 重构名：拆分阶段(Split Phase)

### 演变

+ 引入一个中转数据结构
+ 把第一个阶段提炼成一个变换对象

### 操作

```typescript
// 待重构
function priceOrder(product, quantity, shaippingMethod) {
    const basePrice = product.basePrice * quantity;
    const discount = Math.max(quantity - product.discountThreshold, 0) *
          product.basePrice * product.discountRate;
    const shaippingPerCase = (basePrice > shaippingMethod.discountThreshold) ?
          shaippingMethod.discountFee : shaippingMethod.feePerCase;
    const shaippingCost = quantity * shaippingPerCase;
    const price = basePrice - discount + shaippingCost;
    return price;
}
```

```typescript
// 重构后
function priceOrder(product, quantity, shaippingMethod) {
    const priceData = calculatePricingData(product, quantity)
    return applyShipping(priceData, shaippingMethod)
}

function calculatePricingData(product, quantity) {
    const basePrice = product.basePrice * quantity;
    const discount = Math.max(quantity - product.discountThreshold, 0) *
          product.basePrice * product.discountRate;
    return { basePrice, quantity, discount }
}

function applyShipping(priceData, shaippingMethod) {
    const shaippingPerCase = (priceData.basePrice > shaippingMethod.discountThreshold) ?
          shaippingMethod.discountFee : priceData.shaippingMethod.feePerCase;
    const shaippingCost = priceData.quantity * shaippingPerCase;
    return priceData.basePrice - priceData.discount + shaippingCost;
}
```



# Ⅱ 封装

# Ⅲ 搬移特性

# Ⅳ 重新组织数据

# Ⅴ 简化条件逻辑

# Ⅵ 重构API

# Ⅶ 处理继承关系

