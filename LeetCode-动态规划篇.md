# LeetCode-动态规划篇

[toc]

## LeetCode45

[跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)











**题干**

给定一个长度为 `n` 的 **0 索引**整数数组 `nums`。初始位置为 `nums[0]`。

每个元素 `nums[i]` 表示从索引 `i` 向前跳转的最大长度。换句话说，如果你在 `nums[i]` 处，你可以跳转到任意 `nums[i + j]` 处:

- `0 <= j <= nums[i]` 
- `i + j < n`

返回到达 `nums[n - 1]` 的最小跳跃次数。生成的测试用例可以到达 `nums[n - 1]`。

**样例**

```c++
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```

**解题思路**

- 核心的思路是贪心算法，我们在上次跳跃可达的位置中，选择可以跳跃的最远的位置，作为下一次跳跃的起点。
- 从反向角度来看，就是为了达到终点，在跳跃到终点的所有选项中选择最靠近起点的位置。

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxpos = 0;
        int end = 0;
        int step = 0;
        for (int i = 0; i < n - 1; i++){
            if (i <= maxpos){
                maxpos = max(maxpos, i + nums[i]);
            }
            if (i == end){
                end = maxpos;
                step = step + 1;
            }
        }
        return step;
        //维护一个当前能够到达的最远边界
        //如果遍历已经到达边界，更新边界值
    }
};
```





## LeetCode53

[最大子数组和](https://leetcode.cn/problems/maximum-subarray/)

**题干**

给你一个整数数组 `nums` ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

**子数组** 是数组中的一个连续部分。

**样例**

```c++
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```

**解题思路**

- 构造一个dp数组，其中dp[i]表示以nums[i]为结尾的具有最大和的连续子数组
- 这样在遍历每个位置时，只需要判断当前值和当前值+上一个位置为结尾的最大和之间的最大即可

```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int ret = nums[0]; 
        for (int i = 1; i < nums.size(); i++){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]); //必须取num[i]
            //只有2种情况，一种前面大于0，一种前面小于0 
            ret = max(ret, dp[i]);
        }
        return ret;
    }
};
```





## LeetCode55

[跳跃游戏](https://leetcode.cn/problems/jump-game/)

**题干**

给定一个非负整数数组 `nums` ，你最初位于数组的 **第一个下标** 。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个下标。

**样例**

```c++
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
```
**解题思路**

- 和跳跃游戏II相同的思路，使用贪心的算法即可


```c++
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int rightmost = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i <= rightmost){
                rightmost = max(rightmost, i + nums[i]);
            }
            if (rightmost >= nums.size() - 1) return true;
        }
        return false;

    }
};
```





## LeetCode62 

[不同路径](https://leetcode.cn/problems/unique-paths/)

**题干**

一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。

问总共有多少条不同的路径？

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

**样例**

```c++
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
```

**解题思路**

- 动态规划，首先开辟数组和原始数组一样大小，并且设置第一列和第一行均为1，表示到达该位置的路径数为1
- 而后，dp(i,j) = dp(i-1,j) + dp(i, j- 1)，一直计算到右下角即可

```c++
class Solution {
public:
    int uniquePaths(int m, int n) {
        int matrix[m][n];
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                matrix[i][j] = 1;
            }
        } // 这步其实只要把第一行和第一列的数据设置为1，方便后面的计算
        
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                matrix[i][j] = matrix[i-1][j] + matrix[i][j-1];
                //动态规划，即到达当前点的路径数量 = 到达当前点的上方的路径数量 + 到达当前点左侧的路径的数量
            }
        }
        return matrix[m-1][n-1];
    }
