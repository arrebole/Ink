# 语言特性



- version:  0.0.1

- update: 2018-7-15





#### (一) 变量声明



c 变量声明方法

| 方法              | 例如           |      注释      |
| :---------------- | -------------- | :------------: |
| type 名称         | int a          |    声明变量    |
| type 名称 =  内容 | int a = 1      | 声明变量并赋值 |
| const type = 内容 | const int a =1 | 声明常量并赋值 |



java 变量声明

| 方法                   | 例如           | 注释                     |
| ---------------------- | -------------- | ------------------------ |
| type 名称              | int a          | 变量声明                 |
| type 名称 = 内容       | int a =1       | 声明变量并赋值           |
| var 名称 type          | var a int      | 声明变量( java 10 )      |
| var 名称 = 内容        | var a = 1      | 声明变量并赋值( java 10) |
| final 名称 type = 内容 | final a int =1 | 声明常量并赋值           |



c# 变量声明

| 方法              | 例如           | 注释                    |
| ----------------- | -------------- | ----------------------- |
| type 名称         | int a          | 声明变量                |
| type 名称 =  内容 | int a = 1      | 声明变量并赋值          |
| var 名称          | var a int      | 声明变量( c# 3.5 )      |
| var 名称 = 内容   | var a = 1      | 声明变量并赋值( c# 3.5) |
| const type = 内容 | const int a =1 | 声明常量并赋值          |



go 变量声明方法

| 方法                   | 例如             | 注释                         |
| ---------------------- | ---------------- | ---------------------------- |
| var 名称 type          | var a int        | 声明变量使用默认值           |
| var 名称 (type) = 内容 | var a  (int) = 1 | 声明变量并赋值(type一般省略) |
| 名称 := 内容           | a := 1           | 声明变量并赋值               |
| const 名称 = 内容      | const a = 1      | 声明常量并赋值               |



javascript 变量声明

| 方法              | 例如       | 注释                                      |
| ----------------- | ---------- | ----------------------------------------- |
| var 名称          | var a      | 声明变量                                  |
| var 名称 = 内容   | var a=1    | 声明变量并赋值                            |
| let 名称          | let a      | 声明变量(无变量提升 块级作用域 es6)       |
| let 名称 = 内容   | let a=1    | 声明变量并赋值(无变量提升 块级作用域 es6) |
| const 名称 = 内容 | const a =1 | 声明常量并赋值 (无变量提升 es6)           |



python 变量声明

| 方法        | 例如 | 注释         |
| ----------- | ---- | ------------ |
| 名称 = 内容 | a =1 | 无需显性声明 |







#### (二) 数据类型

#####  c 基本数据类型

| 整型           | 容量         | 转换             | 注释         |
| -------------- | -----------  ---- | ---------------- | ------------ |
| short          | 2 B (16bit)     | (short)          | 短整型       |
| int            | 4 B (32bit)  | (int)            | 整型         |
| long           | 8 B (64bit)       | (long)           | 长整型       |
| unsigned short | 2 B (16bit)      | (unsigned short) | 无符号短整型 |
| unsigned int   | 4 B (32bit)      | (unsigned int)   | 无符号整型   |
| unsigned long  | 8 B (64bit)       | (unsigned long)  | 无符号长整型 |



| 字符          | 容量          | 注释   |
| ------------- | ---------  ---------- | ------ |
| char          | 1 B(8bit) | 一字节 |
| unsigned char | 1 B(8bit) | 无符号 一字节 |
| signed char   | 1 B(8bit) | char 默认为char |



| 浮点型      | 容量         | 范围                        | 转换          | 注释         |
| ----------- | ------------ | --------------------------- | ------------- | ------------ |
| float       | 4 B (32bit)  | 3.40282e+038 ~ 1.17549e-038 | (float)       | 单精度浮点型 |
| double      | 8 B (64 bit) | 1.79769e+308 ~ 2.22507e-308 | (double)      | 双精度浮点型 |
| long double | \            | \                           | (long double) | 取决编译器   |



| 布尔型 | 注释 |
| ------ | ---- |
| ture   | 真   |
| false  | 假   |



| 构造类型 | 注释     |
| -------- | -------- |
| array    | 数组     |
| struct   | 结构体   |
| union    | 共用体   |
| enum     | 枚举类型 |



| 指针类型  |      |
| --------- | ---- |
| char *p   |      |
| int *p    |      |
| float *p  |      |
| double *p |      |
| struct *p |      |







##### java 数据类型

| 整型      | 容量 |      |
| --------- | ---- | ---- |
| byte  | 1B (8bit) |      |
| short | 2 B (16bit) |      |
| int   | 4 B (32bit) |      |
| long  | 8B (64bit) |      |



| 浮点   | 容量         |      |
| ------ | ------------ | ---- |
| float  | 4 B (32 bit) |      |
| double | 8 B (64 bit) |      |



| boolean |            |
| ------- | ----  ---- |
| ture    |            |
| false   |            |



| 字符 | 容量         | 注释               |
| ---- | ------------ | ------------------ |
| char | 2 B (16 bit) | 16 位 Unicode 字符 |



| 字符串        |         | 注释     |
| ------------- | ------- | -------- |
| String        | final类 |          |
| StringBuffer  |         | 线程安全 |
| StringBuilder |         | 速度快   |





##### c# 数据类型

| 整型  | 容量        |      |
| ----- | ----------- | ---- |
| byte  | 1B (8bit)   |      |
| short | 2 B (16bit) |      |
| int   | 4 B (32bit) |      |
| long  | 8B (64bit)  |      |



| 浮点   | 容量         |      |
| ------ | ------------ | ---- |
| float  | 4 B (32 bit) |      |
| double | 8 B (64 bit) |      |



| boolean |      |
| ------- | ---- |
| ture    |      |
| false   |      |



| 字符 | 容量         | 注释               |
| ---- | ------------ | ------------------ |
| char | 2 B (16 bit) | 16 位 Unicode 字符 |



| 字符串        |         | 注释     |
| ------------- | ------- | -------- |
| String        | final类 |          |
| StringBuffer  |         | 线程安全 |
| StringBuilder |         | 速度快   |



##### go数据类型



##### python数据类型

| type       | 转换            |      |      |
| ---------- | --------------- | ---- | ---- |
| int    | int(x [,base]) |      |      |
| float    | float(x) |      |      |
| complex    | complex(real ,imag) |      |      |
| String     | str()           |      |      |
| boolean    |                 |      |      |
| List       | list((1,2,3,4)) |      |      |
| Tuple      | tuple(seq) |      |      |
| Set        | set(s) |      |      |
| Dictionary |                 |      |      |








#### (三) 循环



c 循环

```c
// <for 基本循环>
for(int i=0;i<10;i++){
    //代码语句
}
```



java 循环

```java
// <for 基本循环>
for(int i=0; i<100;i++) {
    //代码语句
}
// <for 增强循环>
// for(声明语句 : 表达式)
String [] names ={"James", "Larry", "Tom", "Lacy"};
for( String name : names ) {
    System.out.print( name );
}
```



c# 循环

```c#
// <for 基本循环>
for (int i=0; i<100;i++){
    //代码语句
}
// <foreach 循环>
foreach(var item in collection){
    //代码语句
}

```





go 循环

```go
// <for 基本循环>
for i :=0; i<10; i++{
     //代码语句
}
// <for rang>
for key, value := range oldMap {
     //代码语句

```



python 循环

```python
# <for in 基本循环>
for value in 'Python':     
   print ('当前字母 :', value)

# <for in range(start,end)> 
#  用于循环数字
for num in range(10,20):
    print('当前数字 :', num)
```



javascript 循环

```javascript
// <for 基本循环>
for(let i=0;i<n;i++){
     //代码语句
}

// <for in>
for(let index in array) {
     //代码语句
};

// <for of (es6)>
// 用于数组,重点获取value
for(let value of array) {
     //代码语句
};

// <forEach> 
//数组的方法,对每一项执行回调函数
array.forEach((value)=> {
	 //代码语句
});
```

