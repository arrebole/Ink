Refactoring

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
  + [封装记录](#封装记录)
  + [封装集合](#封装集合)
  + [以对象取代基本类型](#以对象取代基本类型)
  + [以查询取代临时变量](#以查询取代临时变量)
  + [提炼类](#提炼类)
  + [内联类](#内联类)
  + [隐藏委托关系](#隐藏委托关系)
  + [移除中间人](#移除中间人)
  + [替换算法](#替换算法)
+ 搬移特性
  + [搬移函数](#搬移函数)
  + [搬移字段](#搬移字段)
  + [搬移语句到函数](#搬移语句到函数)
  + [搬移语句到调用者](#搬移语句到调用者)
  + [以函数调用取代内联代码](#以函数调用取代内联代码)
  + [移动语句](#移动语句)
  + [拆分循环](#拆分循环)
  + [以管道取代循环](#以管道取代循环)
  + [移除死代码](#移除死代码)
+ 重新组织数据
  + [拆分变量](#拆分变量)
  + [字段改名](#字段改名)
  + [以查询取代派生变量](#以查询取代派生变量)
  + [将引用对象改为值对象](#将引用对象改为值对象)
  + [将值对象改为引用对象](#将值对象改为引用对象)
+ 简化条件逻辑
  + [分解条件表达式](#分解条件表达式)
  + [合并条件表达式](#合并条件表达式)
  + [以卫语句取代嵌套条件表达式](#以卫语句取代条件表达式)
  + [以多态取代条件表达式](#以多态取代条件表达式)
  + [引入特例](#引入特例)
  + [引入断言](#引入断言)
+ 重构API
  + [将查询函数与修改函数分离](#将查询函数与修改函数分离)
  + [函数参数化](#函数参数化)
  + [移除标记参数](#移除标记参数)
  + [保持对象完整](#保持对象完整)
  + [以查询取代参数](#以查询取代参数)
  + [以参数取代查询](#以参数取代查询)
  + [移除预设函数](#移除预设函数)
  + [以工厂函数取代构造函数](#以工厂函数取代构造函数)
  + [以命令取代函数](#以命令取代函数)
  + [以函数取代命令](#以函数取代命令)
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
function isExpensive(anOrder: {basePrice: number}) {
    let basePrice = anOrder.basePrice;
    return (basePrice > 10000)
}

```

```typescript
// ⭐Skill: 先将变量改为不可修改然后测试，确保变量只被修改一次
function isExpensive(anOrder: {basePrice: number}) {
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
+ 进阶—[封装记录](#封装记录)

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
// 重构：变量改名
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

## 封装记录

> 封装变量的进阶，对过长作用域的变量，进行监管控制。

+ 重构名：封装记录(Encapsulate Record)
+ Ideas：相似点（设计模式—单例模式）

### 演变

+ 先进行封装变量，再分装成类

### 操作

```typescript
const organization = { name: "Acme Gooseberries", country: "GB" }
```

```typescript
// 重构后
class Organization {
    constructor(organization: { name: string, country: string }) {
        this._name = organization.name;
        this._country = organization.country;
    }
    private _name: string
    private _country: string

    get name(): string { return this._name }
    get country(): string { return this._country }
    set name(aName: string) { this._name = aName }
    set country(aCountry: string) { this._country = aCountry }
}

const organization = new Organization({ name: "Acme Gooseberries", country: "GB" })

export function getOrganization() {
    return organization;
}
```





## 封装集合

> 避免直接操作对象的集合成员，应在对象上定义统一接口，
>
> 返回的数据应是源数据的拷贝，避免修改。

+ 重构名：封装集合(Encapsulate Collection)

### 演变

+ 先封装变量再封装集合

+ 永远不直接返回集合的值
+ 限制集合的访问权限

### 操作

```typescript
// 待重构：无封装集合操作
class Course {
    constructor(name: string) {
        this._name = name;
        this._isAdvanced = false;
    }
    private _name: string
    private _isAdvanced: boolean

    get name() { return this._name }
    get isAdvance() { return this._isAdvanced }
}
class Person {
    constructor(name: string) {
        this._name = name
        this._courses = []
    }
    private _name: string;
    private _courses: Array<Course>;

    get name() { return this._name };
    get courses() { return this._courses }
    set courses(aList: Course[]) { this._courses = aList }
}

const Bob = new Person("bob")
Bob.courses = [new Course("cs") ]//💀十分危险的行为
```

```typescript
// 重构后
class Course {
    constructor(name: string) {
        this._name = name;
        this._isAdvanced = false;
    }
    private _name: string
    private _isAdvanced: boolean

    get name() { return this._name }
    get isAdvance() { return this._isAdvanced }
}
class Person {
    constructor(name: string) {
        this._name = name
        this._courses = []
    }
    private _name: string;
    private _courses: Array<Course>;

    get name() { return this._name };
    get courses() { return this._courses.slice() }

    addCourse(aCourse:Course){
        this._courses.push(aCourse);
    }
    removeCourse(aCourse:Course){
        const index = this._courses.indexOf(aCourse);
        if(index == -1) throw new RangeError();
        else this._courses.splice(index, 1);
    }
}

const Bob = new Person("bob")
Bob.addCourse( new Course("cs"))
```



## 以对象取代基本类型

> 一旦发现对某个数据的操作不仅仅局限于打印时，就该为它创建一个新类

+ 重构名：以对象取代基本类型(Replace Primitive with Object)、以对象取代数据值

+ 反向重构：引用对象改为值对象

### 演变

+ 一开始只是简单包装一下

### 操作

```typescript
class Order {
    constructor(data: { priority: string }) {
        this.priority = data.priority
    }
    public priority: string
}

const orders = new Array<Order>();
const highPriorityCount = orders.filter(
    o => "high" === o.priority || "rush" == o.priority
).length;
```

```typescript
// 重构后
class Priority{
    constructor(value:string){
        this._value = value
    }
    private _value:string
    toString(){
        return this._value;
    }
    static legalValues(){return ["low","normal","high","rush"]}
    get _index() {return Priority.legalValues().findIndex(s=>s===this._value)}
    // 🔨骚操作：利用legalValues索引比较
    higherThan(other:Priority){return this._index > other._index}
    lowerThan(other:Priority){return this._index < other._index}
    equals(other:Priority){return this._index ==  other._index}
}
class Order {
    constructor(data: { priority: string }) {
        this._priority = new Priority(data.priority)
    }
    // priority被封装成了对象 
    private _priority: Priority
    get priority():Priority {return this._priority}
    get priorityString(){return this._priority.toString()}
    set setPriority(aString:string){this._priority = new Priority(aString)}
}

const orders = new Array<Order>();
const highPriorityCount = orders.filter(o=>o.priority.higherThan(new Priority("normal")))
```







## 以查询取代临时变量

> 用于处理那些只被计算一次且之后不再被修改的变量
>
> 应用内联变量手法移除临时变量

+ 重构名：以查询取代临时变量(Replace Temp with Query)

### 演算

+ 将变量赋值的代码段提炼成函数
+ 应用内联变量手法移除临时变量

### 操作

```typescript
class Order {
    constructor(quantity: number, item: { price: number }) {
        this.quantity = quantity;
        this.item = item;
    }
    private quantity: number
    private item: { price: number }

    get price() {
        let basePrice = this.quantity * this.item.price;
        let discountFactory = 0.98;
        if (basePrice > 1000) discountFactory -= 0.03;
        return basePrice * discountFactory;
    }
}
```

```typescript
class Order {
    constructor(quantity: number, item: { price: number }) {
        this.quantity = quantity;
        this.item = item;
    }
    private quantity: number
    private item: { price: number }

    get basePrice() {
        return this.quantity * this.item.price;
    }
    get discountFactory() {
        return (this.basePrice > 1000) ? 0.98 - 0.03 : 0.98;
    }
    get price() {
        return this.basePrice * this.discountFactory;
    }
}
```



## 提炼类

> 一个类应该是一个清晰的抽象，只处理一些明确的责任
>
> 如果某些数据和某些函数总是关联出现，，那么可以考虑分离出去

+ 重构名：提炼类(Extract Class)
+ 反向重构: 内联类
+ ideas：设计模式原则—单一职责

### 演算

+ 通过组合的手法解耦合

### 操作

```typescript
class Person {
    private _name: string;
    private _officeAreaCode: string;
    private _officeNumber: string;

    public get name(): string {
        return this._name;
    }
    public set name(v: string) {
        this._name = v;
    }
    public get officeAreaCode(): string {
        return this._officeAreaCode;
    }
    public set officeAreaCode(v: string) {
        this._officeAreaCode = v;
    }
    public get officeNumber(): string {
        return this._officeNumber;
    }
    public set officeNumber(v: string) {
        this._officeNumber = v;
    }
    public get telephoneNumber(): string {
        return `(${this.officeAreaCode}) ${this.officeNumber}`;
    }
}
```

```typescript
class TelephoneNumber{
    private _areaCode: string;
    private _number: string;

    public get areaCode(): string {
        return this._areaCode;
    }
    public set areaCode(v: string) {
        this._areaCode = v;
    }
    public get number(): string {
        return this._number;
    }
    public set number(v: string) {
        this._number = v;
    }
    public get toString(): string {
        return `(${this.areaCode}) ${this.number}`;
    }
}

class Person {
    constructor(){
        this._telephoneNumber = new TelephoneNumber();
    }
    private _name: string;
    private _telephoneNumber:TelephoneNumber;

    public get name(): string {
        return this._name;
    }
    public set name(v: string) {
        this._name = v;
    }
    public get officeAreaCode(): string {
        return this._telephoneNumber.areaCode;
    }
    public set officeAreaCode(v: string) {
        this._telephoneNumber.areaCode = v;
    }
    public get officeNumber(): string {
        return this._telephoneNumber.number;
    }
    public set officeNumber(v: string) {
        this._telephoneNumber.number = v;
    }
    public get telephoneNumber(): string {
        return this._telephoneNumber.toString
    }
}
```







## 内联类

> 如果一个类不再承担足够责任，不再有单独存在的道理，将萎缩类塞进另一个类中
>
> 如果是想重新安排它们的职责，先内联类再提炼类

+ 重构名：内联类(Inline Class)
+ 反向重构：提炼类

### 演算

+ 先内联类再提炼类，重新组织类的关系

### 操作

```typescript
class TrackingInfomation {
    private _shippingCompany: string;
    private _trackingNumber: string;

    public get shippingCompany(): string {
        return this._shippingCompany;
    }
    public set shippingCompany(v: string) {
        this._shippingCompany = v;
    }
    public get trackingNumber(): string {
        return this._trackingNumber;
    }
    public set trackingNumber(v: string) {
        this._trackingNumber = v;
    }

    get display() {
        return `${this.shippingCompany}: ${this.trackingNumber}`
    }
}

class Shipment {
    private _TrackingInfomation: TrackingInfomation;
    public get TrackingInfomation(): TrackingInfomation {
        return this._TrackingInfomation;
    }
    public set TrackingInfomation(v: TrackingInfomation) {
        this._TrackingInfomation = v;
    }
    get trackingInfo() {
        return this._TrackingInfomation.display;
    }
}
```

```typescript
class Shipment {
    private _shippingCompany: string;
    private _trackingNumber: string;

    public get shippingCompany(): string {
        return this._shippingCompany;
    }
    public set shippingCompany(v: string) {
        this._shippingCompany = v;
    }
    public get trackingNumber(): string {
        return this._trackingNumber;
    }
    public set trackingNumber(v: string) {
        this._trackingNumber = v;
    }

    get trackingInfo() {
        return `${this.shippingCompany}: ${this.trackingNumber}`
    }
}
```



## 隐藏委托关系

> 在服务对象上放置一个简单的委托函数，将委托关系隐藏起来。
>
> 隐藏自己的字段

+ 重构名：隐藏委托关系(Hide Delegate)
+ 反向重构：移除中间人
+ ideas: 设计模式-中介模式

### 演算

+ 间接调用内部对象

### 操作

```typescript
class Department {
    private _chargeCode: string;
    private _manager: string;

    public get chargeCode(): string {
        return this._chargeCode;
    }
    public set chargeCode(v: string) {
        this._chargeCode = v;
    }

    public get manager(): string {
        return this._manager;
    }
    public set manager(v: string) {
        this._manager = v;
    }
}

class Person {
    constructor() {
        this._department = new Department();
    }
    private _department: Department;
    public get department(): Department {
        return this._department;
    }
    public set department(v: Department) {
        this._department = v;
    }
}

const aPerson = new Person();
let manger = aPerson.department.manager
```



``` typescript
class Department {
    private _chargeCode: string;
    private _manager: string;
    
    public get chargeCode(): string {
        return this._chargeCode;
    }
    public set chargeCode(v: string) {
        this._chargeCode = v;
    }
    public get manager(): string {
        return this._manager;
    }
    public set manager(v: string) {
        this._manager = v;
    }
}

class Person {
    constructor() {
        this._department = new Department();
    }
    private _department: Department;
    public get department(): Department {
        return this._department;
    }
    public set department(v: Department) {
        this._department = v;
    }
	// 实现委托
    public get manager(){
        return this.department.manager
    }
}

const aPerson = new Person();
let manger = aPerson.manager;
```



## 移除中间人

> 随着委托类的特征（功能）越来越多，更多的转发函数就会使人烦躁。
>
> 此时就应该让客户直接调用受托类

+ 重构名：移除中间人(Remove Middle Man)

- 反向重构：隐藏委托关系(Hide Delegate)

### 演算

+ 去除委托函数

```typescript
class Department {
    private _chargeCode: string;
    private _manager: string;
    
    public get chargeCode(): string {
        return this._chargeCode;
    }
    public set chargeCode(v: string) {
        this._chargeCode = v;
    }
    public get manager(): string {
        return this._manager;
    }
    public set manager(v: string) {
        this._manager = v;
    }
}

class Person {
    constructor() {
        this._department = new Department();
    }
    private _department: Department;
    public get department(): Department {
        return this._department;
    }
    public set department(v: Department) {
        this._department = v;
    }
	// 实现委托
    public get manager(){
        return this.department.manager
    }
}

const aPerson = new Person();
let manger = aPerson.manager;
```

```typescript
class Department {
    private _chargeCode: string;
    private _manager: string;

    public get chargeCode(): string {
        return this._chargeCode;
    }
    public set chargeCode(v: string) {
        this._chargeCode = v;
    }

    public get manager(): string {
        return this._manager;
    }
    public set manager(v: string) {
        this._manager = v;
    }
}

class Person {
    constructor() {
        this._department = new Department();
    }
    private _department: Department;
    public get department(): Department {
        return this._department;
    }
    public set department(v: Department) {
        this._department = v;
    }
}

const aPerson = new Person();
let manger = aPerson.department.manager
```



## 替换算法

> 其中某些方法会比另一些简单，算法也是如此。
>
> 此时就需要改变原先的算法。

+ 重构名：替换算法(Substitute Algorithm)

### 演变

+ 判断点：性能、简洁

### 操作

```typescript
function foundPerson(people: string[]) {
    for (let i = 0; i < people.length; i++) {
        if (people[i] == "Don") {
            return "Don"
        }
        if (people[i] == "John") {
            return "John"
        }
        if (people[i] == "Kent") {
            return "Kent"
        }
    }
    return "";
}
```

```typescript
// 管道替换循环
function foundPerson(people: string[]) {
    const candidates = ["Don","John","Kent"];
    return people.find(p =>candidates.includes(p)) || "";
}
```





# Ⅲ 搬移特性

## 搬移函数

> 任何函数都需要具备上下文环境才能存活
>
> 需要频繁调用一个别处的函数，会考虑搬移这个函数

+ 重构名：搬移函数(Move Function)

### 演算

+ 检查函数上下文与目标上下文的区别

```typescript
class AccountType { }
class Account {
    private daysOverdrawn: number
    private type: { isPremium: boolean }
    get bankCharge() {
        let result = 4.5;
        if (this.daysOverdrawn > 0) result += this.overdraftCharge;
        return result;
    }
    get overdraftCharge() {
        if (this.type.isPremium) {
            const baseCharge = 10;
            if (this.daysOverdrawn <= 7) {
                return baseCharge;
            } else {
                return baseCharge + (this.daysOverdrawn - 7) * 0.85;
            }

        }
        else return this.daysOverdrawn * 1.75
    }
}
```

```typescript
// 重构：搬移函数
class Account {
    daysOverdrawn: number;
    isPremium: boolean;
    type: AccountType;
    get bankCharge() {
        let result = 4.5;
        if (this.daysOverdrawn > 0) result += this.overdraftCharge;
        return result;
    }
    get overdraftCharge() {
        return this.type.overdraftCharge(this)
    }
}
class AccountType {
    overdraftCharge(aAccount: Account) {
        if (aAccount.isPremium) {
            const baseCharge = 10;
            if (aAccount.daysOverdrawn <= 7) {
                return baseCharge;
            } else {
                return baseCharge + (aAccount.daysOverdrawn - 7) * 0.85;
            }

        }
        else return aAccount.daysOverdrawn * 1.75
    }
}
```



## 搬移字段

> 良好的数据结构，会让代码变得简单
>
> 如果发现数据结构已经不适应于需求，就应该马上修缮它

+ 重构名：搬移字段(Move Field)

### 演算

+ 移动裸记录

### 操作

```typescript
class Customer{
    constructor(name:string,discountRate:number){
        this._name = name;
        this._discountRate = discountRate;
        this._contract = new CustomerContract(Date.now().toString())
    }
    private _name:string;
    private _discountRate:number
    private _contract:CustomerContract

}
class CustomerContract{
    private _startData:string
    constructor(startData:string){
        this._startData = startData
    }
}
```

```typescript
class Customer{
    constructor(name:string,discountRate:number){
        this._name = name;
        this._contract = new CustomerContract(Date.now().toString())
        this._setDiscountRate(discountRate);
    }
    private _name:string;
    private _contract:CustomerContract
    get discountRate(){return this._contract.discountRate}
    _setDiscountRate(arg:number){this._contract.discountRate = arg}

}
class CustomerContract{
    private _startData:string
    private _discountRate:number;
    constructor(startData:string){
        this._startData = startData
    }
    set discountRate(arg:number){this._discountRate = arg}
    get discountRate(){return this._discountRate}
}
```



## 搬移语句到函数

> 调用某个函数时，总有一些相同的代码需要每次执行
>
> 会考虑将这些代码合并到函数里头

+ 重构名：搬移语句到函数(Move Statements into Function)
+ 反向重构; 移动语句到调用者

### 演算

+ 如果调用有些距离、先用移动语句

### 操作

```typescript
class Photo{
    title:string
    location:string
    date:Date
}
class Person{
    photo:Photo
}
function renderPerson(person:Person){
    let result = new Array<string>();
    result.push(`<p>title: ${person.photo.title}</p>`)
    result.concat(photoData(person.photo))
    return result.join("\n");
}
function photoData(aPhoto:Photo){
    return[
        `<p>location: ${aPhoto.location}</p>`,
        `<p>date: ${aPhoto.date.toDateString()}</p>`
    ]
}
```

```typescript
// 重构后
class Photo{
    title:string
    location:string
    date:Date
}
class Person{
    photo:Photo
}
function renderPerson(person:Person){
    let result = new Array<string>();
    result.concat(photoData(person.photo))
    return result.join("\n");
}
function photoData(aPhoto:Photo){
    return[
        `<p>title: ${aPhoto.title}</p>`,
        `<p>location: ${aPhoto.location}</p>`,
        `<p>date: ${aPhoto.date.toDateString()}</p>`
    ]
}
```





## 搬移语句到调用者

> 函数边界发生偏移，如今需要在某些调用点面前表现不同的行为
>
> 把不同的行为从函数里挪出，并搬移到其调用处

+ 重构名：搬移语句到调用者(Move Statements to Callers)
+ 反向重构: 搬移语句到函数

### 演算

+ 若调用点不止一两个，需要把不需要搬移的代码提炼函数

### 操作

```typescript
class Photo {
    title: string
    location: string
    date: Date
}
class Person {
    photo: Photo
}
function renderPerson(person: Person) {
    let result = new Array<string>();
    result.concat(photoData(person.photo))
    return result.join("\n");
}
function photoData(aPhoto: Photo) {
    return [
        `<p>title: ${aPhoto.title}</p>`,
        `<p>location: ${aPhoto.location}</p>`,
        `<p>date: ${aPhoto.date.toDateString()}</p>`
    ]
}
```

```typescript
class Photo {
    title: string
    location: string
    date: Date
}
class Person {
    photo: Photo
}
function renderPerson(person: Person) {
    let result = new Array<string>();
    result.push(`<p>title: ${person.photo.title}</p>`)
    result.concat(photoData(person.photo))
    return result.join("\n");
}
function photoData(aPhoto: Photo) {
    return [
        `<p>location: ${aPhoto.location}</p>`,
        `<p>date: ${aPhoto.date.toDateString()}</p>`
    ]
}
```



## 以函数调用取代内联代码

> 将内联代码替代为对一个既有函数的调用

+ 重构名：以函数调用取代内联代码(Replace Inline code with Function Call)

### 演算

+ 优先使用标准库内的函数

### 操作

```typescript
function isAppliesToMass(states: string[]) {
    let appliesToMass = false;
    for (const s of states) {
        if (s == "MA") appliesToMass = true;
    }
    return appliesToMass;
}
```

```typescript
function isAppliesToMass(states: string[]) {
    return states.includes("MA");
}
```



## 移动语句

> 让存在关联的东西一起出现，可以使代码更容易理解

+ 重构名：移动语句(Slide Statements)、合并重复的代码片段

### 演算

+ 确定待移动的代码片段应该被搬往何处。
+ 条件逻辑的移动

### 操作

```typescript
const pricingPlan = retrievePricingPlan()
const order = retrieveOrder()
let charge;
const chargePerUnit = pricingPlan.unit;
```

```typescript
const pricingPlan = retrievePricingPlan()
const chargePerUnit = pricingPlan.unit;
const order = retrieveOrder()
let charge;
```



## 拆分循环

> 让一个循环只做一件事情

+ 重构名：拆分循环(Split Loop)

### 演算

+ 循环拆分后，考虑对得到的循环提炼函数

### 操作

```typescript
let youngest = people[0] ? people[0].age : Infinity;
let totalSalary = 0;
for (const p of people) {
    if (p.age < youngest) youngest = p.age;
    totalSalary += p.salary;
}
let result = `youngestAge:${youngest},totalSalary: ${totalSalary}`;
```

```typescript
function totalSalary(){
    let result = 0;
    for(const p of people){
        result += p.salary;
    }
    return result;
}
function youngest(){
    let result = people[0]?people[0].age: Infinity;
    for(const p of people){
        if(p.age < result) result = p.age;
    }
    return result;
}
let result = `youngestAge:${youngest},totalSalary: ${totalSalary}`;
```



## 以管道取代循环

> 运用集合管道来处理循环

+ 重构名：以管道取代循环(Replace Loop with Pipeline)

### 操作

+ 流式操作

### 操作

```typescript
function totalSalary(){
    let result = 0;
    for(const p of people){
        result += p.salary;
    }
    return result;
}
function youngest(){
    let result = people[0]?people[0].age: Infinity;
    for(const p of people){
        if(p.age < result) result = p.age;
    }
    return result;
}

let result = `youngestAge:${youngest()},totalSalary: ${totalSalary()}`;
```

```typescript
function totalSalary(){
    return people.reduce((total,p)=>total+=p.salary,0)
}
function youngest(){
    return Math.max(...people.map(p=>p.age))
}

let result = `youngestAge:${youngest()},totalSalary: ${totalSalary()}`;
```



## 移除死代码

> 一旦代码不再被使用，我们就该立马删除它

+ 重构名：移除死代码(Remove Dead Code)

### 演算

+ 版本控制器

### 操作

```typescript
let noUsed = 0;
function doSomeThing(){}
```

```typescript

```



# Ⅳ 重新组织数据

## 拆分变量

> 某些用途会很自然地导致临时变量被多次赋值，多次赋值会催生多种bug
>
> 拆分变量用于拆解多次赋值的临时变量

+ 重构名：拆分变量(Split Variable)、分解临时变量

### 演算

+ 对输入参数赋值

### 操作

```typescript
let temp = 2 * (height + width)
console.log(temp);
temp = height * width;
console.log(temp);
```

```typescript
const perimeter = 2 * (height + width);
console.log(perimeter);
const area = height * width;
console.log(area)
```



## 字段改名

> 记录结构中的字段可能需要改名，类的字段也一样

+ 重构名：字段改名(Rename Field)

### 演算

+ 给字段改名

### 操作

```typescript
class Organization{
    name:string
}
```

```typescript
// 字段改名
class Organization{
    title:string
}
```



## 以查询取代派生变量

> 对数据的修改常常导致代码的各个部分以丑陋的形式相互耦合
>
> 很多时候，完全可以去掉可变数据并不实现

+ 重构名：以查询取代临时变量(Replace Derived Variable with Query)

### 演算

+ 引入断言

### 操作

```typescript
class Production{
    private _discountedTotal:number
    private _discount:number
    get discountedTotal(){
        return this._discountedTotal;
    }
    set discountedTotal(aNumber:number){
        const old = this._discount;
        this._discount = aNumber;
        this._discountedTotal += old - aNumber;
    }
}
```

```typescript
class Production{
    private _discount:number
    private _baseTotal:number
    get discountedTotal(){
        return this._baseTotal - this._discount;
    }
    set discountedTotal(aNumber:number){
        this._discount = aNumber;
    }
}
```



## 将引用对象改为值对象

> 位于内部的对象可以视为引用对象也可以视为值对象，值对象可以随意复制
>
> 其视为值对象，就会替换整个内部对象                                                                                                                                                                                                                        

+ 重构名：将引用对象改为值对象(Change Reference to Value)
+ 反向重构：将值对象改为引用对象

### 演算

+ 分布式系统和并发系统常用

### 操作

```typescript
class Product{
    _price:Price
    applyDiscount(arg:number){
        this._price.amount -= arg;
    }
}
```

```typescript
class Product{
    _price:Price
    applyDiscount(arg:number){
        this._price = new Price(this._price.amount - arg)
    }
}
```



## 将值对象改为引用对象

> 位于内部的对象可以视为引用对象也可以视为值对象，引用对象用于共享对象
>
> 其视为应用对象，只更新其属性    

+ 重构名：将值对象改为引用对象(Change Value to Reference)

+ 反向重构：将引用对象改为值对象(Change Reference to Value)

### 演算

+ 对象共享

### 操作

```typescript
class Product{
    _price:Price
    applyDiscount(arg:number){
        this._price = new Price(this._price.amount - arg)
    }
}
```

```typescript
class Product{
    _price:Price
    applyDiscount(arg:number){
        this._price.amount -= arg;
    }
}
```





# Ⅴ 简化条件逻辑

## 分解条件表达式

> 条件逻辑会使代码更难阅读。
>
> 将复杂的条件逻辑分解为多个独立的函数。它是提炼函数的一个应用场景

+ 重构名：分解条件表达式(Decompose Conditional)

### 演算

+ 分支条件分解为新函数

### 操作

```typescript
if (!aDate.isBefore(plan.summerStart) && aDate.isAfter(plan.summerEnd))
    charge = quantity * plan.summerRate;
else
    charge = quantity * plan.regularRate + plan.regularServiceChargr;
```

```typescript
// 重构后
charge = summer() ? summerCharge() : regularCharge()

function summer() {
    return !aDate.isBefore(plan.summerStart) && aDate.isAfter(plan.summerEnd);
}
function summerCharge() {
    return quantity * plan.summerRate;
}
function regularCharge() {
    return quantity * plan.regularRate + plan.regularServiceChargr;
}
```



## 合并条件表达式

> 检查条件各不相同，最终行为却一致，就应该用逻辑或、逻辑与
>
> 将它们合并为一个条件表达式

+ 重构名：合并条件表达式(Consolidate Conditional Expression)

### 演算

+ 如果检查间彼此独立就不该合并

### 操作

```typescript
function disabilityAmount() {
    if (anEmployee.seniority < 2) return 0;
    if (anEmployee.monthsDisabled > 12) return 0;
    if (anEmployee.isPartTime) return 0;
    return 1;
}
```

```typescript
// 重构后
function disabilityAmount() {
    if (isNotEligibleForDisability()) return 0;
    return 1;
}
function isNotEligibleForDisability() {
    return (anEmployee.seniority < 2)
    || (anEmployee.monthsDisabled > 12)
    || (anEmployee.isPartTime);
}
```



## 以卫语句取代嵌套条件表达式

> 条件风格为、只有一条分支是正常行为，另一个是异常情况
>
> 如果某个条件极其罕见，就应该单独检查该条件，并在该条件为真时立即从函数中返回

+ 重构名：以卫语句取代嵌套条件表达式(Replace Nested Conditional with Guard Clauses)

### 演算

### 操作

```typescript
function adjustedCapital(anInstrument: Instrument) {
    let result = 0;
    if (anInstrument.capital > 0) {
        if (anInstrument.interestRate > 0 && anInstrument.duration > 0) {
            result = (anInstrument.income / anInstrument.duration) 
                * anInstrument.adjusementFactor;
        }
    }
    return result;
}
```

```typescript
// 重构后
function adjustedCapital(anInstrument: Instrument) {
    if ( anInstrument.capital          <= 0
        || anInstrument.interestRate   <= 0
        || anInstrument.duration       <= 0 ) return 0;
    
    return (anInstrument.income / anInstrument.duration) 
        * anInstrument.adjusementFactor;
}
```



## 以多态取代条件表达式

> 面对复杂条件逻辑，多态是改善这种情况的有力工具

+ 重构名：以多态取代条件表达式(Replace Conditional with Polymorphism)

### 演算

+ 多态处理变体逻辑

### 操作

```typescript
type birdData = {
    type: string,
    numberOfCocnuts: number,
    voltage: number,
    isNailed: boolean,
    name:string
}

function plumages(birfs: birdData[]) {
    return new Map(birfs.map(b => [b.name, plumage(b)]))
}
function speeds(birfs: birdData[]) {
    return new Map(birfs.map(b => [b.name, airSpeedVelocity(b)]))
}
function plumage(birfs: birdData) {
    switch (birfs.type) {
        case "EuropeanSwallow":
            return "average";
        case "AfricanSwallow":
            return (birfs.numberOfCocnuts > 2) ? "tired" : "average";
        case "NorwegianBlueParrot":
            return (birfs.voltage > 100) ? "scorched" : "beautiful";
        default:
            return "unknown";
    }
}
function airSpeedVelocity(birfs: birdData) {
    switch (birfs.type) {
        case "EuropeanSwallow":
            return 35;
        case "AfricanSwallow":
            return 40 - 2 * birfs.numberOfCocnuts;
        case "NorwegianBlueParrot":
            return (birfs.isNailed) ? 0 : 10 + birfs.voltage / 10;
        default:
            return null;
    }
}
```



```typescript
// 重构后
type birdData = {
    type: string,
    numberOfCocnuts: number,
    voltage: number,
    isNailed: boolean,
    name:string
}
abstract class Bird {
    constructor(birdObj: birdData) {
        this.name = birdObj.name
        this.type = birdObj.type
        this.numberOfCocnuts = birdObj.numberOfCocnuts
        this.voltage = birdObj.voltage
    }
    name: string;
    type: string;
    numberOfCocnuts: number;
    voltage: number;
    isNailed: boolean;
    abstract get plumage(): string;
    abstract get airSpeedVelocity(): number;
}
class EuropeanSwallow extends Bird {
    get plumage(): string {
        return "average";
    }
    get airSpeedVelocity(): number {
        return 35;
    }
}
class AfricanSwallow extends Bird {
    get plumage(): string {
        return (this.numberOfCocnuts > 2) ? "tired" : "average";
    }
    get airSpeedVelocity(): number {
        return 40 - 2 * this.numberOfCocnuts;
    }
}
class NorwegianBlueParrot extends Bird {
    get plumage(): string {
        return (this.voltage > 100) ? "scorched" : "beautiful";
    }
    get airSpeedVelocity(): number {
        return (this.isNailed) ? 0 : 10 + this.voltage / 10;
    }
}

function createBird(bird: birdData): Bird {
    switch (bird.type) {
        case "EuropeanSwallow":
            return new EuropeanSwallow(bird);
        case "AfricanSwallow":
            return new AfricanSwallow(bird);
        case "NorwegianBlueParrot":
            return new NorwegianBlueParrot(bird);
        default:
            throw new Error("error");
    }
}

function plumages(birds: birdData[]) {
    return new Map(birds
                   .map(b => createBird(b))
                   .map(bird => [bird.name, bird.plumage]))
}

function speeds(birds: birdData[]) {
    return new Map(birds
                   .map(b => createBird(b))
                   .map(bird => [bird.name, bird.airSpeedVelocity]))
}
```



## 引入特例

> 代码中有对多处以同样方式应对同一个特殊值，使用特例模式
>
> 创建特例元素，用函数调用取代特例检查

+ 重构名: 引入特例(Introduce Special Case)

### 演算

+ 使用对象字面量
+ 使用变换

### 操作

```typescript
class Site {
    customer: Customer
}
class Customer {
    _name: string
    get name() { return this._name }
}

let aCustomer = site.customer;
if (aCustomer.name == "unknown") {

}
```

```typescript
function isUnkown(arg: { isUnkown(): boolean }) {
        return arg.isUnkown()
    }
class Site {
    customer: Customer
}
class Customer {
    _name: string
    get name() { return this._name }
    isUnkown() {
        return false;
    }
}
function createUnkownCustomer() {
    return {
        name: "isUnkown",
        isUnkown() {
            return true;
        }
    }
}

let aCustomer = site.customer;
if (isUnkown(aCustomer)) {
    //...
}
```





## 引入断言

> 断言是一个条件表达式，应该总是为真，
>
> 断言是帮助追踪bug的最后一招，在断言绝对不会失败的时候，才会使用

+ 重构名：引入断言(Introduce Assertion)

### 演算

+ 使用断言明确标明这些假设

### 操作

```typescript
class Customer {
    private _discountRate: number
    set discountRate(aNumber: number) {
        this._discountRate = aNumber
    }
    applyDiscount(aNumber: number) {
        return (this._discountRate)
            ? aNumber - (this._discountRate * aNumber)
        : aNumber
    }
}
```

```typescript
class Customer {
    private _discountRate: number
    set discountRate(aNumber: number) {
        console.assert(aNumber == null || aNumber >= 0, "assert fail")
        this._discountRate = aNumber
    }
    applyDiscount(aNumber: number) {
        console.assert(this._discountRate >= 0, "assert fail")
        return aNumber - (this.discountRate * aNumber)

    }
}
```





# Ⅵ 重构API

# Ⅶ 处理继承关系

