<h1 style="text-align:center">WebAssembly</h1>

## table of contents

+ [1、什么是wasm](#什么是wasm)
+ [2、wasm有什么用](#wasm有什么用)
+ [3、如何使用wasm](#如何使用wasm)
    + [编译成wasm](#①编译出wasm)
    + [Browser](#②在Browser执行)
    + [Nodejs](#③在Nodejs执行)
+ [4、性能比较](#性能比较)
+ [5、使用其他语言编译](#5、使用其他语言编译)

## 1、什么是wasm

wasm 是一个可移植、体积小、加载快并且兼容 Web 的全新格式（字节码）。

我们学习时通常把未知事物类比于已知事物，可以把它比作`java`，`wasm`是字节码格式，而浏览器为它提供了VM。


## 2、为什么需要wasm

由于前端的`javascript`存在一些问题：

+ 语法太灵活导致开发大型 Web 项目困难；
+ 性能不能满足一些场景的需要。

三大浏览器巨头分别提出了自己的解决方案（ `TypeScript`, `Dart`, `asm.js` ），它们互不兼容，这违背了 Web 的宗旨: 技术的规范统一。所以`wasm`诞生了。

## 3、如何使用wasm
> `wasm`已经在三大浏览器内被支持，由于`nodejs`内部使用的是`v8`, `nodejs` 也对其做了支持。
大部分高级语言都对wasm做了编译支持
+ c/c++ Emscripten(llvm)
+ rust wasm-pack(llvm、wasm-bindgen)
+ go 编译器自带
+ typescript assemblyscript

### ①编译成wasm
```c
// add.c 代码 -> Emscripten -> add.wasm
int add(int x, int y) {
  return x + y;
}
```

### ②在Browser执行
```javascript
fetch('localhost:300/add.wasm')
    .then(response => response.arrayBuffer())
    .then(bytes => WebAssembly.compile(bytes))
    .then(wasmModule => {
        const instance = new WebAssembly.Instance(wasmModule);
        console.log(instance.exports.add(100, 201));
    })
    .catch(err => console.log(err));
```
### ③在Nodejs执行
```javascript
const fs = require('fs');
const bytes = new Uint8Array(fs.readFileSync('./add.wasm'));

WebAssembly.compile(bytes)
    .then(wasmModule => {
        const instance = new WebAssembly.Instance(wasmModule);
        console.log(instance.exports.add(100, 201));
    })
    .catch(err => console.log(err));
```

## 4、性能比较