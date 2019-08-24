#! /usr/bin/nodejs

const sort = require("./sort")
const RandomLen = 4_0000
const RandomMax = 4_0000

console.log("\033[0;31;1m排序测试，测试长度:%d \033[0m", RandomLen)

/**
 * @returns {number[]}
 * @description 生成随机数组 
 */
function randomArray() {
    const result = new Array(RandomLen)
    for (let i = 0; i < RandomLen; i++) {
        result[i] = parseInt(Math.random() * RandomMax)
    }
    return result;
}

function assetsSorted(nums) {
    return new Promise((resolve, reject) => {
        resolve(assetsSorted.caller.name)
    }).then((callName) => {
        let flag = true;
        for (let i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                flag = false;
                break;
            }
        }
        let msg = flag ? "OK" : "Fail! not sorted"
        console.log("test %s ... %s", callName, msg)
    })

}


function test(fn) {
    const data = randomArray()
    let startTime = new Date()
    fn(data)
    let endTime = new Date()
    console.log("bench %s %s ms", fn.name, endTime - startTime)
}

// 测试生成随机数组
test(function TestRandomArray() {
    randomArray()
})

// 测试冒泡排序
test(function TestBubbleSort(data) {
    assetsSorted(sort.bubbleSort(data))
})

// 测试归并排序
test(function TestMergeSort(data) {
    assetsSorted(sort.mergeSort(data))
})


// 测试堆排序
test(function TestHeapSort(data) {
    assetsSorted(sort.heapSort(data))
})

// 测试快速排序
test(function TestQuickSort(data) {
    assetsSorted(sort.quickSort(data))
})