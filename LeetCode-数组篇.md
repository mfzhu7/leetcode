# LeetCode-数组篇

[toc]



## LeetCode118

[ 杨辉三角](https://leetcode.cn/problems/pascals-triangle/)

> ```c++
> 输入: numRows = 5
> 输出: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
> ```



```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        for (int i = 0; i < numRows; ++i){
            res[i].resize(i + 1);
            res[i][0] = res[i][i] = 1;
            for (int j = 1; j < i; ++j){
                res[i][j] = res[i - 1][j - 1] + res[i - 1][j]; 
            }
        }
        return res;

    }
};
```





## LeetCode119

[杨辉三角 II](https://leetcode.cn/problems/pascals-triangle-ii/)

```c++
输入: rowIndex = 3
输出: [1,3,3,1]
```



```c++
class Solution {
public:
    void helper(int nums, vector<int>& lastRow){
        if (nums == 1) return;
        for (int i = 0; i < lastRow.size() - 1; i++){
            lastRow[i] = lastRow[i] + lastRow[i + 1];
        }
        lastRow.emplace(lastRow.begin(), 1);
        helper(nums - 1, lastRow);
        return;

    }
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0){
            vector<int> res = {1};
            return res;
        }
        if (rowIndex == 1){
            vector<int> res = {1,1};
            return res;
        }
        vector<int> res = {1,1};
        helper(rowIndex, res);
        return res;
    }
};
```



## LeetCode128(待研究)

[最长连续序列](https://leetcode.cn/problems/longest-consecutive-sequence/)

> 

```c++
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
```



```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++){
            int curr = nums[i] + 1;
            while(true){
                bool flag = false;
                for (int j = 0;j < nums.size();j++){          
                    if (nums[j] == curr){
                        flag = true;
                        break;
                    }
                }
                curr = curr + 1;
                if (!flag) break;
            }
            
            ret = max(ret, curr - nums[i] - 1);
        }
        return ret;

    }
};
```



## Leetcode134(待研究)



[加油站](https://leetcode.cn/problems/gas-station/)

> 数组+贪心算法

```c++
输入: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
输出: 3
解释:
从 3 号加油站(索引为 3 处)出发，可获得 4 升汽油。此时油箱有 = 0 + 4 = 4 升汽油
开往 4 号加油站，此时油箱有 4 - 1 + 5 = 8 升汽油
开往 0 号加油站，此时油箱有 8 - 2 + 1 = 7 升汽油
开往 1 号加油站，此时油箱有 7 - 3 + 2 = 6 升汽油
开往 2 号加油站，此时油箱有 6 - 4 + 3 = 5 升汽油
开往 3 号加油站，你需要消耗 5 升汽油，正好足够你返回到 3 号加油站。
因此，3 可为起始索引。
```



```c++
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int idx = 0;

        while(idx < n){
            int sumGas = 0;
            int sumCost = 0;
            int cnt = 0;
            while(cnt < n){
                int j = (idx + cnt) % n;
                sumCost += cost[j];
                sumGas += gas[j];
                if (sumCost > sumGas) break;
                cnt = cnt + 1;
            }
            if (cnt == n) return idx;
            else {
                idx = idx + cnt + 1;
            }
        }
        return -1;
        
    }
};
```

