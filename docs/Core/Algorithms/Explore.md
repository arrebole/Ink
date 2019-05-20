# Explore

>算法对问题的具体实现。

## Index

### Brute-Forc

+ [Breadth-first Search]()
  + [岛屿的个数]()
  + [打开转盘锁]()
  + [完全平方数]()
+ [Depth-first Search]()
  + [岛屿的个数]()
  + [目标和]()



## Brute-Forc

### Breadth-first search

#### 1.0 岛屿的个数

>[原题链接](https://leetcode-cn.com/explore/learn/card/queue-stack/217/queue-and-bfs/872/)
>
>架构： 暴力法-广度优先搜索，队列。

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



#### 2.0 打开转盘锁

>[原题链接](https://leetcode-cn.com/explore/learn/card/queue-stack/217/queue-and-bfs/873/)
>
>架构：暴力法-广度优先搜索

```java
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



#### 3.0 完全平方数

```python
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

#### 1.0 岛屿的个数

>[原题链接](https://leetcode-cn.com/explore/learn/card/queue-stack/217/queue-and-bfs/872/)
>
>算法： 暴力法-深度优先搜索，栈。

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





#### 2.0 目标和

>[原题链接](https://leetcode-cn.com/explore/learn/card/queue-stack/219/stack-and-dfs/883/)
>
>算法： 暴力法-深度优先搜索，栈。

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



#### 3.0 克隆图

>[原题链接](https://leetcode-cn.com/explore/learn/card/queue-stack/219/stack-and-dfs/884/)
>
>算法：暴力法-深度优先搜索

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

