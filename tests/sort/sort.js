/**
 *  排序测试，测试长度:40000,数据范围[0-4_0000]
 *  BubbleSort: 2767.657ms
 *  MergeSort: 19.027ms
 *  HeapSort: 13.693ms
 *  QuickSort: 12.761ms
*/


class Bubble {
  constructor(nums) {
    this.nums = nums;
  }
  swap(a, b) {
    const t = this.nums[a];
    this.nums[a] = this.nums[b];
    this.nums[b] = t;
  }
  sort() {
    for (let i = 0; i < this.nums.length; i++) {
      for (let j = 0; j < this.nums.length - i - 1; j++) {
        if (this.nums[j] > this.nums[j + 1]) this.swap(j, j + 1);
      }
    }
    return this.nums;
  }
}

// 三向切分的快速排序
class Quick {
  constructor(nums) {
    this.nums = nums;
  }
  exch(a, b) {
    const t = this.nums[a];
    this.nums[a] = this.nums[b];
    this.nums[b] = t;
  }
  
  partition(lo, hi) {
    if (lo >= hi) return;
    // 双指针：lt 和 i
    let lt = lo, i = lo + 1, gt = hi;
    const v = this.nums[lo];

    while (i <= gt) {
      const cmp = this.nums[i] - v;
      if (cmp < 0) this.exch(lt++, i++);
      else if (cmp > 0) this.exch(i, gt--);
      else i++;
    }
    // a[lo..lt-1] < v = a[lt..gt] < a[gt+1..hi]
    this.partition(lo, lt - 1);
    this.partition(gt + 1, hi);
  }
  sort() {
    this.partition(0, this.nums.length - 1)
    return this.nums;
  }
}

// 自底而上的归并排序
class Merge {
  constructor(nums) {
    this.nums = nums;
    this.aux = new Array(nums.length);
  }
  copyToAux(lo, hi) {
    for (let k = lo; k <= hi; k++) {
      this.aux[k] = this.nums[k];
    }
  }
  merge(lo, mid, hi) {
    let i = lo, j = mid + 1;
    // 将[lo,hi]拷贝到 aux数组
    this.copyToAux(lo, hi);
    // 归并
    for (let k = lo; k <= hi; k++) {
      if (i > mid) this.nums[k] = this.aux[j++];
      else if (j > hi) this.nums[k] = this.aux[i++];
      else if (this.aux[i] > this.aux[j]) this.nums[k] = this.aux[j++];
      else this.nums[k] = this.aux[i++];
    }
  }
  // 经测试 120_0000 数据，自上而下归并 690 ms， 自下而上归并 18.3 ms, 38倍
  sort() {
    //  sz 子数组大小,  lo 子数组索引
    for (let sz = 1; sz < this.nums.length; sz = sz + sz) {
      for (let lo = 0; lo < this.nums.length - sz; lo += sz + sz) {
        this.merge(lo, lo + sz - 1, Math.min(lo + sz + sz - 1, this.nums.length - 1));
      }
    }
    return this.nums;
  }
}

class Heap {
  constructor(nums) {
    this.nums = nums;
  }
  less(a, b) {
    return this.nums[a] < this.nums[b]
  }
  exch(a, b) {
    const t = this.nums[a];
    this.nums[a] = this.nums[b];
    this.nums[b] = t;
  }
  sink(root, heapSize) {
    while (2*root+1 < heapSize) {
      let node =  2 * root + 1
      if(node+1 < heapSize && this.less(node, node+1)) node++;
      if (!this.less(root, node)) break;
      this.exch(root, node)
      root = node;
    }
  }
  buildHeap(){
    const lastNode = this.nums.length- 1;
    const lastParent = parseInt((lastNode-1)/2);
    for (let k = lastParent; k >= 0; k--) {
      this.sink(k, this.nums.length);
    }
  }
  sort() {
    this.buildHeap();
    let n = this.nums.length -1;
    for(let i = n; i>0 ;i--){
      this.exch(0, i);
      this.sink(0, i);
    }
    return this.nums;
  }
}

module.exports.bubbleSort = function (nums) {
  return new Bubble(nums).sort();
};

module.exports.quickSort = function (nums) {
  return new Quick(nums).sort();
};

module.exports.mergeSort = function (nums) {
  return new Merge(nums).sort();
};

module.exports.heapSort = function (nums) {
  return new Heap(nums).sort();
};
