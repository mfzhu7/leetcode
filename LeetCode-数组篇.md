# LeetCode-数组篇



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

