
/*------------------------------------------------------ */

function main() {
    let array1 = [3, 6, 0, 3, 7, 9, 0, 4, 3];
    let array2 = [3, 8, 1, 3, 7, 9, 0, 4, 3];
    BubbleSort(array1);
    QuickSort(array2, 0, array2.length - 1);
    console.log(array1);
    console.log(array2);
}

main()

/*-------------------------------------------------------- */


/**
 * 冒泡排序
 * @param {array<number>} array 
 * 
 */
function BubbleSort(array) {
    for (let i = 0; i < array.length; i++) {
        for (let j = 0; j < array.length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                let temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

/**
 * 快速排序
 * @param {array<number>} array 
 * @param {number} left
 * @param {number} right
 */
function QuickSort(array, left, right) {
    if (left > right) {
        return
    }
    let base = array[left];
    let i = left;
    let j = right;

    while (i != j) {
        //从右向左扫描是否存在比基数小的数字
        while (array[j] >= base && i < j) {
            j--;
        }
        //从左向右扫描是否存在比基数大的数字
        while (array[i] <= base && i < j) {
            i++;
        }

        if (i < j) {
            //将大于基数的数字放置到右侧
            let temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }

    //更新基数
    array[left] = array[i];
    array[i] = base;

    //递归对左侧进行排序
    QuickSort(array, left, i - 1);
    //递归对右侧进行排序
    QuickSort(array, (i + 1), right);

}