
// js存在两个event loop
// 微任务和宏任务（微任务优先级高，微任务空时才执行宏任务）

console.log('1');

// 移动到异步api， 0秒后在宏任务队列追加执行的函数
setTimeout(() => {
    console.log("setTimeout");
}, 0)

// 将函数插到微任务队列前处
process.nextTick(() => {
    console.log("nextTick1");
})

// 将函数插到微任务队列前处
process.nextTick(() => {
    console.log("nextTick2");
})

// 宏任务队列追加执行的函数
setImmediate(() => {
    console.log("setImmediate");
})


new Promise((resolve) => {
    console.log("promise");
    resolve();
}).then(() => { // 在微任务队列push then函数
    console.log("then");
})

async function asyncPrint() {
    console.log("async");
    await console.log("await...");
    console.log("next await ...")
}

asyncPrint()