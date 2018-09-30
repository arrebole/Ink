# 数据类型

## c 语言

#### 基本类型

+ 有符号整型： short， int， log， log log
+ 无符号整型： unsigned short，unsigned int，unsigned log，unsigned log log
+ 字符类型： char
+ 浮点类型：float，double，log double
+ 指针类型：type *

+ 数组 ： [ ]
+ 结构体：struck
+ 共用体：union



## c++ 语言
#### 基本类型

+ 有符号整型： short， int， log， log log
+ 无符号整型： unsigned short，unsigned int，unsigned log，unsigned log log
+ 字符类型： char
+ 字符串: string
+ 浮点类型：float，double，log double
+ 指针类型：type *
+ 布尔型：ture，false
+ **引用类型：type &name**

+ 数组 ： [ ]
+ 结构体：struck
+ 共用体：union
+ 类：class

#### 扩展类型

+ 向量：vector （动态数组，长度可变 ）
+ 链表：list （双向链表 ）
+ 映射：map 

#### 操作

>字符串转整型 string atoi(const char *_Str)

```c++
string str = "123"
int intTest = atoi(str.c_str());
```



## go 语言

#### 基本类型

+ 有符号整型： int8，int16，int32，int64 （int=int8）
+ 无符号整型： uint8，uint16，uint32，uint64
+ 字符类型： byte，rune
+ 字符串：string
+ 浮点类型：float32，float64，**complex64**，**complex128** 
+ 指针类型：*type，**uintptr** 

+ 数组 ： [ ]
+ **切片**（引用类型）：[ ] （动态数组，长度可变 ）
+ 映射（引用类型）：map
+ 结构体：struck
+ 管道（引用类型）：chan
+ 接口：interface



## Java 语言

#### 基本类型

+ 有符号整型：  byte，short，int，log
+ 字符类型： char
+ 浮点类型：float，double
+ 布尔型：ture，false

+ 数组 ： [ ]
+ 类：class
+ 接口：interface

#### 扩展类型

+ 字符串类型：string（不可变），stringbuffer（可变），stringbuilder（可变）
+ 映射类（map）：HashMap ，LinkedHashMap ，TreeMap 
+ 列表类（list）：ArrayList（数组结构） ，LinkedList（链表结构） 
+ 向量类：Vector（自动增长的对象数组）



## c# 语言
#### 基本类型

+ 有符号整型：  byte，short，int，log
+ 字符类型： char
+ 浮点类型：float，double
+ 布尔型：ture，false

+ 数组 ： [ ]
+ 类：class
+ 接口：interface

#### 扩展类型

+ 字符串类型：string（不可变），stringbuffer（可变），stringbuilder（可变）
+ 映射类（map）：HashMap ，LinkedHashMap ，TreeMap 
+ 列表类（list）：ArrayList（数组结构） ，LinkedList（链表结构） 
+ 向量类：Vector（自动增长的对象数组）



## JavaScript

#### 基本类型

+ 整型：Number
+ 字符串：String
+ 布尔型：ture，false
+ 空：Undefined，Null
+ 数组：Array （[ ]）
+ 对象：Object（{}）

+ class （es6）



## python

#### 基本类型

+ 数字类型：**int、float、complex（复数）** 

+ 字符串类型：String

+ 列表：list （类似go的slice）

+ 元组：Tuple（不能修改）

+ 集合: Set （无序不重复元素的序列）

+ 字典（映射）：Dictionary

+ class

#### 扩展类型

+ 集合(collections): chainMap, counter, deque(链表), orderedDict, namedtuple