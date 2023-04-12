# LeetCode-动态规划篇

[toc]

## LeetCode45

[跳跃游戏 II](https://leetcode.cn/problems/jump-game-ii/)

> 动态规划/贪心

```c++
输入: nums = [2,3,1,1,4]
输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
```



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

> 动态规划，定义为以num[i]为结尾的最大子数组和作为寻优目标。

```c++
输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
```



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

> 动态规划，参考跳跃游戏II的做法

```c++
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
```

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

> 动态规划

```c++
输入：m = 3, n = 2
输出：3
解释：
从左上角开始，总共有 3 条路径可以到达右下角。
1. 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右
3. 向下 -> 向右 -> 向下
```



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

> 和62题类似的动态规划

```c++
输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
输出：2
解释：3x3 网格的正中间有一个障碍物。
从左上角到右下角一共有 2 条不同的路径：
1. 向右 -> 向右 -> 向下 -> 向下
2. 向下 -> 向下 -> 向右 -> 向右
```



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

> 动态规划 + 贪心

```c++
输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
输出：7
解释：因为路径 1→3→1→1→1 的总和最小。
```

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

> 动态规划

```c++
输入：n = 3
输出：3
解释：有三种方法可以爬到楼顶。
1. 1 阶 + 1 阶 + 1 阶
2. 1 阶 + 2 阶
3. 2 阶 + 1 阶
```

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

> 动态规划

```c++
输入：s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出：true
```



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

> 数组+动态规划



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

> 数组+动态规划

```c++
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
```



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

> 数组+动态规划



```c++
输入：prices = [7,1,5,3,6,4]
输出：7
解释：在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5 - 1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6 - 3 = 3 。
     总利润为 4 + 3 = 7 。
```



```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        vector<vector<int>> dp(length, vector<int>(2,0));

        dp[0][0] = 0;
        dp[0][1] = -1 * prices[0];

        for (int i = 1; i < length; i++){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }   
		//因为每一个时间刻都有可能是买入和卖出两个动作；
        //所以维护一个数组，然后每个时刻包含两个值，表示买入和卖出的获利值
        return dp[length - 1][0];
    }
};
```





## LeetCode139(待研究)

[单词拆分](https://leetcode.cn/problems/word-break/)

> 动态规划

```c++
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。
```



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

> 首尾相连的情况下，考虑不抢最后一间和不抢第一间来求得最大值

```c++
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
```



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











