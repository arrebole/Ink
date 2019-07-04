# Explore

>算法对问题的具体实现。





## Table of Contents

**Brute-Forc**

+ Sequential Search
  + [find-pivot-index](#find-pivot-index)

+ Breadth-first Search
  + [number-of-islands](#number-of-islands)
  + [open-the-lock](#open-the-lock)
  + [perfect-squares](#perfect-squares)
+ Deepth-first Search
  + [number-of-islands](#number-of-islands)
  + [target-sum](#target-sum)
  + [clone-graph](#clone-graph)
  + [keysAndRooms](#keysAndRooms)



## Brute-Forc

### Sequential Search

#### find-pivot-index

> [724. 题目链接](https://leetcode.com/problems/find-pivot-index/)
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

#### Largest Number At Least Twice of Others

> [题目链接](https://leetcode.com/problems/largest-number-at-least-twice-of-others/)
>
> 暴力法-顺序查找

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







### Breadth-first search

#### number-of-islands

>[200.题目链接](https://leetcode.com/problems/number-of-islands/)
>
>暴力法-广度优先搜索，队列。

```javascript
/**
 * @param {String[][]} grid
 * @return {Number}
 */
function numIslands(grid) {
    if (grid.length <= 0) {
        return 0;
    }
    const LAND = "1";
    const MAX_COL = grid[0].length;
    const MAX_ROW = grid.length;

    let lands = 0;
    for (let row = 0; row < MAX_ROW; row++) {
        for (let col = 0; col < MAX_COL; col++) {
            if (grid[row][col] == LAND) {
                bfsTravelIsLands(grid, [row, col]);
                lands++;
            }
        }
    }
    return lands;
};


/**
 * @param {String[][]} grid 地图
 * @param {landPoint} entrance 入口坐标
 * @description 广度优先搜索将 "1"一块搜索完并标记为"0"
 */
function bfsTravelIsLands(grid, entrance) {
    const MAX_COL = grid[0].length;
    const MAX_ROW = grid.length;

    let queue = [];
    let row = 0, col = 0, coordinate = null;

    const visit = (r, c) => {
        grid[r][c] = '0';
    }

    const pushToQueue = (r, c) => {
        queue.push([r, c]);
    }

    queue.push(entrance);
    while (queue.length > 0) {
        // 取出队列第一个
        coordinate = queue.shift();
        col = coordinate[1];
        row = coordinate[0];

        // 标记已访问
        visit(row, col);

        // 遍历周围
        // 向右搜索
        if (col + 1 < MAX_COL && grid[row][col + 1] == "1") {
            visit(row, col + 1);
            pushToQueue(row, col + 1);
        }
        // 向左搜索
        if (col - 1 >= 0 && grid[row][col - 1] == "1") {
            visit(row, col - 1);
            pushToQueue(row, col - 1);
        }
        // 向上搜索
        if (row - 1 >= 0 && grid[row - 1][col] == "1") {
            visit(row - 1, col);
            pushToQueue(row -1, col);
        }
        // 向下搜索
        if (row + 1 < MAX_ROW && grid[row + 1][col] == "1") {
            visit(row + 1, col);
            pushToQueue(row + 1, col);
        }
    }
}
```



```javascript
function main() {
    let m = [
        ["1", "1", "1", "1", "1", "0", "1"],
        ["0", "1", "1", "1", "1", "1", "1"],
        ["1", "0", "1", "1", "1", "0", "0"],
        ["1", "0", "1", "1", "0", "1", "1"],
        ["1", "0", "0", "1", "1", "1", "1"],
    ];
     console.log(numIslands(m))
}
```



#### open-the-lock

>[752.题目链接](https://leetcode.com/problems/open-the-lock/)
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

```java
    public static void main(String[] args) {
        String[] deadends = { "0201", "0101", "0102", "1212", "2002" };
        String target = "0202";
        int ret = new Solution().openLock(deadends, target);
        System.out.print(ret);
    }
```



#### perfect-squares

> [279.题目链接](https://leetcode.com/problems/perfect-squares/)
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





### Deepth-first Search

#### Number of Islands

>[200.原题链接](https://leetcode.com/problems/number-of-islands/)
>
>暴力法-深度优先搜索，栈。

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



#### target-sum

>[494.原题链接](https://leetcode.com/problems/target-sum/)
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



#### clone-graph

>[133.原题链接](https://leetcode.com/problems/clone-graph/)
>
>暴力法-深度优先搜索

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



#### keysAndRooms

> [841.题目链接](https://leetcode.com/problems/keys-and-rooms/)
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

