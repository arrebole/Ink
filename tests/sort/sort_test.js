#! /usr/bin/nodejs

const sort = require("./sort")
const RandomLen = 3_0000
const RandomMax = 3_0000

console.log("\033[0;31;1m排序测试，测试长度:%d \033[0m",RandomLen)

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

/**
 * 
 * @param {number[]} nums
 * @description 检验数组是否有序 
 */
function assets(nums,msg) {
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] > nums[i + 1]) {
            console.log("\033[0;35;1m=>%s test fail!!! index = %d \033[0m", msg, i)
            return false
        }
    }
    return true;
}

// 测试生成随机数组
function TestRandomArray() {
    const lable = "@RandomArray"
    console.time(lable)
    const testData = randomArray()
    console.timeEnd(lable)
}
TestRandomArray()

// 测试冒泡排序
function TestBubbleSort() {
    const lable = "BubbleSort"
    const testData = randomArray()

    console.time(lable)
    sort.bubbleSort(testData)
    console.timeEnd(lable)
    
    assets(testData, lable)
}
TestBubbleSort()



// 测试归并排序
function TestMergeSort(){
    const lable = "MergeSort";
    const testData = randomArray()

    console.time(lable)
    sort.mergeSort(testData)
    console.timeEnd(lable)
    
    assets(testData,lable)
}
TestMergeSort()


// 测试堆排序
function TestHeapSort(){
    const lable = "HeapSort"
    const testData = randomArray()

    console.time(lable)
    sort.heapSort(testData)
    console.timeEnd(lable)

    assets(testData, lable)
}
TestHeapSort()

// 测试快速排序
function TestQuickSort(){
    const lable = "QuickSort"
    const testData = randomArray()

    console.time(lable)
    sort.quickSort(testData)
    console.timeEnd(lable)
    assets(testData, lable)
}
TestQuickSort()