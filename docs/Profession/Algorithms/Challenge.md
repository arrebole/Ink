# Explore

>算法对问题的具体实现。



## Brute-Forc

### Spiral Matrix

> [leetcode.54](https://leetcode.com/problems/spiral-matrix/)
>
> 暴力法—穷举查找

```javascript

```



### Two Sum II - Input array is sorted

> [leetcode.167](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)
>
> 暴力法—穷举查找

```javascript
/**
 * @param {number[]} numbers
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function (numbers, target) {
    return new Solution(numbers, target).twoSum()
};

// ideas: 暴力法—穷举查找、双指针
class Solution {
    constructor(nums, target) {
        this.nums = nums;
        this.target = target;
        this.lo = 0;
        this.hi = 0;
    }
    get lastIndex() {
        return this.nums.length - 1;
    }
    get result() {
        return [this.lo + 1, this.hi + 1]
    }
    isEqTarget() {
        let sum = this.nums[this.lo] + this.nums[this.hi];
        return sum == this.target;
    }
    twoSum() {
        while (this.lo < this.nums.length) {
            this.hi = this.lastIndex
            while (this.hi > this.lo) {
                if (this.isEqTarget()) return this.result;
                this.hi--
            }
            this.lo++
        }
    }
}
```



### Rotate Array

> [leetcode.189](https://leetcode.com/problems/rotate-array/)
>
> 暴力法

```javascript
// 数组翻转问题
// ideas: 队列操作
class Solution {
    constructor(nums, k) {
        this.nums = nums;
        this.target = k;
    }
    execult() {
        for (let i = 0; i < this.target; i++) {
            this.nums.unshift(this.nums.pop())
        }
        return this.nums
    }
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function (nums, k) {
    return new Solution(nums, k).execult();
};
```





### Reverse String

> [leetcode.344](https://leetcode.com/problems/reverse-string/)
>
> 暴力法—双指针翻转字符串

```javascript
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
    return new Solution(s).reverseString()
};

// ideas: 暴力法—顺序查找
class Solution {
    constructor(aStringArray) {
        this._aStringArray = aStringArray
    }
    swap(i, j) {
        let temp = this._aStringArray[i];
        this._aStringArray[i] = this._aStringArray[j];
        this._aStringArray[j] = temp
    }
    // 双指针翻转字符串
    reverseString() {
        let lo = 0, hi = this._aStringArray.length - 1;
        while (lo < hi) {
            this.swap(lo++, hi--);
        }
        return this._aStringArray;
    }
}
```



### Plus-One

> [leetcode.66](https://leetcode.com/problems/plus-one/)
>
> 暴力法—顺序查找

```javascript
/**
 * @param {number[]} digits
 */
function plusOne(digits) {
    const solution = new Solution(digits);
    return solution.plusOne()
}

class Solution {
    constructor(digits) {
        this.digits = digits;
        this.len = digits.length;
    }
    carry() {
        for (let i = this.len - 1; i >= 0; i--) {
            if (this.digits[i] <= 9) return this.digits;

            this.digits[i] = 0;
            if (i == 0) this.digits.unshift(1)
            else this.digits[i - 1]++;
        }
        return this.digits;
    }
    plusOne() {
        this.digits[this.len - 1]++;
        return this.carry();
    }
}
```



### clone-graph

> [leetcode.133](https://leetcode.com/problems/clone-graph/)
>
> 暴力法-深度优先搜索

```c++
class Solution {
 public:
  Node* cloneGraph(Node* node) { return this->clone(node); }

 private:
  unordered_map<int, Node*> seen;
  Node* clone(Node* node) {
    if (node == nullptr) return node;
    if (seen.count(node->val)) return seen[node->val];

    Node* newNode = createNode(node);
    int size = node->neighbors.size();
    for (int i = 0; i < size; i++) {
      newNode->neighbors.push_back(clone(node->neighbors[i]));
    }
    return newNode;
  }
  Node* createNode(Node* node) {
    Node* newNode = new Node();
    newNode->val = node->val;
    seen[node->val] = newNode;
    return newNode;
  }
};
```



### Number of Islands

> [leetcode.200](https://leetcode.com/problems/number-of-islands/)
>
> 暴力法-深度优先搜索，栈。

```javascript
/**
 * @param {character[][]} grid
 * @return {number}
 */
function numIslands(grid) {
    const MAX_ROW = grid.length
    if (MAX_ROW <= 0) return 0;
    const MAX_COL = grid[0].length;
    const ISLAND = "1"
    let count = 0;

    for (let i = 0; i < MAX_ROW; i++) {
        for (let j = 0; j < MAX_COL; j++) {
            if (grid[i][j] == ISLAND) {
                dfsTravelIsLands(grid, [i, j])
                count++;
            }
        }
    }
    return count;
};

/**
 * @param {character[][]} grid
 * @param {number[]} entrance
 */
function dfsTravelIsLands(grid, entrance) {
    const SEA = "0";
    let [i, j] = entrance;
    if (i >= 0 && i < grid.length && j >= 0 && j < grid[0].length && grid[i][j] == "1") {
        grid[i][j] = SEA;
        dfsTravelIsLands(grid, [i + 1, j]);
        dfsTravelIsLands(grid, [i - 1, j]);
        dfsTravelIsLands(grid, [i, j + 1]);
        dfsTravelIsLands(grid, [i, j - 1]);
    }
    return;
}
```



### DiagonalTraverse

> [leetcode.498](https://leetcode.com/problems/diagonal-traverse/)
>
> 暴力法—顺序查找

```

```



### Find-pivot-index

> [leetcode.724](https://leetcode.com/problems/find-pivot-index/)
>
> 暴力法—顺序查找

```javascript
/**
 * @param {number[]} nums
 */
function pivotIndex(nums) {
    for (let i = 0; i < nums.length; i++) {
        const LeftSum = arraySum(nums, 0, i - 1);
        const RightSum = arraySum(nums, i + 1, nums.length - 1)
        if (LeftSum == RightSum) {
            return i;
        }
    }
    return -1;
};

function arraySum(aArray, start, end) {
    let result = 0;
    while (start <= end) {
        result += aArray[start++];
    }
    return result;
}
```



### Largest Number At Least Twice of Others

> [leetcode.747](https://leetcode.com/problems/largest-number-at-least-twice-of-others/)
>
> ideas：暴力法-顺序查找、(变治法-预排序)

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
function dominantIndex(nums) {
    if(nums.length < 2){
        return nums.length -1;
    }
    const solution = new Solution(nums)
    return solution.solve()
};

class Solution {
    constructor(nums) {
        this.nums = nums;
        this.maxIndex = 0;
        this.maxValue = nums[0];
    }
    findMaxValue() {
        this.nums.forEach((value, index) => {
            if (value > this.maxValue) {
                this.maxIndex = index;
                this.maxValue = this.nums[index];
            }
        });
    }
    maxIsTwoPow() {
        let result = this.maxIndex;
        this.nums.forEach((v, i) => {
            if (v * 2 > this.maxValue && i != this.maxIndex) {
                result = -1
            }
        })
        return result
    }
    solve() {
        this.findMaxValue()
        return this.maxIsTwoPow()
    }
}
```



### open-the-lock

>[leetcode.752](https://leetcode.com/problems/open-the-lock/)
>
>暴力法-广度优先搜索

```java
// java 
class Solution {
    private Set<String> seen;
    private Queue<String> queue;
    private int count;

    public Solution() {
        queue = new LinkedList<>();
        seen = new HashSet<String>();
        count = 0;
    }

    public boolean isUnableStart(String[] deadends, String target) {
        for (String i : deadends) {
            seen.add(i);
        }
        if (seen.contains(target) || seen.contains("0000")) {
            return false;
        }
        return true;
    }

    public int openLock(String[] deadends, String target) {
        if (!isUnableStart(deadends, target)) {
            return -1;
        }
        queue.offer("0000");
        seen.add("0000");

        while (!queue.isEmpty()) {
            int sizeQueue = queue.size();
            for (int i = 0; i < sizeQueue; i++) {
                String roulette = queue.poll();
                if (target.equals(roulette)) {
                    return count;
                }
                for (int j = 0; j < 4; j++) {
                    String up = neighbor(roulette, j, 1);
                    String down = neighbor(roulette, j, -1);
                    System.out.println(up);
                    System.out.println(down);
                    if (seen.add(up)) {
                        queue.offer(up);
                    }
                    if (seen.add(down)) {
                        queue.offer(down);
                    }
                }
            }
            count++;
        }
        return -1;
    }

    private String neighbor(String roulette, int i, int flage) {
        final int UP = 1;
        char[] cs = roulette.toCharArray();
        // 向大搜索
        if (flage == UP) {
            if (cs[i] == '9') {
                cs[i] = '0';
            } else {
                cs[i]++;
            }
        } else {
            // 向小搜索
            if (cs[i] == '0') {
                cs[i] = '9';
            } else {
                cs[i]--;
            }
        }
        return new String(cs);
    }
}

```



### perfect-squares

> [leetcode.279](https://leetcode.com/problems/perfect-squares/)
>
> 暴力法-广度优先搜索

```python
# /usr/bin/python
class Solution:
    def numSquares(self, n: int) -> int:
        bfsQueue: set = {n}
        basicList: list = list()
        count: int = 0

        for i in range(1, int(math.sqrt(n))+1):
            sum: int = i**2
            basicList.append(sum)
        while bfsQueue:
            count += 1
            newQueue: set = set()
            for i in bfsQueue:
                for j in basicList:
                    if i == j:
                        return count
                    if i-j >= 0:
                        newQueue.add(i-j)
            bfsQueue = newQueue
        return count
```





### target-sum

> [leetcode.494](https://leetcode.com/problems/target-sum/)
>
> 暴力法-深度优先搜索，栈。

```java
class Solution {
    private int[] nums;
    private int target;
    private int waysCount;

    public int findTargetSumWays(int[] nums, int target) {
        this.nums = nums;
        this.target = target;
        this.waysCount = 0;
        dfsFindWays(0, 0);
        return this.waysCount;
    }
    private void dfsFindWays(int sum, int level) {
        if (level >= nums.length) {
            if (sum == target) {
                waysCount++;
            }
            return;
        }
        dfsFindWays(sum + nums[level], level + 1);
        dfsFindWays(sum - nums[level], level + 1);
    }
}
```



### keysAndRooms

> 题目链接 [leetcode.841](https://leetcode.com/problems/keys-and-rooms/)
>
> dfs、stack

```javascript
/** 
 * @param {number[][]} rooms 
 */
function canVisitAllRooms(rooms) {
    let q = new KeysAndRooms(rooms);
    return q.resolve();
};

class KeysAndRooms {
    constructor(rooms) {
        this.Rooms = rooms
        this.Seen = new Array(rooms.length);
        this.Seen.fill(false,0,rooms.length)
    }

    Room = null
    Seen = null
    Stack = new Array();

    resolve(){
        this.mark(0)
        this.dsf()
        return this.isEnterEvery()
    }
    mark(index) {
        this.Stack.push(this.Rooms[index])
        this.Seen[index] = true;
    }
    dsf() {
        while (this.Stack.length > 0) {
            let list = this.Stack.pop()
            if (list.length == 0) {
                continue;
            }
            for (const iterator of list) {
                if (!this.Seen[iterator]) {
                    this.mark(iterator)
                }
            }
        }
    }
    isEnterEvery() {
        for (const i of this.Seen) {
            if(!i) return false;
        }
        return true;
    }
}
```



## Reduce-Conquer

### remove-element

> [leetcode.27](https://leetcode.com/problems/remove-element/)
>
> ideas: 减治法-减常因子，插入排序

```javascript
class Solution {
    constructor(nums, val) {
        this.nums = nums;
        this.val = val;
    }
    get count() {
        let result = this.nums.length;
        this.nums.forEach(e => {
            if (e == this.val) result--;
        });
        return result;
    }
    // ideas: 减治法—减常因子，插入排序
    removeVal() {
        let len = nums.length;
        for (let i = 0; i < len; i++) {
            if (this.nums[i] != this.val) continue;
            for (let j = i; j < len - 1; j++) {
                this.nums[j] = this.nums[j + 1]
            }
            i--;
            len--;
        }
    }
    execult() {
        let result = this.count;
        this.removeVal();
        return result;
    }
}

/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
    return new Solution(nums, val).execult()
};
```



### Move Zeroes

> [leetcode.283](https://leetcode.com/problems/move-zeroes/)
>
> ideas: 减治法-减常因子，插入排序

```javascript
class Solution {
    constructor(nums) {
        this.nums = nums;
        this.count = 0
    }
    execlut(nums) {
        for (let i = 0; i < this.nums.length - this.count; i++) {
            if (this.nums[i] != 0) continue;
            else {
                this.insertion(i);
                i--;
            }
        }
    };
    insertion(i) {
        let j = i
        while (j < this.nums.length - 1) {
            this.nums[j] = this.nums[++j]
        }
        this.nums[this.nums.length - 1] = 0;
        this.count++;
    }
}

/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function (nums) {
    new Solution(nums).execlut()
};
```