```

## LeetCode63 

[不同路径 II](https://leetcode.cn/problems/unique-paths-ii/)

**题干** 

一个机器人位于一个 `m x n` 网格的左上角 （起始点在下图中标记为 “Start” ）。

机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish”）。

现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？

网格中的障碍物和空位置分别用 `1` 和 `0` 来表示。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)



**样例**

```c++
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```

**解题思路**

- 和62的题目类似，唯一需要判断的就是当前位置是否是障碍物
- 障碍物的情况下设置为0即可；(i+j)=0为判断初始点的一个技巧

```c++
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        int col = obstacleGrid[0].size();

        vector<vector<int>> matrix(row, vector<int>(col, 0));
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(obstacleGrid[i][j] == 1){ matrix[i][j] = 0; continue; }
                // 判断是不是被堵住了
                if(i + j == 0) {matrix[0][0] = 1; continue;}
                //设定初始值
                int left = (i - 1 >= 0 ? matrix[i - 1][j] : 0);
                int up = (j - 1 >= 0 ? matrix[i][j - 1] : 0);
                //计算左侧和上方的路径数，记得判断边界值
                matrix[i][j] = left + up;
            }
        }
        return matrix[row - 1][col - 1];
    }
};
```



## LeetCode64

[最小路径和](https://leetcode.cn/problems/minimum-path-sum/)

**题干**

给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

![img](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)

**示例**

```c++
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
```

**解题思路**

- 和路径的计数题目类似，首先，计算出第一行和第一列到达对应位置之和

- 而后遍历矩阵中的剩余位置，取左侧和上方的最小值作为其路径
- 则最后右下角的位置即为总和最小的


```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i = 1; i < grid.size(); i++){
            grid[i][0] = grid[i][0] + grid[i - 1][0];
        }
        for(int j = 1; j < grid[0].size(); j++){
            grid[0][j] = grid[0][j] + grid[0][j - 1];
        } // 上述分别计算了第一行和第一列的最小值，第一行和第一列只存在一个路径
        for (int i = 1; i < grid.size(); i++){
            for(int j = 1; j < grid[0].size(); j++){
                grid[i][j] = min(grid[i-1][j], grid[i][j - 1]) + grid[i][j];
            }
        } //贪心，到达当前点的方法只有从上方和左侧，计算其最小值即可
        int row = grid.size() - 1;
        int col = grid[0].size() - 1;
        return grid[row][col];
    }
};
```



## LeetCode70 

[爬楼梯](https://leetcode.cn/problems/climbing-stairs/)

**题干**

假设你正在爬楼梯。需要 `n` 阶你才能到达楼顶。

每次你可以爬 `1` 或 `2` 个台阶。你有多少种不同的方法可以爬到楼顶呢？

**示例**

```c++
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
```
**解题思路**

- 斐波那契数列
- 到达第n阶的方式，(1)可能是从n-1阶爬一个台阶 (2) 可能是从n-2阶爬两个台阶

```c++
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int a_1 = 1;
        int a_2 = 2;
        int res = 0;
        while(n - 3 >= 0){
            res = a_1 + a_2;
            a_1 = a_2;
            a_2 = res;
            n = n - 1;
        }
        return res;
    }
};
```

##  LeetCode97

[交错字符串](https://leetcode.cn/problems/interleaving-string/)

**题干**

给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ... 或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。

 

示例 1：

![img](https://assets.leetcode.com/uploads/2020/09/02/interleave.jpg)

**示例**

```c++
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
```

**解题思路**

- 我们定义dp(i,j)表示是否能够用s1(i)个元素和s2(j)个元素来构成s3(i+j)个元素
- 当s1(i) == s3(i + j)时，则dp(i, j) = dp(i - 1, j)
- 当s2(j) == s3(i + j)时，则dp(i, j) = dp(i , j - 1)
- 核心在于动态规划状态转移方程的表达

```c++
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        if (m + n != s3.size()) return false;

        int a = m + 1;
        int b = n + 1;

        vector<vector<int>> dp(a, vector<int>(b, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++){
            for (int j = 0; j <= n; j++){
                int p = i + j - 1;
                if (i > 0){
                    dp[i][j] |= (dp[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0){
                    dp[i][j] |= (dp[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return dp[m][n];

    }
};
```



## LeetCode120

[三角形最小路径和](https://leetcode.cn/problems/triangle/)

**题干**

给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

**示例**

```c++
输入：triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
输出：11
解释：如下面简图所示：
   2
  3 4
 6 5 7
4 1 8 3
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
```

**解题思路**

- 经典的dp题目。我们自顶向下开始遍历，存储下达到当前节点的最小路径和即可
- dp(i, j) = min(dp(i - 1,j)，dp(i - 1, j  + 1)) + array(i, j)
- 最后从最后一行里面选取出路径最小和即可

```c++
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int num = triangle.size();
        vector<int> row(num, 0);
        vector<vector<int>> dp(num, row);
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < num; i++){
            for (int j = 0; j <= i; j++){
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }
                else if (j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }
                else {
                    dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
                }
            } //每一层保存当前点的最小路径和，则最后一层中的最小值就是目标值
        }
        int ret = INT_MAX;
        for (auto i: dp[num-1]){
            ret = min(ret, i);
        }
        return ret;
    }
};
```



## LeetCode121



[买卖股票的最佳时机](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/)

**题干**

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

**示例**

```c++
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```

**解题思路**

- 核心思路是维护一个到目前为止的价格的最小值，而后遍历数组，更新最小值，和用当前位置的股票价格和最小值之差所得到的最大获利

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;
        int max_profit = 0;
        for (int i = 0; i <= prices.size() - 1; i++){
            max_profit = ((prices[i] - min_price) > max_profit) ? (prices[i] - min_price): max_profit;
            min_price = prices[i] > min_price ?  min_price : prices[i];
            //维护一个到当前为止的最小值，遍历数组的过程来得到每个位置上的最大获利值
        }
        return max_profit;
    }
};
```





## LeetCode122(贪心算法待实现)

[ 买卖股票的最佳时机 II](https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/)

**题干**

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。

返回 你能获得的 最大 利润 。

**示例**

```c++
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。
```

**解题思路**

- 核心是维护一个两种选择的数组，i时刻极可能买入也可以卖出
- 同时需要考虑上一个时刻的情况，因为手上最多只有一手股票
- 注意初始值的设置

```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        vector<vector<int>> dp(length, vector<int>(2,0));

        dp[0][0] = 0;
        dp[0][1] = -1 * prices[0];

        for (int i = 1; i < length; i++){
            //0表示卖出，1表示买入
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]); //i时刻卖出股票，则i-1时刻是买入股票/i-1时刻已经卖出股票
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]); // i时刻买入股票，则i-1时刻是卖出股票/i-1时刻已经买入股票
        }   
		//因为每一个时间刻都有可能是买入和卖出两个动作；
        //所以维护一个数组，然后每个时刻包含两个值，表示买入和卖出的获利值
        return dp[length - 1][0];
    }
};
```





## LeetCode139(待研究)

[单词拆分](https://leetcode.cn/problems/word-break/)

**题干**

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

**示例**

```c++
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。
```

**解题思路**

- 我们定义dp(i)表示字符串的前i个字符能否由字典所构成
- 那么计算dp(i)的时候，需要判断0到i-1位置的所有拆分点是否能够由字典构成
- 计算拆分点的时候，假设位置为j，dp(j)为false，则说明无法构成
- dp(j)为true的情况下，只需要判断s(j, i-j)是否在字典中即可

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>wordDictSet(wordDict.begin(), wordDict.end());

        auto dp = vector <bool> (s.size() + 1);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] && wordDictSet.find(s.substr(j, i - j)) != wordDictSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};


```



## Leetcode213

[ 打家劫舍 II](https://leetcode.cn/problems/house-robber-ii/)

**题干**

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。

**示例**

```c++
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
```

**解题思路**

- 首尾相连的情况下，我们只需要考虑[0, n-2]和[1, n-1]的情况即可

```c++
class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        int first = nums[start];
        int second = max(nums[start], nums[start + 1]);

        for (int i = start + 2;i <= end; i++){
            int  temp = max(first + nums[i], second);
            first = second;
            second = temp;
        }
        return second;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        return max(helper(nums, 0, nums.size() - 2), helper(nums, 1, nums.size() -1));

    }
};
```



## LeetCode221

[最大正方形](https://leetcode.cn/problems/maximal-square/)

**题干**

在一个由 `'0'` 和 `'1'` 组成的二维矩阵内，找到只包含 `'1'` 的最大正方形，并返回其面积。

 

**示例 1：**

![img](https://assets.leetcode.com/uploads/2020/11/26/max1grid.jpg)



```c++
输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
输出：4
```

**解题思路**

- 构建矩阵dp(i, j)，表示以(i,j)为右下角的矩阵的最大正方形边长
- 如果当前位置(i,j)的原始数据为0，那么当前位置无法被包含，即为0 
- 如果当前值为1，判断是否为边界，边界为1
- 不为边界的情况下，最大边长为其相邻的3个位置中最小的值加1




```c++
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (rows == 0 || cols == 0) return 0;
        int maxSide = 0;

        vector<vector<int>>dp(rows, vector<int>(cols, 0));

        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols;j++){
                if (matrix[i][j] == '1'){
                    if (i == 0 || j == 0){
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
                    }
                }
                maxSide = max(maxSide, dp[i][j]);

            }
        }
        return maxSide * maxSide;

    }
};
```





